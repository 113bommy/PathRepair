#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int maxm = 4e5 + 5;
struct edge {
  int u, v, next;
} E[maxm];
int head[maxn];
int tot = -1;
void addedge(int u, int v) {
  E[++tot].u = u;
  E[tot].v = v;
  E[tot].next = head[u];
  head[u] = tot;
}
int edgevis[maxm];
int vertexvis[maxn];
int fa[maxn], pre[maxn];
struct Ans {
  int a, b, c;
} ans[maxm >> 1];
int anstot = 0;
void addans(int a, int b, int c) {
  ans[++anstot].a = a;
  ans[anstot].b = b;
  ans[anstot].c = c;
}
void dfs(int u) {
  vertexvis[u] = 1;
  for (int i = head[u]; i >= 0; i = E[i].next) {
    int v = E[i].v;
    if (!vertexvis[v]) {
      fa[v] = u;
      pre[v] = i;
      dfs(v);
    }
  }
  vector<int> ez;
  for (int i = head[u]; i >= 0; i = E[i].next) {
    if (edgevis[i]) continue;
    int v = E[i].v;
    if (fa[u] != v) {
      ez.push_back(i);
    }
  }
  for (int i = 0; i + 1 < ez.size(); i += 2) {
    addans(E[ez[i]].v, u, E[ez[i + 1]].v);
    edgevis[ez[i]] = edgevis[ez[i] ^ 1] = 1;
    edgevis[ez[i + 1]] = edgevis[ez[i + 1] ^ 1] = 1;
  }
  if ((ez.size() & 1) && fa[u]) {
    addans(E[ez.back()].v, u, fa[u]);
    edgevis[ez.back()] = edgevis[ez.back() ^ 1] = 1;
    edgevis[pre[u]] = edgevis[pre[u] ^ 1] = 1;
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  fill(head, head + 1 + n, -1);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    addedge(u, v);
    addedge(v, u);
  }
  for (int i = 1; i <= n; i++) {
    if (!vertexvis[i]) dfs(1);
  }
  printf("%d\n", anstot);
  for (int i = 1; i <= anstot; i++) {
    printf("%d %d %d\n", ans[i].a, ans[i].b, ans[i].c);
  }
}
