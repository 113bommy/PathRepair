#include <stdio.h>
#include <algorithm>
using namespace std;
int n, m, c[100];
inline int solve() {
	int ret = 0, u = 1;
	for(int i = 0; i < m - 1; i++) u *= c[i];
	for(int i = m - 1; i < n; i++) u *= c[i], ret = max(ret, u), u /= c[i - m + 1];
	return ret;
}
int main() {
	while(scanf("%d%d", &n, &m), n) {
		for(int i = 0; i < n; i++) scanf("%d", c + i);
		int ret = 0, res = solve();
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j < n; j++) {
				swap(c[i], c[j]);
				ret = max(ret, solve());
				swap(c[i], c[j]);
			}
		}
		if(ret < res) puts("NO GAME");
		else printf("%d\n", ret - res);
	}
}