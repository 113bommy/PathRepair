#include<stdio.h>

int main() {
	int n, y;
	scanf("%d %d",&n, &y);

	for (int ix = 0; ix <= n; ++ix) {
		for (int i = 0; i <= n - ix; ++i) {
			if (ix * 10000 + i * 5000 + (n - ix - i) * 1000 == y) {
				printf("%d %d %d\n", ix, i, n - ix - i);
				return 0;
			}
		}
	}

	printf("-1 -1 -1\n");
}