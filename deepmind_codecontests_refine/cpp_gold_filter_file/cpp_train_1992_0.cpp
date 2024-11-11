#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int INF = 99999999;
const double eps = 1e-6;
const int maxn = 1e5 + 5;
int cur, a, b;
int n, m, cnt;
bool vis[maxn];
struct Edge {
  int v, nxt;
} edge[maxn << 1];
int head[maxn], res[maxn];
void addEdge(int u, int v) {
  edge[++cnt].v = v;
  edge[cnt].nxt = head[u];
  head[u] = cnt;
}
void solve() {
  priority_queue<int, vector<int>, greater<int> > q;
  q.push(1);
  while (!q.empty()) {
    int u = q.top();
    printf("%d ", u);
    vis[u] = true;
    q.pop();
    for (int i = head[u]; i; i = edge[i].nxt) {
      if (!vis[edge[i].v]) {
        q.push(edge[i].v);
        vis[edge[i].v] = true;
      }
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  while (m--) {
    scanf("%d%d", &a, &b);
    addEdge(a, b);
    addEdge(b, a);
  }
  solve();
  return 0;
}
