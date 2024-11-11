#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
const long double PI =
    3.141592653589793238462643383279502884197169399375105820974944;
inline void io() {}
const long long mod = 2e15;
const long long maxn = 2e5 + 5;
void solve() {
  long long n, m;
  cin >> n >> m;
  m = m * 8;
  long long a[n], cnt = 0;
  map<long long, long long> mp;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  map<long long, long long> st1, st2;
  sort(a, a + n);
  for (long long i = 0; i < n - 1; i++) {
    if (a[i] < a[i + 1]) st1[a[i]] = n - i - 1;
  }
  for (long long i = 1; i < n - 1; i++) {
    if (a[i] > a[i - 1]) st2[a[i]] = i;
  }
  vector<long long> v(a, a + n);
  v.resize(unique(v.begin(), v.end()) - v.begin());
  long long k = m / n;
  k = pow(2, min(20ll, k));
  long long ans = INT_MAX;
  for (long long i = 0; i < (long long)((v).size()) - k + 1; i++) {
    ans = min(ans, st2[v[i]] + st1[v[i + k - 1]]);
  }
  if (ans == INT_MAX) ans = 0;
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(16);
  long long tc = 1;
  while (tc--) {
    solve();
  }
  return 0;
}
