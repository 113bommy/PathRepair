#include <bits/stdc++.h>
using namespace std;
const long long N = 2001, M = 201, mod = 1e9 + 7;
long long n, m;
long long _hash[M * M], Pow[M * M], cal1[N], cal2[N];
string a[N], b[M];
long long solve(string res) {
  long long x = res.length();
  for (long long i = 0; i < x; ++i) {
    if (i == 0)
      _hash[i] = res[i] - 'a' + 1;
    else
      _hash[i] = (_hash[i - 1] * 27 + res[i] - 'a') % mod;
  }
  return _hash[x - 1];
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  Pow[0] = 1;
  for (long long i = 1; i <= m * m; ++i) Pow[i] = Pow[i - 1] * 27 % mod;
  for (long long i = 0; i < n; ++i) cin >> a[i];
  for (long long i = 0; i <= n - m; ++i) {
    string res = "";
    for (long long j = i; j < m + i; ++j) res += a[j];
    cal1[i] = solve(res);
  }
  for (long long i = 0; i < m; ++i) cin >> b[i];
  for (long long i = 0; i <= n - m; ++i) {
    string res = "";
    for (long long j = 0; j < m; ++j)
      for (long long st = i; st < i + m; ++st) res += b[j][st];
    cal2[i] = solve(res);
  }
  for (long long i = 0; i <= n - m; ++i)
    for (long long j = 0; j <= n - m; ++j)
      if (cal1[i] == cal2[j]) {
        cout << i + 1 << ' ' << j + 1;
        return 0;
      }
}
