#include <bits/stdc++.h>
using namespace std;

int main() {
	int D, G;
	cin >> D >> G;

	vector<int> p(D), c(D);
	for (int i = 0; i < D; i++) {
		cin >> p[i] >> c[i];
	}

	int ans = 10000;
	for (int i = 0; i < (1<<D); i++) {
		int sum = 0;
		int n = 0;
		for (int j = 0; j < D; j++) {
			if (!(i & (1 << j))) continue;
			sum += 100 * (j + 1) * p[j] + c[j];
			n += p[j];
		}

		for (int j = D - 1; j >= 0; j--) {
			if ((i & (1 << j))) continue;
			if (G - sum <= 0) continue; 

			int cnt = min((G - sum) / (100 * (j + 1)), p[j] - 1);
			n += cnt;
			sum += cnt * 100 * (j + 1);
		}
		ans = min(ans, n);
	}
	
	cout << ans << endl;

	return 0;
}
