#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
ld eps = 1e-9;

int main() {
	ld d; cin >> d;
	ld ans = d*sqrt(2);
	for (int i = 0; i < d+eps; ++i) {
		ld x = sqrt(d*d - i*i);
		ans = max(ans, ld(i) + 1);
	}
	cout << setprecision(22) << fixed<<ans << endl;
	return 0;
}