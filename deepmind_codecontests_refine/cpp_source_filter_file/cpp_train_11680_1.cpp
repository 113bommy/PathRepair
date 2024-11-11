#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, kk, a[N], ave;
vector<vector<int>> ans;
int calc(int s, int kk) {
  int ret = 0;
  for (int i = 0; i < kk; i++) ret += a[s + i];
  return ret;
}
int rr;
void choose(int s, int v, int kk) {
  a[s + kk - 1] = calc(s, kk) - v - ave * (kk - 2);
  a[s] = v;
  for (int i = 1; i + 1 < kk; i++) a[i + s] = ave;
  vector<int> vv = {(s - 1 + n - (::kk - kk)) % n};
  for (int i = kk; i < ::kk; i++) vv.push_back(a[rr--]);
  reverse(vv.begin() + 1, vv.end());
  vv.insert(vv.end(), a + s, a + s + kk);
  ans.push_back(vv);
}
int mnid, mn = INT_MAX;
void solve(int l, int r) {
  int tot = calc(max(r - kk + 1, l), min(kk, r - l + 1));
  int i;
  for (i = r - kk + 1; i >= l && tot * 1.0 / (r - i + 1) < ave;
       i -= kk - 1, tot += calc(i, kk - 1))
    ;
  int tt = i;
  if (i < l) {
    if (i + kk - 1 > l) rr = mnid, choose(l, ave, i + kk - 1 - l + 1);
  } else {
    choose(i, calc(i, r - i + 1) - ave * (r - i), kk);
  }
  while ((i += kk - 1) < r) choose(i, ave, kk);
  if (l < tt) solve(l, tt);
}
int c[N], pre[N], dp[N][20], stp[N];
map<int, int> lst[N];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> kk;
  for (int i = 1; i <= n; i++) cin >> a[i], ave += a[i + n] = a[i];
  ave /= n;
  memcpy(c, a + 1, sizeof(int) * n);
  for (int i = 1; i <= n * 2; i++) {
    pre[i] = pre[i - 1] + a[i] - ave;
    dp[i][0] = lst[(i - 1) % (kk - 1)][pre[i]];
    stp[i] = dp[i][0] ? stp[dp[i][0]] + (i - dp[i][0] - 1) / (kk - 1) : 0;
    lst[i % (kk - 1)][pre[i]] = i;
  }
  for (int i = 0; i < 20; i++)
    for (int j = 1; j <= n * 2; j++) dp[j][i] = dp[dp[j][i - 1]][i - 1];
  for (int i = n + 1; i <= n * 2; i++) {
    int pos = i;
    for (int j = 19; j >= 0; --j)
      if (dp[pos][j] >= i - n) pos = dp[pos][j];
    int vv = stp[i] - stp[pos], l = pos - (i - n);
    if (l) vv += l <= kk ? 1 : (l - kk + kk - 2) / (kk - 1) + 1;
    if (vv < mn) mn = vv, mnid = i;
  }
  for (int i = mnid; i > mnid - n; i = dp[i][0])
    if (dp[i][0] + 1 < i) solve(max(mnid - n, dp[i][0]) + 1, i);
  cout << ans.size() << endl;
  for (auto &i : ans) {
    for (auto &j : i) cout << j << ' ';
    cout << endl;
  }
  return 0;
}
