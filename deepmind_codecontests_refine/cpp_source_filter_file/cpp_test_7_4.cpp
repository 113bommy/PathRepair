#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;
void solve() {
  int n, m;
  cin >> n >> m;
  vvi dp(m, vi(n - m + 2, -1));
  string a, b;
  cin >> a >> b;
  dp[0][0] = 0;
  vector<array<int, 2>> nxt(m + 1, array<int, 2>{0, 0});
  vi p(m);
  {
    for (int i = 1; i < m; ++i) {
      p[i] = p[i - 1];
      while (p[i] && b[p[i]] != b[i]) p[i] = p[p[i]];
      if (b[p[i]] == b[i]) p[i]++;
    }
    for (int i = 0; i < (m + 1); ++i) {
      nxt[i][0] = nxt[i][1] = 0;
      if (b[i] == '1') {
        nxt[i][1] = i + 1;
        if (i) nxt[i][0] = nxt[p[i - 1]][0];
      } else {
        nxt[i][0] = i + 1;
        if (i) nxt[i][1] = nxt[p[i - 1]][1];
      }
    }
  }
  for (int i = 0; i < (n); ++i) {
    vvi dp2(m, vi(n - m + 2, -1));
    for (int pref = 0; pref < (m); ++pref) {
      for (int occs = 0; occs < (n - m + 2); ++occs) {
        for (int x = 0; x < (2); ++x) {
          int value = dp[pref][occs];
          if (value == -1) continue;
          if (x != (a[i] - '0')) value++;
          int pref2 = nxt[pref][x];
          int occs2 = occs;
          if (pref2 == m) {
            occs2++;
            pref2 = p[m - 1];
          }
          if (occs2 > n - m + 1) continue;
          if (dp2[pref2][occs2] == -1 || dp2[pref2][occs2] > value) {
            dp2[pref2][occs2] = value;
          }
        }
      }
    }
    swap(dp, dp2);
  }
  for (int i = 0; i < (n - m + 2); ++i) {
    int mn = -1;
    for (int j = 0; j < (m); ++j) {
      if (dp[j][i] == -1) continue;
      if (mn == -1 || dp[j][i] < mn) mn = dp[j][i];
    }
    cout << mn << ' ';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  for (int i = 0; i < (t); ++i) {
    solve();
  }
  return 0;
}
