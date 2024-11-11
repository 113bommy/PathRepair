#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 4e5 + 5;
const ll M = 1e18 + 7;
int a[N];
ll dp[(1 << 20)][20];
ll d[20][20], suff[N][20];
ll sum[N], cnt[N];
void solve() {
  for (int mask = 0; mask < (1 << 20); ++mask) {
    for (int i = 0; i < 20; ++i) {
      dp[mask][i] = M;
    }
  }
  int n;
  cin >> n;
  int ret_mask = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i]--;
    ret_mask |= (1 << a[i]);
    ++cnt[a[i]];
    sum[a[i]] += i;
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j < 20; ++j) {
      suff[i][j] = suff[i + 1][j] + (a[i] == j);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 20; ++j) {
      if (a[i] == j) continue;
      d[a[i]][j] += suff[i + 1][j];
    }
  }
  for (int i = 0; i < 20; ++i) dp[0][i] = 0;
  for (int mask = 0; mask < (1 << 20); ++mask) {
    bool bad = 0;
    for (int i = 0; i < 20; ++i) {
      if (((mask >> i) & 1) && !cnt[i]) bad = 1;
    }
    if (bad) continue;
    ll opt = M;
    ll was = 0;
    for (int i = 0; i < 20; ++i) {
      if ((mask >> i) & 1) {
        opt = min(opt, dp[mask][i]);
        was += cnt[i];
      }
    }
    if (!mask) opt = 0;
    for (int i = 0; i < 20; ++i) {
      if (!((mask >> i) & 1)) {
        ll sz = cnt[i];
        ll j = was * sz + (sz * (sz + 1)) / 2;
        ll add = 0;
        for (int k = 0; k < 20; ++k) {
          if ((mask >> k) & 1) add += d[i][k];
        }
        ll idx_sum = add + sum[i];
        dp[mask | (1 << i)][i] = min(dp[mask | (1 << i)][i], opt + idx_sum - j);
      }
    }
  }
  cout << *min_element(dp[ret_mask], dp[ret_mask] + 20);
}
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  int tt = 1;
  while (tt--) {
    solve();
    cout << '\n';
  }
  return 0;
}
