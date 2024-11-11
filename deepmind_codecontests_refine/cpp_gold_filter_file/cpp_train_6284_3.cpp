#include <bits/stdc++.h>
const double EPS = 1e-9;
const double PI = acos(-1.0);
using namespace std;
vector<int> g[100500];
int n, m;
int h, t;
int deg[100500];
vector<pair<int, int> > e;
bool used[100500];
bool is(int v, int u) {
  int id = lower_bound(g[v].begin(), g[v].end(), u) - g[v].begin();
  return id != ((int)(g[v]).size()) && g[v][id] == u;
}
int main() {
  cin >> n >> m >> h >> t;
  memset(deg, 0, sizeof deg);
  for (int i = 0; i < (int)m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    e.push_back(make_pair(a, b));
    e.push_back(make_pair(b, a));
    deg[a]++;
    deg[b]++;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int i = 0; i < (int)n; i++) sort(g[i].begin(), g[i].end());
  for (int i = 0; i < (int)((int)(e).size()); i++) {
    int a = e[i].first;
    int b = e[i].second;
    int dega = deg[a] - 1;
    int degb = deg[b] - 1;
    if (dega < h || degb < t) continue;
    int deg = 0;
    for (int k = 0; k < (int)((int)(g[b]).size()); k++) {
      int v = g[b][k];
      if (is(v, a)) deg++;
    }
    if (h + t <= dega + degb - deg) {
      memset(used, 0, sizeof used);
      puts("YES");
      printf("%d %d\n", a + 1, b + 1);
      for (int k = 0; k < (int)((int)(g[a]).size()); k++) {
        if (h == 0) break;
        int v = g[a][k];
        if (v == b) continue;
        if (is(v, b)) continue;
        printf("%d ", v + 1);
        h--;
        used[v] = 1;
      }
      for (int k = 0; k < (int)((int)(g[a]).size()); k++) {
        if (h == 0) break;
        int v = g[a][k];
        if (v == b) continue;
        if (used[v]) continue;
        printf("%d ", v + 1);
        h--;
        used[v] = 1;
      }
      puts("");
      for (int k = 0; k < (int)((int)(g[b]).size()); k++) {
        int v = g[b][k];
        if (v == a) continue;
        if (used[v]) continue;
        printf("%d ", v + 1);
        t--;
        if (t == 0) break;
      }
      return 0;
    }
  }
  puts("NO");
  return 0;
}
