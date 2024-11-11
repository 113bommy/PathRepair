#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1e5 + 10, inf = 1e8;
int n, m;
vector<int> g[maxn];
int d[maxn][3];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0, u, v; i < m; ++i) {
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
  }
  int s, t;
  scanf("%d%d", &s, &t);
  for (int i = 1; i <= n; ++i) {
    d[i][0] = d[i][1] = d[i][2] = inf;
  }
  d[s][0] = 0;
  queue<pair<int, int>> q;
  q.emplace(s, 0);
  while (q.size()) {
    int x = q.front().first;
    int t = q.front().second;
    q.pop();
    for (int y : g[x]) {
      int &tmp = d[y][(t + 1) % 3];
      if (tmp == inf) {
        tmp = d[x][t] + 1;
        q.emplace(y, (t + 1) % 3);
      }
    }
  }
  printf("%d\n",  (d[t][0] != inf) ? d[t][0] / 3 : -1);
  return 0;
}

