#include<cstdio>
 
int main()
{
	int X;
	scanf("%d", &X);
	for (int A = 0; A < 1000; ++A)
		for (int B = -1000; B < A; ++B)
			if (A * A * A * A * A - B * B * B * B * B == X)
			{
				printf("%d %d", A, B);
				return 0;
			}
}