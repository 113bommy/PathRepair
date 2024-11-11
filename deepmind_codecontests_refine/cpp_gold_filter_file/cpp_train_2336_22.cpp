#include <bits/stdc++.h>
using namespace std;
int n, m, b;
const int N = 102;
int x[N], k[N], M;
int mask[N];
long long dp[(1ll << 20) + 1];
template <typename T>
inline void smin(T &a, T b) {
  if (a > b) a = b;
}
int main() {
  scanf("%d %d %d", &n, &m, &b);
  vector<pair<pair<int, int>, int>> v(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d %d", x + i, k + i, &M);
    for (int j = 1; j <= M; ++j) {
      int x;
      scanf("%d", &x);
      mask[i] |= (1ll << (x - 1));
    }
    v[i] = {{k[i], x[i]}, mask[i]};
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; ++i) {
    x[i] = v[i].first.second;
    k[i] = v[i].first.first;
    mask[i] = v[i].second;
  }
  int fmask = (1ll << m) - 1;
  for (int i = 0; i <= (1 << 20); ++i) dp[i] = 2.1e18;
  dp[0] = 0;
  long long res = 2.1e18;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= fmask; ++j) {
      smin(dp[j | (mask[i])], dp[j] + x[i]);
    }
    if (~dp[fmask]) {
      smin(res, dp[fmask] + b * 1ll * (k[i]));
    }
  }
  if (res >= 2e18)
    puts("-1");
  else
    cout << res << endl;
}
