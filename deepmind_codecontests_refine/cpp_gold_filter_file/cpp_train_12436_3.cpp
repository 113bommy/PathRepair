#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
long long power(long long a, long long b);
vector<long long> z_function(vector<long long> s) {
  long long n = (long long)s.size();
  vector<long long> z(n);
  for (long long i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long tt = 1;
  while (tt--) {
    long long n, m;
    cin >> n >> m;
    long long a[n + 1], b[m + 1];
    for (long long i = 1; i <= n; i++) cin >> a[i];
    for (long long i = 1; i <= m; i++) cin >> b[i];
    if (m > n) {
      cout << "0";
      return 0;
    }
    if (m == 1) {
      cout << n << "\n";
      exit(0);
    }
    vector<long long> c;
    for (long long i = 1; i < m; i++) c.push_back(b[i + 1] - b[i]);
    for (long long i = 1; i < n; i++) c.push_back(a[i + 1] - a[i]);
    vector<long long> z = z_function(c);
    long long ans = 0;
    for (long long i = m - 1; i < z.size(); i++) {
      if (z[i] >= (m - 1)) ans++;
    }
    cout << ans << "\n";
  }
  return 0;
}
long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b % 2)
      b--, res = res * a;
    else
      b = b / 2, a *= a;
  }
  return res;
}
