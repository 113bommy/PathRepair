#include "bits/stdc++.h"
using namespace std;
const long long INF = long long(1e18) + 1;
int main() {
	int N;
	long long K;
	cin >> N >> K;
	vector<long long>A(N);
	for (int n = 0; n < N; ++n) {
		cin >> A[n];
	}
	//小さい順にソート
	sort(A.begin(), A.end());
	long long l = -INF;
	long long r = INF;	
	while (l + 1 < r) {
		long long x = (l + r) / 2;
		bool check = [&] {
			long long tmp = 0;
			for (int n = 0; n < N; ++n) {
				if (A[n] < 0) {
					int l = -1;
					int r = N;
					while (l + 1 < r) {
						int c = (l + r) / 2;
						if (A[c] * A[n] < x) {
							r = c;
						}
						else {
							l = c;
						}
					}
					tmp += (long long)(N - r); 
				}
				else {
					int l = -1, r = N;
					while (l + 1 < r) {
						int c = (l + r) / 2;
						if (A[c] * A[n] < x) l = c; else r = c;
					}
					tmp += (long long)r; 
				}
				if (A[n] * A[n] < x) {
					tmp--;
				}
			}
			tmp /= 2; 
			return tmp < K;
		}();
		if (check) {
			l = x;
		}
		else {
			r = x;
		}
	}
	cout << l << endl;
	return 0;
}