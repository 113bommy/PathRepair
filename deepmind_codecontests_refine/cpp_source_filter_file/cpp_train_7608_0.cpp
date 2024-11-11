#include <bits/stdc++.h>
using namespace std;
vector<vector<array<int, 2>>> vals(4100);
int ans[4100][100];
int Hash(string &s) {
  int ret = 0;
  for (auto c : s) {
    ret <<= 1;
    if (c == '1') ++ret;
  }
  return ret;
}
int findpos(vector<array<int, 2>> &v, int k) {
  if (v[0][0] > k) return 0;
  int l = 0, r = v.size();
  --r;
  while (l < r) {
    int m = (l + r + 1) / 2;
    if (v[m][0] > k)
      r = m - 1;
    else
      l = m;
  }
  return v[l][0] > k ? v[l - 1][1] : v[l][1];
}
int main(void) {
  memset(ans, -1, sizeof ans);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  int w[n];
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
  }
  int lim = pow(2, n);
  int ct[lim];
  memset(ct, 0, sizeof ct);
  int wu[lim];
  memset(wu, 0, sizeof wu);
  for (int i = 0; i < m; ++i) {
    string s;
    cin >> s;
    int h = Hash(s);
    ++ct[h];
  }
  for (int i = 0; i < lim; ++i) {
    int t = i;
    for (int k = n - 1; k >= 0; --k) {
      if (!(t & 1)) wu[i] += w[k];
      t >>= 1;
    }
  }
  for (int i = 0; i < lim; ++i) {
    for (int j = 0; j < lim; ++j) {
      if (!ct[j]) continue;
      vals[i].push_back({wu[i ^ j], ct[j]});
    }
    sort(vals[i].begin(), vals[i].end());
    int N = vals[i].size();
    for (int j = 1; j < N; ++j) {
      vals[i][j][1] += vals[i][j - 1][1];
    }
  }
  while (q--) {
    string s;
    cin >> s;
    int h = Hash(s);
    int k;
    cin >> k;
    if (ans[h][k] == -1) ans[h][k] = findpos(vals[h], k);
    cout << ans[h][k] << '\n';
  }
}
