#include <cstdio>

int main()
{
	scanf("%d", &K);
	int x = 0;
	int ans = -1;
	for (int i = 0; i < K; ++i) {
		x = (10 * x + 7) % K;
		if (x == 0) {
			ans = i + 1;
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}

