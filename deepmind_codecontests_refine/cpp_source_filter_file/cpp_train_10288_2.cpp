#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int x[110], y[110]; long long h[110];
	long long H;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> h[i];
	}
	bool flag;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			flag = true;
			for (int k = 0; k < n; k++) {
				if (h[k] >= 1) {
					H = h[k] + abs(x[k] - i) + abs(y[k] - j);
					break;
				}
			}
			for (int k = 0; k < n; k++) {
				if (max(0,H - abs(x[k] - i) - abs(y[k] - j)) != h[k] ) {
					flag = false;
					break;
				}
			}
			if (flag == true) {
				cout << i << ' ' << j << ' ' << H << endl;
			}
		}
	}
}
