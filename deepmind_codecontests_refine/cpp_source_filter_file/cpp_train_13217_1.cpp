#include <iostream>
#include <algorithm>
using namespace std;
int n, q, xa, ya, xb, yb, x[5555], y[5555]; pair<int, int> p[5555];
int main() {
	scanf("%d%d", &n, &q);
	for(int i = 0; i < n; i++) scanf("%d%d", &p[i].first, &p[i].second);
	sort(p, p + n);
	for(int i = 0; i < n; i++) x[i] = p[i].first, y[i] = p[i].second;
	for(int i = 0; i < q; i++) {
		scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
		int l = lower_bound(x, x + n, xa);
		int r = lower_bound(x, x + n, xb + 1);
		int c = 0;
		for(int j = l; j < r; j++) {
			if(ya <= y[j] && y[j] <= yb) c++;
		}
		printf("%d\n", c);
	}
}