#include <stdio.h>
int N, A, B, v[111], r[111], G[111][222];
int rec(int pos) {
	int ret = 0; v[pos] = 1;
	for (int i = 0; i < r[pos]; i++) {
		if (!v[G[pos][i]]) {
			int w = rec(G[pos][i]);
			ret = ret > w ? ret : w;
		}
	}
	v[pos] = 0;
	return ret + 1;
}
int main() {
	while (scanf("%d", &N), N) {
		for (int i = 0; i < 100; i++) r[i] = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d%d", &A, &B), A--, B--;
			G[A][r[A]++] = B, G[B][r[B]++] = A;
		}
		int ret = 0;
		for (int i = 0; i < 100; i++) {
			int w = rec(i);
			ret = ret > w ? ret : w;
		}
		printf("%d\n", ret);
	}
	return 0;
}