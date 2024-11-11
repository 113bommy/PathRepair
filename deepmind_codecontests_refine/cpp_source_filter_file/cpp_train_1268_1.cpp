#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int cnt;
vector<int> ans;
struct node {
  int v, nxt;
} edge[N];
int head[N];
void add(int u, int v) {
  edge[cnt].v = v;
  edge[cnt].nxt = head[u];
  head[u] = cnt++;
}
int L[N], R[N];
int dfn[N], sta[N], low[N], vis[N], col[N];
int top, tot;
void Tarjan(int p) {
  dfn[p] = low[p] = ++tot;
  sta[++top] = p;
  vis[p] = 1;
  for (int i = head[p]; i != -1; i = edge[i].nxt) {
    int q = edge[i].v;
    if (!dfn[q]) {
      Tarjan(q);
      low[p] = min(low[p], dfn[q]);
    } else if (vis[q]) {
      low[p] = min(low[p], dfn[q]);
    }
  }
  if (low[p] == dfn[p]) {
    tot++;
    int q;
    do {
      q = sta[top--];
      col[q] = tot;
      vis[q] = 0;
    } while (q != p);
  }
}
int main() {
  int n, p, m, M;
  scanf("%d%d%d%d", &n, &p, &M, &m);
  memset(head, -1, sizeof head);
  for (int i = 1; i <= n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    add(p + u, v);
    add(p + v, u);
  }
  int t = 2 * p;
  for (int i = 1; i <= p; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    L[i] = l, R[i] = r;
    add(i, t + r + 1);
    add(t + r + 1 + M, i + p);
    add(t + l, i + p);
    add(i, t + l + M);
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    add(u, v + p);
    add(v, u + p);
  }
  for (int i = 1; i < M; i++) {
    add(t + i, t + i + 1);
    add(t + i + 1 + M, t + i + M);
  }
  for (int i = 1; i <= t + 2 * M; i++) {
    if (!dfn[i]) Tarjan(i);
  }
  int f = 0;
  for (int i = 1; i <= p; i++) {
    if (col[i] == col[i + p]) {
      puts("-1");
      return 0;
    } else if (col[i] < col[i + p]) {
      ans.push_back(i);
      f = max(L[i], f);
    }
  }
  printf("%d %d\n", ans.size(), f);
  for (auto it : ans) {
    printf("%d ", it);
  }
  puts("");
  return 0;
}
