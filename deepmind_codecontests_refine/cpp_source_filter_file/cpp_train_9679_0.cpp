#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int d, n, m, x, y, z, p[50], q[50]; string s:
int main() {
	cin >> d >> n;
	for(int i = 0; i < n; i++) {
		cin >> s >> z;
		if(s == "D") p[x++] = z;
	}
	sort(p, p + x);
	cin >> m;
	for(int i = 0; i < m; i++) {
		cin >> s >> z;
		if(s == "DD") q[y++] = z;
	}
	sort(q, q + y);
	int ret = 0;
	for(int i = 0; i <= x; i++) {
		for(int j = 0; j <= y; j++) {
			if(i + 2 * j <= d) {
				int sum = 0;
				for(int k = 0; k < i; k++) sum += p[k];
				for(int k = 0; k < j; k++) sum += q[k];
				ret = max(ret, sum);
			}
		}
	}
	cout << ret << endl;
}