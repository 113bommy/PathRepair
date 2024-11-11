#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
const int N = 1e6 + 10;
const long long mod = 1e9 + 7;
const long long mod2 = 998244353;
const long long inf = 8e18;
const int LOG = 22;
const int B = 550;
long long pw(long long a, long long b, long long M) {
  return (!b ? 1
             : (b & 1 ? (a * pw(a * a % M, b / 2, M)) % M
                      : pw(a * a % M, b / 2, M)));
}
int n, m, check[N], P[N];
vector<int> path[N];
vector<pair<int, int> > vec[N];
bool solve() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i <= m; i++) path[i].clear();
  for (int i = 0; i <= n; i++) check[i] = P[i] = -1, vec[i].clear();
  for (int i = 1; i <= m; i++) {
    int sz;
    scanf("%d", &sz);
    for (int j = 0; j < sz; j++) {
      int x;
      scanf("%d", &x);
      path[i].push_back(x);
    }
  }
  for (int i = 1; i <= m; i++) {
    if ((int)path[i].size() >= B) {
      for (int i2 = 0; i2 < (int)path[i].size(); i2++) {
        P[path[i][i2]] = i2;
      }
      for (int j = 1; j <= m; j++) {
        if (i == j) continue;
        int Mx = -1;
        for (int t = (int)path[j].size() - 1; ~t; t--) {
          if (P[path[j][t]] != -1) {
            if (Mx > P[path[j][t]] &&
                path[i][P[path[j][t]] + 1] != path[j][t + 1]) {
              return !printf("Human");
            }
          }
          Mx = max(Mx, P[path[j][t]]);
        }
      }
      for (int i2 = 0; i2 < (int)path[i].size(); i2++) {
        P[path[i][i2]] = -1;
      }
    } else {
      for (int i2 = 0; i2 < (int)path[i].size(); i2++) {
        for (int i3 = i2 + 1; i3 < (int)path[i].size(); i3++) {
          vec[path[i][i2]].push_back(make_pair(path[i][i3], path[i][i2 + 1]));
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (auto x : vec[i]) {
      if (check[x.first] == -1) check[x.first] = x.second;
      if (check[x.first] != x.second) return !printf("Human");
    }
    for (auto x : vec[i]) check[x.first] = -1;
  }
  return !printf("Robot");
}
int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    solve();
  }
  return 0;
}
