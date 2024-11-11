#include<stdio.h>
const MAXL 1e5 + 10;
int Tree[MAXL];
int findRoot(int x) {
	if (Tree[x] == x) return x;
	else return Tree[x] = findRoot(Tree[x]);
}

int list[MAXL];
int belong[MAXL];

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", &list[i]);
			Tree[i] = i;
		}
		while (m--) {
			int a, b;
			scanf("%d%d", &a, &b);
			a = findRoot(a);
			b = findRoot(b);
			if (a != b) {
				Tree[a] = b;
			}
		}

		for (int i = 1; i <= n; i++) {
			belong[list[i]] = findRoot(i);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (belong[i] == findRoot(i))
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}