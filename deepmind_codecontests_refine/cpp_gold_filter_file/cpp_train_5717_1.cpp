#include <stdio.h>
#include <algorithm>
using namespace std;
int n, s, r;
int main() {
	while(scanf("%d%d", &n, &s), n) {
		int a[102] = {0};
		for(int i = 0; i < n; i++) scanf("%d", &r), a[r]++;
		int ret = 0;
		for(int i = 1; i <= 100; i++) {
			for(int j = max(i, s - i + 1); j <= 100; j++) {
				ret += a[i] * a[j];
			}
		}
		for(int i = s / 2 + 1; i <= 100; i++) ret -= (a[i] * a[i] + a[i]) / 2;
		printf("%d\n", ret);
	}
}