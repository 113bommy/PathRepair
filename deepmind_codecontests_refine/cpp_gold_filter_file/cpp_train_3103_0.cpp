#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, r, l = 0;
	cin >> n;
	vector<int> w(n);
	for (int i = 0; i < n; i++) {
		cin >> w[i];
		r += w[i];
	}
	int d, m = 99;
	for (int j = 0; j < n; j++) {
		r -= w[j];
		l += w[j];
		d = abs(r - l);
		m = min(d, m);
	} 
	cout << m << endl;
	return 0;
}