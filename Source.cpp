#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;
void Create(int* r, const int size, const int Low, const int High, int i)
{
	r[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(r, size, Low, High, i + 1);
}
void Print(int* r, const int size, int i)
{
	cout << setw(4) << r[i];
	if (i < size - 1)
		Print(r, size, i + 1);
	else
		cout << endl;
}
int Number(int* r, const int size, int count, int i)
{
	if (r[i] % 6 == 0 || i % 5 != 0)
		count++;
	if (i < size - 1)
		Number(r, size, count, i + 1);
	else
		return count;
}
int Sum(int* r, const int size, int i)
{
	if (i < size)
	{
		if (r[i] % 6 == 0 || i % 5 != 0)
			return r[i] + Sum(r, size, i + 1);
		else
			return Sum(r, size, i + 1);
	}
	else
		return 0;
}
int Mode(int* r, const int size, int i)
{
	if (r[i] % 6 == 0 || i % 5 != 0)
		r[i] = 0;
	if (i < size - 1)
		Mode(r, size, i + 1);
	else
		return 0;
}

int main()
{
	srand((unsigned)time(NULL));
	const int n = 22;
	int r[n];
	int Low = 4;
	int High = 73;
	Create(r, n, Low, High, 0);
	Print(r, n, 0);
	cout << "  " << "N = " << Number(r, n, 0, 0) << endl;
	cout << "  " << "S = " << Sum(r, n, 0) << endl;
	Mode(r, n, 0);
	Print(r, n, 0);
	return 0;
}