#include<stdio.h>
#define MAXN 100006
int memo[MAXN], flag[MAXN];

int main() {
	int m, n, x, y, ans = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) memo[i] = 1, flag[i] = 0;
	flag[1] = 1;
	while (m--) {
		scanf("%d%d", &x, &y);
		if (flag[x] == 1) flag[y] = 1;
		memo[x]--, memo[y]++;
		if (memo[x] == 0) flag[x] = 0;
	}
	for (int i = 1; i <= n; i++) if (flag[i] == 1) ans++;
	printf("%d\n", ans);
	return 0;
}