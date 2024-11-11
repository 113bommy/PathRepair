#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, S; cin >> N >> S;
	vector<int>as(N);
	for (int i = 0; i < N; ++i)cin >> as[i];
	auto it = as.begin();auto jt = as.begin();
	int sum = 0;
	int ans = int(1e6);
	while (jt != as.end()) {
		sum += *jt;
		jt++;
		while (sum >= S) {
			ans = min(ans, int(jt - it));
			sum -= *it;
			it++;
		}
		 
	}
	if (ans == int(1e6))ans = 0;
	cout << ans << endl;
	return 0;
}