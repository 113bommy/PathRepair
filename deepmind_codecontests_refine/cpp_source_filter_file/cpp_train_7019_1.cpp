#include <bits/stdc++.h>
using namespace std;
double PI = 3.141592653589793;
const int mx = 1e5 + 1, bmx = 17;
long long tree[4 * mx][bmx] = {};
int suf[4 * mx][bmx] = {}, pre[4 * mx][bmx] = {};
int n;
void update(int i, int j, int l, int r) {
  tree[i][j] = tree[i << 1][j] + tree[(i << 1) | 1][j] +
               suf[(i << 1)][j] * pre[(i << 1) | 1][j];
  int md = (l + r) >> 1;
  suf[i][j] = suf[(i << 1) | 1][j];
  if (suf[i][j] == (r - md)) suf[i][j] += suf[i << 1][j];
  pre[i][j] = pre[i << 1][j];
  if (pre[i][j] == (md - l + 1)) pre[i][j] += pre[(i << 1) | 1][j];
}
void upd(int ind, int j, int val, int i = 1, int l = 0, int r = n - 1) {
  if (l == r) {
    tree[i][j] = val;
    if (val)
      suf[i][j] = pre[i][j] = 1;
    else
      suf[i][j] = pre[i][j] = 0;
    return;
  }
  int md = (l + r) >> 1;
  if (ind <= md)
    upd(ind, j, val, i << 1, l, md);
  else
    upd(ind, j, val, (i << 1) | 1, md + 1, r);
  update(i, j, l, r);
}
void solve() {
  int q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < 1; j++) {
      if (k & (1 << j))
        upd(i, j, 1);
      else
        upd(i, j, 0);
    }
  }
  while (q--) {
    int p, v;
    cin >> p >> v;
    p--;
    for (int j = 0; j < bmx; j++) {
      if (v & (1 << j))
        upd(p, j, 1);
      else
        upd(p, j, 0);
    }
    long long ans = 0;
    for (int i = 0; i < bmx; i++) ans += tree[1][i] * (1ll << i);
    cout << ans << '\n';
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  for (int c = 1; c < T + 1; c++) {
    solve();
  }
}
