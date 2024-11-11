#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, q, a;
	cin >> n >> k >> q;

	vector<int> p(n,0);
	for (int i = 0; i < q; i++) {
		cin >> a;
		p[a-1]++;
	}

	for (int i = 0; i < n; i++) {
		if (p[i]+k-q > 0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}