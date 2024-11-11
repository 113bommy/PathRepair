#include <bits/stdc++.h>
using namespace std;
struct node {
  int v, next;
} ed[100005];
int n, m, ans, num;
int parent[100005], head[100005], dis[100005], vis[100005];
void addedge(int u, int v) {
  ed[num].v = v;
  ed[num].next = head[u];
  head[u] = num++;
}
int gcd(int a, int b) {
  int i;
  while (b) {
    i = a % b;
    a = b;
    b = i;
  }
  return a;
}
int abs(int a) { return a >= 0 ? a : -a; }
int Find(int x) {
  if (x != parent[x]) {
    int tp = parent[x];
    parent[x] = Find(tp);
    dis[x] = dis[tp] + dis[x];
  }
  return parent[x];
}
void dfs(int x, int root) {
  int i, j, k;
  vis[x] = 1;
  for (i = head[x]; i != -1; i = ed[i].next) {
    j = ed[i].v;
    if (vis[j]) {
      k = Find(j);
      Find(x);
      if (root != k) {
        parent[k] = root;
        dis[k] = dis[x] + 1 - dis[j];
      } else {
        if (dis[j] - dis[x] - 1) {
          if (ans == n + 1)
            ans = abs(dis[j] - dis[x] - 1);
          else
            ans = gcd(ans, abs(dis[j] - dis[x] - 1));
        }
      }
      continue;
    }
    dis[j] = 1;
    parent[j] = x;
    dfs(j, root);
  }
}
int main() {
  int u, v;
  scanf("%d%d", &n, &m);
  memset(head, -1, sizeof(head));
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &u, &v);
    addedge(u, v);
  }
  for (int i = 1; i <= n; i++) parent[i] = i;
  ans = n + 1;
  for (int i = 1; i <= n; i++)
    if (!vis[i]) dfs(i, i);
  if (ans == n + 1) ans = n;
  printf("%d\n", ans);
  return 0;
}
