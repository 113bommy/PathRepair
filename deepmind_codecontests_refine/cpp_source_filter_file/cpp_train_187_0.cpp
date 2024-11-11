#include<cstdio>
int n;
int f[100][14];
int p[100][15];

int main() {
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)for (int j = 0; j < 10; j++)scanf_s("%d", &f[i][j]);
	for (int i = 0; i < n; i++)for (int j = 0; j < 11; j++) scanf_s("%d", &p[i][j]);
	int res = -(1 << 30);
	for (int b = 1; b < (1 << 10); b++) {
		int cc = 0;
		for (int i = 0; i < n; i++) {
			int c = 0;
			for (int j = 0; j < 10; j++)if ((b >> j & 1) && f[i][j])c++;
			cc += p[i][c];
		}
		if (res < cc)res = cc;
	}
	printf("%d\n", res);

	return 0;
}