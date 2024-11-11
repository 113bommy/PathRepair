#include<cstdio>
int main()
{
	int X;
	scanf_s("%d", X);
	for (int A = 0; A < 1000; ++A)
		for (int B = -1000; B < A; ++B)
			if (A * A * A * A * A - B * B * B * B * B == X)
			{
				printf_s("%d %d", A, B);
				return 0;
			}
}