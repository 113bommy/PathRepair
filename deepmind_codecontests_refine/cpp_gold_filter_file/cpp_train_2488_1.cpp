#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int N;
int X[3000], Y[3000];
bool F[5001][5001];
int solve(int P, int Q){
	int xp = X[P];
	int yp = Y[P];
	int xq = X[Q];
	int yq = Y[Q];
	int xs = xp + (yp - yq);
	int ys = yp + (xq - xp);
	int xr = xq + (yp - yq);
	int yr = yq + (xq - xp);
	if ((xs>=0&&xs<=5000)&&(ys>=0&&ys<=5000)&&(xr>=0&&xr<=5000)&&(yr>=0&&yr<=5000)&&F[xs][ys]&&F[xr][yr])return (xq - xp)*(xq - xp) + (yq - yp)*(yq - yp);
	xs = xp - (yp - yq);
	ys = yp - (xq - xp);
	xr = xq - (yp - yq);
	yr = yq - (xq - xp);
	if ((xs >= 0 && xs<=5000) && (ys >= 0 && ys<=5000) && (xr >= 0 && xr<=5000) && (yr >= 0 && yr<=5000) && F[xs][ys] && F[xr][yr])return (xq - xp)*(xq - xp) + (yq - yp)*(yq - yp);
	return 0;
}
int main()
{
	while (true){
		scanf("%d", &N);
		if (N == 0)return 0;
		for (int i = 0; i < N; i++){
			scanf("%d%d", &X[i], &Y[i]);
			F[X[i]][Y[i]] = true;
		}
		int ans = 0;
		for (int i = 0; i < N; i++){
			for (int j = i + 1; j < N; j++){
				ans = max(ans, solve(i, j));

			}
		}
		printf("%d\n", ans);
		for (int i = 0; i < N; i++)F[X[i]][Y[i]] = false;
	}
}