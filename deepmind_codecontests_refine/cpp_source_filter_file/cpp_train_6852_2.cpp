#include "bits/stdc++.h"
using namespace std;

struct BIT {
	long long n;
	vector<long long> dat;

	void init(long long n_input) {
		n = n_input + 1;
		dat.resize(n + 1);
		for (int i = 0; i <= n; i++) dat[i] = 0;
	}

	long long sum(long long i) {
		long long s = 0;
		while (i >= 0) {
			s += dat[i];
			i = (i & (i + 1)) - 1;
		}
		return s;
	}

	void add(long long i, long long x) {
		while (i <= n) {
			dat[i] += x;
			i |= i + 1;
		}
	}
};

int main() {
	int i;
	int N;
	cin >> N;
	vector<int> A(N), sortedA(N);
	for (i = 0; i < N; i++) {
		cin >> A[i];
		sortedA[i] = A[i];
	}
	sort(sortedA.begin(), sortedA.end());
	int ub = N;
	int lb = 0;
	BIT bit;

	long long border = ((((long long)N * (N + 1) / 2) + 1) / 2;
	while (ub - lb > 1) {
		int mid = (ub + lb) / 2;
		int midn = sortedA[mid];
		bit.init(2 * N + 1);
		int sum = 0;
		bit.add(sum + N, 1);
		long long result = 0;
		for (i = 0; i < N; i++) {
			sum += A[i] >= midn ? 1 : -1;
			result += bit.sum(sum + N);
			bit.add(sum + N, 1);
		}
		if (result >= border) {
			lb = mid;
		}
		else {
			ub = mid;
		}
	}
	cout << sortedA[lb] << endl;
	return 0;
}
