#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll prime(ll x) {
	ll i;
	if (x < 2)return 0;
	else if (x == 2) return 1;
	if (x % 2 == 0) return 0;
	for (i = 3; i*i <= x; i += 2) {
		if (x%i == 0) return 0;
	}
	return 1;
}
int main() {
	int N;
	while (cin >> N, N) {
		int cnt - 0;
		for (int i = 1; i <= N; i++) {
			if (prime(i) && prime(N - i + 1))
				cnt++;
		}
		cout << cnt << endl;
	}
}



