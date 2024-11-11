#include <bits/stdc++.h>
using namespace std;
int p[100005];
vector<int> g[100005];
int root(int a) { return p[a] == a ? a : (p[a] = root(p[a])); }
void merge(int a, int b) {
  a = root(a), b = root(b);
  if (a != b) p[a] = b;
}
int main() {
  int n, s;
  scanf("%d%d", &n, &s);
  for (int i = 1; i <= n; i++) p[i] = i;
  for (int i = 1; i <= n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    g[a].push_back(b);
    g[b].push_back(a);
  }
  if (n == 2) {
    printf("%.20Lf\n", (long double)s);
    return 0;
  }
  int mx = 0, idx = 0;
  for (int i = 1; i <= n; i++) {
    if (g[i].size() > mx) {
      mx = g[i].size();
      idx = i;
    }
  }
  long double ans = (long double)s / mx;
  priority_queue<pair<int, int> > pq;
  for (int i = 0; i < g[idx].size(); i++) {
    int v = g[idx][i];
    if (g[v].size() != 1)
      pq.push(pair<int, int>(g[v].size(), v)), merge(idx, v);
  }
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    mx += g[u].size();
    mx -= 2;
    ans = min(ans, (long double)s / mx);
    for (int i = 0; i < g[u].size(); i++) {
      int v = g[idx][i];
      if (g[v].size() != 1 && root(v) != root(u))
        pq.push(pair<int, int>(g[v].size(), v)), merge(u, v);
    }
  }
  printf("%.20Lf\n", ans * 2);
}
