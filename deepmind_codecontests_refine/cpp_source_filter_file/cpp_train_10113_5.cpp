#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
const int INF = 1e9;
const int MAXN = 5e3 + 6.9;
int n, a, b;
string s;
int maxx[MAXN];
int dp[MAXN];
void inline minimize(int& a, int b) {
  if (a > b) a = b;
}
void build() {
  int cnt = 0;
  for (int stat = 1; stat <= n; stat++) {
    vector<int> z;
    z.resize(n + 1, 0);
    for (int k = stat + 1, l, r = -1; k <= n; k++) {
      if (k <= r) z[k] = min(z[k - l], r - k + 1);
      while (k + z[k] <= n && s[k + z[k]] == s[stat + z[k]]) {
        z[k]++;
      }
      if (k + z[k] - 1 > r) {
        l = k - stat + 1;
        r = k + z[k] - 1;
      }
      maxx[k] = max(maxx[k], min(z[k], k - stat));
    }
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> a >> b;
  cin >> s;
  s = ' ' + s;
  build();
  fill(dp + 1, dp + 1 + n, INF);
  dp[0] = 0;
  for (int i = 0; i <= n; i++) {
    minimize(dp[i + 1], dp[i] + a);
    for (int j = 1; j <= maxx[i + 1]; j++) minimize(dp[i + j], dp[i] + b);
  }
  cout << dp[n];
}
