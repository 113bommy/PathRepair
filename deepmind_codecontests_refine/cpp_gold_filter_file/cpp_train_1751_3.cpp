#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define double long double
vector<long long> solve(vector<long long> v) {
	int N = v.size();
	vector<double> pot(N), sum(N);
	for (int i = 0; i < N; ++i) pot[i] = log2(v[i]) / 2; // = log4(v[i])
	for (int i = 1; i < N; ++i) {
		double diff = pot[i] - pot[i - 1] + 32 + 1.0e-11L;
		sum[i] = sum[i - 1] + (diff - int(diff));
	}
	vector<double> eval(N);
	for (int i = 0; i < N; ++i) eval[i] = sum[i] - pot[i];
	vector<long long> ans(N);
	vector<int> st;
	double cur = 0, tailsum = 0;
	for (int i = N - 1; i >= 0; --i) {
		while (!st.empty() && eval[st.back()] >= eval[i]) {
			int last = N;
			if (st.size() >= 2) last = st[st.size() - 2];
			cur -= eval[st.back()] * (last - st.back());
			st.pop_back();
		}
		cur += eval[i] * ((st.empty() ? N : st.back()) - i);
		st.push_back(i);
		tailsum += eval[i];
		ans[i] = tailsum - cur;
	}
	return ans;
}
int main() {
	int N;
	cin >> N;
	vector<long long> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<long long> cpos = solve(A);
	reverse(A.begin(), A.end());
	vector<long long> cneg = solve(A);
	reverse(A.begin(), A.end());
	reverse(cneg.begin(), cneg.end());
	long long ans = (1LL << 60);
	for (int i = 0; i <= N; ++i) {
		ans = min(ans, (i == N ? 0 : cpos[i]) * 2 + (i == 0 ? 0 : cneg[i - 1]) * 2 + i);
	}
	cout << ans << endl;
	return 0;
}