#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	int n, p = -1,i,X,Y; cin >> n;
	int x[105], y[105], h[105];
	for (i=0;i<n;i++) {
		cin >> x[i] >> y[i] >> h[i];
		if (h[i] != 0)p = i;
	}
	for (X = 0; X <= 100; X++) {
		for (Y = 0; Y <= 100; Y++) {
			int H = abs(x[p] - X) + abs(y[p] - Y) + h[p];
			if (H <= 0)continue;
			bool flag = 1;
			for (i = 0; i < n; i++)
				if (h[i] != max(H - abs(X - x[i]) - abs(Y - y[i]), (int)0))flag = 0;
			if (flag) {
				cout << X << ' ' << Y << ' ' << H << endl;
				cin >> n;
				return 0;
			}
		}
	}
}