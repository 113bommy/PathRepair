#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;

int main() {
	int H[2], ans = (int)1e5;
	cin >> H[0] >> H[1];
	for (int i = 0; i < 2; i++) {
		if (H[i] % 3 == 0) {
			cout << 0 << endl;
			return 0;
		}
		ans = min(ans, H[1 - i]);
		int H1 = H[i] / 3;
		int S_max = (H1 + 1) * H[1 - i];
		int S_min = (H[i] - H1 - 1) * (H[1 - i] / 2);
		ans = min(ans, S_max - S_min);
		S_min = H1 * H[1 - i];
		S_max = (H[i] - H1) * ((H[1 - i] + 1) / 2);
		ans = min(ans, S_max - S_min);
	}
	cout << ans << endl;
	return 0;
}
