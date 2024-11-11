#include <iostream>
#include <algorithm>
using namespace std;
int n, q, c, x, y, size_, dat[262144];
void update(int pos, int x) {
	pos += size_; dat[pos] = x;
	while(pos > 1) {
		pos /= 2;
		dat[pos] = min(dat[2 * pos], dat[2 * pos + 1]);
	}
}
int query(int a, int b, int k, int l, int r) {
	if(r <= a || b <= l) return 2147483647;
	if(a <= l && r <= b) return dat[k];
	int lc = query_(a, b, 2 * k, l, (l + r) / 2);
	int rc = query_(a, b, 2 * k + 1, (l + r) / 2, r);
	return min(lc, rc);
}
int main() {
	scanf("%d%d", &n, &q);
	for(size_ = 1; size_ < n;) size_ *= 2;
	for(int i = 0; i < size_ * 2; i++) dat[i] = 2147483647;
	for(int i = 0; i < q; i++) {
		scanf("%d%d%d", &c, &x, &y);
		if(c == 0) update(x, y);
		else printf("%d\n", query(x, y + 1, 1, 0, size_));
	}
}