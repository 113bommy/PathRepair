#include <iostream>
#include <algorithm>
using namespace std;
int q, n, m, a[100000], b[99999];
int main() {
	cin >> q;
	for(int i = 0; i < q; i++) {
		cin >> n >> m;
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 1; i < n; i++) b[i - 1] = a[i] - a[i - 1];
		sort(b, b + n - 1);
		int ret = a[n - 1] - a[0];
		for(int i = n - 2; i >= n - m && i >= 0; i--) ret -= b[i];
		cout << ret << endl;
	}
}