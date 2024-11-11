#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
int solve();
int main() {
  solve();
  return 0;
}
const int dd = (int)5e2 + 7;
const int inf = (int)1e9 + 7;
int RR[dd][dd][61][2];
vector<pair<int, int> > G[dd];
int Y[dd];
int solve() {
  int n, m, mm = 0;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int x, y, t;
    scanf("%d %d %d", &x, &y, &t);
    --x, --y;
    G[x].push_back(make_pair(y, t));
    mm += t;
  }
  if (mm == m) return 0 * puts("0");
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < (int)G[i].size(); ++j) {
      RR[i][G[i][j].first][0][G[i][j].second] = 1;
    }
  }
  for (int i = 0; i < n; ++i)
    if (RR[i][i][0][0] && RR[i][i][0][1]) return 0 * puts("-1");
  int k;
  for (k = 1; k < 61; ++k) {
    int ok = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (RR[i][j][k - 1][0])
          for (int q = 0; q < n; ++q) {
            if (RR[j][q][k - 1][1]) {
              RR[i][q][k][1] = 1;
              if (k & 1) ok = 0;
            }
          }
        if (RR[i][j][k - 1][1])
          for (int q = 0; q < n; ++q) {
            if (RR[j][q][k - 1][0]) {
              RR[i][q][k][0] = 1;
              if ((k & 1) == 0) ok = 0;
            }
          }
      }
    }
    for (int i = 0; i < n; ++i)
      if (RR[i][i][k][0] && RR[i][i][k][1]) return 0 * puts("-1");
    if (ok) break;
  }
  k--;
  int O = k & 1;
  vector<int> Q;
  long long ans = 0;
  for (int i = 0; i < n; ++i) Q.push_back(i);
  while (k != -1) {
    int cnt = 0;
    memset(Y, 0, sizeof Y);
    for (int i = 0; i < (int)Q.size(); ++i) {
      int x = Q[i];
      for (int j = 0; j < n; ++j) {
        if (RR[x][j][k][O]) Y[j] = 1, cnt++;
      }
    }
    if (cnt) {
      ans += (1ll << k);
      Q = vector<int>(0);
      for (int i = 0; i < n; ++i)
        if (Y[i]) Q.push_back(i);
    } else {
      O ^= 1;
    }
    k--;
  }
  printf("%I64d", ans > (long long)1e18 ? -1ll : ans);
  return 0;
}
