#include <bits/stdc++.h>
using namespace std;
const int N = 1e6, MOD = 1e9 + 7;
const long double EPS = 0.000000001;
pair<long long, long long> p[N];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long ans = 0, n;
  cin >> n;
  for (long long i = 2; i < n; i++) {
    ans += i * (i + 1);
  }
  cout << ans;
}
