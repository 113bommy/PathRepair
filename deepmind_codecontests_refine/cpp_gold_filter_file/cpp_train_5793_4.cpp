#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("omit-frame-pointer")
#pragma GCC optimize("unroll-loops")
const int MAXINT = 2147483640;
const long long MAXLL = 9223372036854775800LL;
const long long MAXN = 1000000;
const double eps = 1e-9;
const long long mod = 1e9 + 7;
using namespace std;
long long binpow(long long a, long long n) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans *= a;
    a *= a;
    n >>= 1;
  }
  return ans;
}
vector<long long> v[100];
long long i, n, m, j, a, b, kek, x[MAXN * 5], mask;
long long dp[MAXN * 5];
pair<long long, long long> f[MAXN * 5];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  srand(time(0));
  cin >> n;
  for (i = 1; i <= (1 << n); i++) dp[i] = 1e18;
  cin >> m;
  if (m == (n * (n - 1)) / 2) {
    cout << 0 << endl;
    return 0;
  }
  for (i = 1; i <= m; i++) {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for (i = 1; i <= n; i++) {
    x[i] = (1 << (i - 1));
    for (j = 0; j < v[i].size(); j++) {
      x[i] += (1 << (v[i][j] - 1));
    }
  }
  dp[0] = 0;
  f[0] = make_pair(-1, -1);
  for (i = 0; i <= (1 << n) - 1; i++) {
    for (j = 1; j <= n; j++) {
      if ((i & (1 << (j - 1))) or !i) {
        mask = i | x[j];
        if (dp[mask] > dp[i] + 1) {
          dp[mask] = dp[i] + 1;
          f[mask] = make_pair(i, j);
        }
      }
    }
  }
  cout << dp[(1 << n) - 1] << endl;
  kek = (1 << n) - 1;
  vector<long long> v1;
  while (f[kek].first != -1) {
    v1.push_back(f[kek].second);
    kek = f[kek].first;
  }
  for (i = 0; i < v1.size(); i++) {
    cout << v1[i] << " ";
  }
  return 0;
}
