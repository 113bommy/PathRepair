#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#define int long long
using namespace std;

signed main() {
	int a, b;
	cin >> a >> b;
	vector<int>c(b);
	vector<int>f(a-1);
	for (int d = 0; d < b; d++) { int g; cin >> g; g--; c[d] = g; }
	for (int e = 0; e < b - 1; e++) {
		vector<int>h(2); h[0] = c[e]; h[1] = c[e + 1];
		sort(h.begin(), h.end());
		for (int i = 0; i < a - 1; i++) {
			if (i >= h[0] && i < h[1])f[i]++;
		}
	}
	int s = 0;
	for (int i = 0; i < a - 1; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		s += min(x*f[i],z+y*f[i]);
	}
	cout << s << endl;
}