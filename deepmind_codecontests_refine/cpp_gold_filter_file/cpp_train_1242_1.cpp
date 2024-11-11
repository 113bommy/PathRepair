#include "bits/stdc++.h"
using namespace std;
int main() {
	int a[1000];
	int n, m;
	while (cin >> n >> m, n) {
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (a[i] + a[j] <= m) ans = max(ans, a[i] + a[j]);
			}
		}
		if (ans == 0) cout << "NONE" << endl;
		else cout << ans << endl;
	}
}
