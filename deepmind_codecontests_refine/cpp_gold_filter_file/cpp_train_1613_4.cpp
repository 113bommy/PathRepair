#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int SIZE = 3 * 1e3 + 10;
int n, m;
vector<vector<int> > g;
int d[SIZE][SIZE];
int main() {
  if (0) {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
  }
  while (scanf("%d%d", &(n), &(m)) == 2) {
    g.clear();
    g.resize(n);
    for (int i = 0; i < (m); ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      u--, v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    int s1, t1, l1;
    scanf("%d%d%d", &s1, &t1, &l1);
    int s2, t2, l2;
    scanf("%d%d%d", &s2, &t2, &l2);
    s1--, t1--, s2--, t2--;
    for (int i = 0; i < (n); ++i) {
      queue<pair<int, int> > q;
      bitset<SIZE> vis;
      q.push(make_pair(i, 0));
      vis[i] = 1;
      while (((int)(q).size())) {
        pair<int, int> r = q.front();
        q.pop();
        int u = r.first;
        int co = r.second;
        d[i][u] = co;
        d[u][i] = co;
        for (int j = 0; j < (((int)(g[u]).size())); ++j) {
          int v = g[u][j];
          if (vis[v]) continue;
          q.push(make_pair(v, co + 1));
          vis[v] = 1;
        }
      }
    }
    if (d[s1][t1] > l1 || d[s2][t2] > l2)
      printf("-1\n");
    else {
      int ma = m - d[s1][t1] - d[s2][t2];
      for (int i = 0; i < (n); ++i)
        for (int j = 0; j < (n); ++j) {
          if (d[s1][i] + d[i][j] + d[j][t1] <= l1 &&
              d[i][s2] + d[i][j] + d[j][t2] <= l2)
            ma = max(ma,
                     m - d[s1][i] - d[i][j] - d[j][t1] - d[i][s2] - d[j][t2]);
          if (d[s1][i] + d[i][j] + d[j][t1] <= l1 &&
              d[i][t2] + d[i][j] + d[j][s2] <= l2)
            ma = max(ma,
                     m - d[s1][i] - d[i][j] - d[j][t1] - d[i][t2] - d[j][s2]);
        }
      printf("%d\n", ma);
    }
  }
  return 0;
}
