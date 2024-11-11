#include <bits//stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long int ll;
int main() {
	int n,cnt = 0; cin >> n; vector<int> a(n);
	rep(i, n) cin >> a[i];
	sort(a.begin(), a.end());
	ll sum = 0;
	rep(i, n - 1) {
		sum += a[i];
		if (sum * 2 < a[i + 1]) cnt = i+1;
	}cout << n - cnt << endl;
}
