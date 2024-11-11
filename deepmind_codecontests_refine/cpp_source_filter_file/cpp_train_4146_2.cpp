#include<bits/stdc++.h>
using namespace std;
long long N, A[200009], cnt;
multiset<long long> S;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A, A + N);
	for (int i = N - 1; i >= 0; i--) {
		bool flag = false;
		for (int j = 0; j < 32; j++) {
			long long ret = (1LL << j) - A[i];
			if (A[i] > ret) continue;
			auto itr = S.lower_bund(ret);
			if (itr != S.end() && *itr == ret) {
				S.erase(itr);
				cnt++;
				flag = true;
				break;
			}
		}
		if (flag == false) {
			S.insert(A[i]);
		}
	}
	cout << cnt << endl;
}