#include<bits/stdc++.h>
using namespace std;
const int N = 305, inf = 1e9;

int n, k;
char a[N];

int dt[N][N][N];
bool vis[N][N][N];

int solve (int S, int E, int X) {
	if(X < 0) return -inf;
	if(S > E) return 0;
	if(vis[S][E][X]) return dt[S][E][X];
	vis[S][E][X] = true;
	dt[S][E][X] = max({solve(S+1, E, X), solve(S, E-1, X), solve(S+1, E-1, X - (a[S] != a[E])) + 1 + (S != E)});
	return dt[S][E][X];
}

int main()
{
	scanf("%s%d",a+1,&k);
	n = strlen(a+1);
	printf("%d\n",solve(1, n, k));
}
