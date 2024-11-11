#include <bits/stdc++.h>
using namespace std;

using db = double;
const db eps = 1e-6;

struct poi {
	db x, y;
	void r() { cin >> x >> y; }
	poi operator -(poi p) {
		return {x - p.x, y - p.y};
	}
	db cross(poi p) {
		return x * p.y - y * p.x;
	}
};
db xmul(poi a, poi b, poi c) {
	return (b - a).cross(c - a);
}

int main() {
	ios :: sync_with_stdio(false);
	poi a, b, c, p;
	while(cin >> a.x >> a.y) {
		b.r(); c.r(); p.r();
		db s = abs(xmul(a, b, c));
		db t = abs(xmul(p, a, b)) + abs(xmul(p, b, c)) + abs(xmul(p, c, a));
		if(s < t + eps && t < s + eps)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}