#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	long long N, X;
	cin >> N >> X;
	vector<long long> x(N);

	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}

	reverse(x.begin(), x.end());

	long long ans = INFINITY;

	vector<long long> sum(N + 1);

	for (int i = 0; i < N; i++) {
		sum[i + 1] = sum[i] + x[i];
	}

	for (long long k = 1; k < N + 1; k++) {
		long long cost = k * X + N * X;
		
		for (long long i = 0; i*k < N; i++) {
			long long t = i + 1;
			long long l = k * i;
			long long r = min(l + k, N);
			if (t == 1) {
				cost += (sum[r] - sum[l]) * 5;
			}
			else {
				cost += (sum[r] - sum[l])*(2 * t + 1);
			}
			if (cost > ans) break;
		}
		ans = min(ans, cost);

	}

	cout << ans << endl;

}

