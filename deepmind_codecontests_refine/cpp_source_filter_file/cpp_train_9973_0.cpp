#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
typedef long long ll;

const int MAXN = 1e4 + 10;
struct Node {
	ll x, y;
	bool operator < (const Node a) {
		return atan2(x, y) < atan2(a.x, a.y);
	}
};

Node node[MAXN];

ll cal(ll x, ll y) {
	return x * x + y * y;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> node[i].x >> node[i].y;
	}
	sort(node, node + n);
	ll maxa = 0;
	for (int i = 0; i < n; i++) {
		ll x = node[i].x, y = node[i].y;
		maxa = max(maxa, x * x + y * y);
		for (int j = (i + 1) % n; j != i; j = (j + 1) % n) {
			x += node[j].x;
			y += node[j].y;
			maxa = max(maxa, x * x + y * y);
		}
	}
	cout << fixed << setprecision(11) << sqrt(maxa) << endl;
	return 0;
}