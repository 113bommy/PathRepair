#include <bits/stdc++.h>
using namespace std;
int a[1001[1001], n, d1, d2, p;
void work(int k) {
	int b = 0;
	while (k % 4 == 0) 
	{
	      k /= 4;
	      b++;
	}
	if (k & 1) {
		for (int i = 0; i < 2 * n; i++) 
		{
			for (int j = 0; j < 2 * n; j++) 
			{
				if (((i >> b) + (j >> b)) & 1) 
				{
					a[i][j] = 1;
				}
			}
		}
	} 
	else 
	{
		for (int i = 0; i < 2 * n; i++) 
		{
			for (int j = 0; j < 2 * n; j++) 
			{
				if ((i >> b) & 1) 
				{
					a[i][j] = 1;
				}
			}
		}
	}
}
int main() 
{
	scanf("%d%d%d", &n, &d1, &d2);
	work(d1);
	work(d2);
	for (int i = 0; i < 2 * n; i++) 
	{
		for (int j = 0; j < 2 * n; j++) 
		{
			if (p < n * n && !a[i][j]) 
			{
				printf("%d %d\n", i, j);
				p++;
			}
		}
	}
	return 0;
}