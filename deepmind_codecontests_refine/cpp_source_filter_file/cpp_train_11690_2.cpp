#include <bits/stdc++.h>
using namespace std;
int n, m, s, l, u[100001], v[100001], w[100001], ans;
int flag[100001], d[100001];
vector<pair<int, int> > E[100001];
void Dijkstra() {
  priority_queue<pair<int, int>, vector<pair<int, int> >,
                 greater<pair<int, int> > >
      Q;
  for (int i = 1; i <= n; i++) d[i] = (1 << 29), flag[i] = 0;
  d[s] = 0;
  Q.push(pair<int, int>(d[s], s));
  while (!Q.empty()) {
    int u = Q.top().second;
    Q.pop();
    if (flag[u]) continue;
    flag[u] = 1;
    for (int i = 0; i < E[u].size(); i++)
      if (!flag[E[u][i].first]) {
        int v = E[u][i].first, w = E[u][i].second;
        if (d[u] + w < d[v]) {
          d[v] = d[u] + w;
          Q.push(pair<int, int>(d[v], v));
        }
      }
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &s);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &u[i], &v[i], &w[i]);
    E[u[i]].push_back(pair<int, int>(v[i], w[i]));
    E[v[i]].push_back(pair<int, int>(u[i], w[i]));
  }
  scanf("%d", &l);
  Dijkstra();
  for (int i = 1; i <= n; i++)
    if (d[i] == l) ans++;
  for (int i = 1; i <= m; i++) {
    int a = d[u[i]], b = d[v[i]];
    int x = (b - a + w[i]);
    if (x <= 0) {
      if (a < l && a + w[i] > l) ans++;
    } else if (x >= 2 * w[i]) {
      if (b < l && b + w[i] > l) ans++;
    } else {
      if (a < l && 2 * a + x >= 2 * l) ans++;
      if (b < l && 2 * b + 2 * w[i] - x >= 2 * l) ans++;
      if (a < l && b < l && 2 * a + x == 2 * l && 2 * b + 2 * w[i] - x == 2 * l)
        ans--;
    }
  }
  printf("%d", ans);
  return 0;
}
