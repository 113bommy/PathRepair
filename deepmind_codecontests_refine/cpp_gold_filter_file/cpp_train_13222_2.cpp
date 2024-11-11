#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
int cnt;
vector<int> G;

void insertionSort(vector<int> &A, int n, int g)
{
	for (int i = g; i < n; i++)
	{
		int v = A[i];
		int j = i - g;
		while (j >= 0 && A[j] > v)
		{
			A[j + g] = A[j];
			j -= g;
			cnt++;
		}
		A[j + g] = v;
	}
}
void shellsort(vector<int> &A, int n)
{
	for (int h = 1; h <= n; h = 3 * h + 1)
	{
		G.push_back(h);
	}
	for (int i = G.size() - 1; i >= 0; --i)
	{
		insertionSort(A, n, G[i]);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &v[i]);
	}
	
	shellsort(v, n);

	printf("%d\n", G.size());
	for (int i = G.size() - 1; i >= 0; --i)
		printf("%d ", G[i]);
	printf("%d\n", cnt);
	for (int i = 0; i < n; ++i)
		printf("%d\n", v[i]);

	return 0;
}