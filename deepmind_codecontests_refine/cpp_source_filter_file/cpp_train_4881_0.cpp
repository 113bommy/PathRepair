#include "bits/stdc++.h"
using namespace std;

vector<int>primes(1e8);
vector<int>sums(1e8 + 1);
void hurui(const int amax) {
	static bool flag = false;
	if (flag)return;
	vector<int>sos;
	sos = vector<int>(amax + 1, true);
	sos[0] = false; sos[1] = false;
	for (int i = 2; i <= amax; ++i) {
		if (sos[i]) {
			for (int j = 2 * i; j <= amax; j += i)sos[j] = false;
		}
	}
	for (int i = 0; i <= amax; ++i) {
		if (sos[i]) {
			primes[i] = true;
		}
	}
	flag = true;
}


int main() {
	hurui(999983);
	for (int i = 0; i < 1e7; ++i) {
		sums[i + 1] = sums[i] + primes[i + 1];
	}
	while (1) {
		int N; cin >> N;
		if (!N)break;
		long long int prize = 0;
		while (N--) {
			long long int p, m; cin >> p >> m;
			int amax = min(999983ll, p + m);
			int amin = max(0ll, p - m-1);
			const int aprize = sums[amax] - sums[amin];
			prize += aprize - 1;
		}
		cout << max(0,prize )<< endl;
	}
	return 0;
}