#include <bits/stdc++.h>

using namespace std;

struct Node { 
	int x, y;
}S[90001];
int sum[90001];
int res;
int n;
int m;
int d;

int main() {
	scanf("%d%d%d", &n, &m, &d);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			int k;
			scanf("%d", &k);
			S[k].x = i;
			S[k].y = j;
		}
	for(int i = d + 1; i <= n * m; i++)
		sum[i] = sum[i - d] + abs(S[i].x - S[i - d].x) + abs(S[i].y - S[i - d].y);
	int Q;
	scanf("%d", &Q);
	while(Q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", sum[r] - sum[l]);
		res = 0;
	}
	return 0;
}