#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, all = 0;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		all ^= a[i];
	}
	for (int i = 0; i < n; ++i) {
		cout << (all ^ a[i]) << ' ';
	}
	return 0;
}