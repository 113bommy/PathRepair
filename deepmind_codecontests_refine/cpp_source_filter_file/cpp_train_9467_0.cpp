#include <stdio.h>
#include <algorithm>
int a, b;
int main() {
	while(scanf("%d%d", &a, &b), a + b) {
		int ret = 999999999;
		for(int i = 1; i * i <= a; i++) {
			if(a % i) continue;
			for(int j = 1; j * j <= b; j++) {
				if(b % j) continue;
				int p[4] = { i, a / i, j, b / j };
				std::sort(p, p + 4);
				int res = 0;
				for(int k = 0; k < 2; k++) res += (p[k + 1] - p[k]) * (p[k + 1] - p[k]);
				ret = min(ret, res);
			}
		}
		printf("%d\n", ret);
	}
}