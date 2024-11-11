#include <cstdio>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define Nmax 200010
inline int lowbit(int x)
{
	return x&-x;
}

int ls[2][Nmax];
long long N;
int Q;
long long ans;
void adin(int *A, int x, int y)
{
	for (int i = x; i <= N; i += lowbit(i))
		A[i] = min(A[i], y);
}
int qin(int *A, int x)
{
	int as = N+1;
	for (int i = x; i; i -= lowbit(i))
		as = min(as, A[i]);
	return as;
}
int main()
{
	scanf("%lld %d", &N, &Q);
	ans = (N-2)*(N-2);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 1; j <= N; j++)
			ls[i][j] = N+1;
	}
	adin(ls[0], 1, N);
	adin(ls[1], 1, N);
	int a, b;
	int q;
	int x, y;
	for (int i = 0; i < Q; i++)
	{
		scanf("%d %d", &a, &b);
		q = qin(ls[a-1], N-b+1);
		ans -= q-2;
		if (a == 1)
		{
			x = q;
			y = b;
		}
		else
		{
			x = b;
			y = q;
		}
		adin(ls[0], N-y+1, x);
		adin(ls[1], N-x+1, y);
	}
	printf("%lld\n", ans);
	return 0;
}