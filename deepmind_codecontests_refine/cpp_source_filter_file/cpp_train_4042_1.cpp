#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) cin >> A[i];
	sort(A.begin(), A.end());
	long long sum = 0;
	for (int i = 0; i < N - 1; ++i) {
		sum += 2 * long long(min(i + 1, N - i - 1)) * (A[i + 1] - A[i]);
	}
	if (N % 2 == 0) {
		sum -= A[N / 2] - A[N / 2 - 1];
	}
	else {
		sum -= min(A[N / 2] - A[N / 2 - 1], A[N / 2 + 1] - A[N / 2]);
	}
	cout << sum << endl;
	return 0;
}