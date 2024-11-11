#include <bits/stdc++.h>
using namespace std;

// why am I so weak

int n, k, l;
int par[2][200055];

typedef pair<int, int> P;

map<P, int> c;

int fin(int i, int j) {
	if (par[i][j] == j) return j;
	return par[i][j] = fin(i, par[i][j]);
}
int main() {
	scanf("%d %d %d", &n, &k, &l);

	for (int i = 0; i < n; i++) {
		par[0][i] = par[1][i] = i;
	}

	while (k--) {
		int x, y;
		scanf("%d %d", &x, &y);
		x--, y--;

		par[0][fin(0, x)] = fin(0, y);
	}

	while (l--) {
		int x, y;

		scanf("%d %d", &x, &y);
		x--, y--;

		par[1][fin(1, x)] = fin(1, y);
	}

	for (int i = 0; i < n; i++) c[P(fin(0, i), fin(1, i))]++;

	for (int i = 0; i < n; i++) {
		if (i) printf(" ");
		printf("%d", c[P(fin(0, i), fin(1, i))]);
	}

	puts("");

	return 0;
}
