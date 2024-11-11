#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * power(a * a % md, b / 2, md) % md
                      : power(a * a % md, b / 2, md) % md));
}
const int xn = 4e5 + 10;
const int xm = -20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const long long INF = 1e18 + 10;
const long double eps = 1e-15;
const int mod = 998244353;
const int base = 257;
int n, dp[xn], ps[xn], ans;
pair<pair<int, int>, int> a[xn];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int fl;
    cin >> a[i].first.first >> a[i].first.second >> a[i].second;
    dp[i] = a[i].first.first - a[i].first.second;
    int lb = 0, rb = i;
    while (1 < rb - lb) {
      int mid = lb + rb >> 1;
      if (a[mid].first.first < a[i].first.second)
        lb = mid;
      else
        rb = mid;
    }
    dp[i] = (dp[i] + ps[i - 1]) % mod;
    dp[i] = (dp[i] - ps[lb] + mod) % mod;
    ps[i] = (ps[i - 1] + dp[i]) % mod;
  }
  ans = a[n].first.first + 1;
  for (int i = 1; i <= n; ++i)
    if (a[i].second) ans = (ans + dp[i]) % mod;
  cout << ans << '\n';
  return 0;
}
