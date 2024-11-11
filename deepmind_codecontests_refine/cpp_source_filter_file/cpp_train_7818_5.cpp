#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const int INF = 1 << 30;
int A[5010][5010];
vector<pair<int, int> > Ans[1000];
int P[1000];
int main() {
  int n, m;
  cin >> n >> m;
  int d = 0;
  for (int i = 1; i <= n; ++i) {
    ++d;
    A[d][d] = i;
    P[i] = d;
  }
  while (m--) {
    int u, v;
    cin >> u >> v;
    if (u > v) swap(u, v);
    ++d;
    A[d][d] = u;
    if (P[u]) {
      int d1 = P[u];
      A[d1][d] = u;
    }
    if (P[v]) {
      int d1 = P[v];
      A[d1][d] = u;
    }
  }
  for (int i = 1; i <= d; ++i) {
    for (int j = 1; j <= d; ++j) {
      int t = A[i][j];
      if (t) {
        Ans[t].push_back(make_pair(i, j));
      }
    }
  }
  for (int k = 1; k <= n; ++k) {
    int c = Ans[k].size();
    printf("%d\n", c);
    for (int i = 0; i < c; ++i) {
      int u = Ans[k][i].first;
      int v = Ans[k][i].second;
      printf("%d %d\n", u, v);
    }
  }
  return 0;
}
