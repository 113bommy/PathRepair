#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10000000];
int ans[1000000];
int dsu[1000000];
bool vis[1000000];
pair<int, int> DFS(int n, int dis, int par) {
  pair<int, int> u = make_pair(dis, n);
  for (int i = 0; i < adj[n].size(); i++) {
    if (par != adj[n][i]) u = max(DFS(adj[n][i], dis + 1, n), u);
  }
  return u;
}
int findd(int a) {
  if (dsu[a] == a) return a;
  return dsu[a] = findd(dsu[a]);
}
void mergee(int u, int v) {
  int x = findd(u);
  int y = findd(v);
  if (x == y) return;
  int d = max((int)(ceil(ans[x] / 2.0) + ceil(ans[y] / 2.0) + 1),
              max(ans[x], ans[y]));
  dsu[x] = dsu[y];
  ans[dsu[y]] = d;
}
int funt(int n) {
  if (ans[n] != -1) return ans[n];
  pair<int, int> x = DFS(findd(n), 0, findd(n));
  ans[n] = DFS(x.second, 0, x.second).first;
  return ans[n];
}
int main() {
  memset(ans, -1, sizeof(ans));
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++) dsu[i] = i;
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
    dsu[findd(b)] = findd(a);
  }
  for (int i = 1; i <= n; i++) {
    ans[i] = funt(findd(i));
  }
  for (int i = 0; i < q; i++) {
    int c, x, y;
    scanf("%d", &c);
    if (c == 1) {
      scanf("%d", &x);
      printf("%d\n", ans[findd(x)]);
    } else {
      scanf("%d%d", &x, &y);
      mergee(x, y);
    }
  }
  return 0;
}
