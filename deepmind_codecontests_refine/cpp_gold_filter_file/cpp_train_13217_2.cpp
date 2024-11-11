#include <iostream>
#include <algorithm>
using namespace std;
int n, q, xa, ya, xb, yb, xc[5555], yc[5555], xd[5555], yd[5555]; pair<int, int> p1[5555], p2[5555];
int main() {
	scanf("%d%d", &n, &q);
	for(int i = 0; i < n; i++) scanf("%d%d", &p1[i].first, &p1[i].second), p2[i] = make_pair(p1[i].second, p1[i].first);
	sort(p1, p1 + n); sort(p2, p2 + n);
	for(int i = 0; i < n; i++) xc[i] = p1[i].first, yc[i] = p1[i].second, xd[i] = p2[i].second, yd[i] = p2[i].first;
	for(int i = 0; i < q; i++) {
		scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
		int l1 = lower_bound(xc, xc + n, xa) - xc;
		int r1 = lower_bound(xc, xc + n, xb + 1) - xc;
		int l2 = lower_bound(yd, yd + n, ya) - yd;
		int r2 = lower_bound(yd, yd + n, yb + 1) - yd;
		int c = 0;
		if(r1 - l1 <= r2 - l2) {
			for(int j = l1; j < r1; j++) {
				if(ya <= yc[j] && yc[j] <= yb) c++;
			}
		}
		else {
			for(int j = l2; j < r2; j++) {
				if(xa <= xd[j] && xd[j] <= xb) c++;
			}
		}
		printf("%d\n", c);
	}
}