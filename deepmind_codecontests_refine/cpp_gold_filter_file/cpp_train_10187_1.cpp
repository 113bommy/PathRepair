#include <iostream>
#include<stdio.h>
using namespace std;
int a[102];
int b[102];
int main()
{
	long long n;
	int p1 = 0, p2 = 0, m = 100;
	scanf("%lld", &n);
	n++;
	while (n > 1)
	{
		if (n & 1)
		{
			a[++p1] = m--;
			n--;
		}
		else
		{
			b[++p2] = m--;
			n >>= 1;
		}
	}
	printf("%d\n", p1 + p2 << 1);
	for (int i = 1; i <= p1; i++)
		printf("%d ", a[i]);
	for (int i = p2; i >= 1; i--)
		printf("%d ", b[i]);
	for (int i = 101 - p1 - p2; i <= 100; ++i)
		printf("%d ", i);
	return 0;
}
