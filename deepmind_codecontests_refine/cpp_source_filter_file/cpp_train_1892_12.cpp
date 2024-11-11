#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[30][30];
vector<int> mnr, mnc, mxr, mxc;
bool check() {
  for (int i = (0); i <= (k); ++i) {
    if (mxr[i] == 0 && mxc[i] == 0 && mnr[i] == 1000000000 &&
        mnc[i] == 1000000000) {
      mnr[i] = mnr[k];
      mnc[i] = mnc[k];
      mxr[i] = mxr[k];
      mxc[i] = mxc[k];
    }
    if (mnr[i] != mxr[i] && mnc[i] != mxc[i]) return 0;
    for (int r = (mnr[i]); r <= (mxr[i]); ++r)
      for (int c = (mnc[i]); c <= (mxc[i]); ++c) {
        if (a[r][c] < i || a[r][c] == -1) return 0;
      }
  }
  return 1;
}
void solve() {
  mnr = vector<int>(26, 1000000000);
  mnc = vector<int>(26, 1000000000);
  mxr = vector<int>(26);
  mxc = vector<int>(26);
  cin >> n >> m;
  char c;
  k = -1;
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (m); ++j) {
      cin >> c;
      if ('a' <= c && c <= 'z') {
        a[i][j] = c - 'a';
        k = max(k, a[i][j]);
      } else
        a[i][j] = -1;
      int x = a[i][j];
      mnr[x] = min(mnr[x], i);
      mxr[x] = max(mxr[x], i);
      mnc[x] = min(mnc[x], j);
      mxc[x] = max(mxc[x], j);
    }
  if (check()) {
    cout << "YES\n";
    cout << k + 1 << '\n';
    for (int i = (0); i <= (k); ++i)
      cout << mnr[i] << ' ' << mnc[i] << ' ' << mxr[i] << ' ' << mxc[i] << '\n';
  } else
    cout << "NO\n";
}
int main() {
  if (0) {
    freopen("CP.inp", "r", stdin);
    freopen("CP.out", "w", stdout);
  }
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
