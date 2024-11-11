#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int CNTV = 105;
const int LENSUFF = 11;
const int K = 4;
const int MOD = 1e9 + 7;
struct node {
  int go[K], suff, p, pch, lev, cr;
  node() {
    memset(go, -1, sizeof go);
    suff = p = pch = cr = -1;
    lev = 0;
  }
};
int sz = 1, num[256];
node a[CNTV];
inline void add(string second) {
  int v = 0;
  for (int i = 0; i < second.size(); ++i) {
    int c = num[second[i]];
    if (a[v].go[c] == -1) {
      a[sz].lev = a[v].lev + 1;
      a[sz].p = v;
      a[sz].pch = c;
      a[v].go[c] = sz++;
    }
    v = a[v].go[c];
  }
  a[v].cr = v;
}
int go(int v, int c);
int sufflink(int v);
int go(int v, int c) {
  if (a[v].go[c] != -1) return a[v].go[c];
  if (v == 0) return a[v].go[c] = 0;
  return a[v].go[c] = go(sufflink(v), c);
}
int sufflink(int v) {
  if (v == 0 || a[v].p == 0) return a[v].suff = 0;
  if (a[v].suff != -1) return a[v].suff;
  return a[v].suff = go(sufflink(a[v].p), a[v].pch);
}
int cross(int v) {
  if (a[v].cr != -1) return a[v].cr;
  return a[v].cr = cross(sufflink(v));
}
int n, m, dp[N][CNTV][LENSUFF];
int main() {
  num['A'] = 0;
  num['C'] = 1;
  num['G'] = 2;
  num['T'] = 3;
  a[0].cr = 0;
  cin >> n >> m;
  string second;
  for (int i = 0; i < m; ++i) {
    cin >> second;
    add(second);
  }
  dp[0][0][0] = 1;
  for (int len = 0; len < n; ++len)
    for (int v = 0; v < sz; ++v)
      for (int need = 0; need < 10; ++need)
        for (int c = 0; c < 4; ++c) {
          int to = go(v, c);
          if (a[to].lev >= need + 1) {
            int cr = cross(to);
            if (a[cr].lev >= need + 1)
              dp[len + 1][to][0] =
                  (dp[len + 1][to][0] + dp[len][v][need]) % MOD;
            else
              dp[len + 1][to][need + 1] =
                  (dp[len + 1][to][need + 1] + dp[len][v][need]) % MOD;
          }
        }
  int ans = 0;
  for (int v = 0; v < sz; ++v) ans = (ans + dp[n][v][0]) % MOD;
  cout << ans;
  return 0;
}
