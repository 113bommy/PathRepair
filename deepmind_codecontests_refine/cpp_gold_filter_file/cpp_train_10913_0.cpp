#include<iostream>
#include<algorithm>
using namespace std;

const int sq = 30000;
int ans = 0, n;

int sg(int x, int k) {
	if (x % k == 0)return x / k;
	if (x / k > sq)return sg(x - x / k - 1, k);
	else {
		int m1 = x % k;
		return sg(x - max(x / k + 1, m1 - m1 % (x / k + 1)), k);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x, k;
		scanf("%d%d", &x, &k);
		ans ^= sg(x, k);
	}
	cout << (ans ? "Takahashi" : "Aoki") << endl;

	return 0;
}
