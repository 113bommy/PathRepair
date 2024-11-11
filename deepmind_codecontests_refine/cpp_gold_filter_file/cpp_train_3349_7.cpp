#include <bits/stdc++.h>
using namespace std;
int n, m, u, v;
int tot = 0;
int head[1000000 + 5];
struct node {
  int u, v, next, vis;
} edge[4000000 + 5];
void add(int u, int v) {
  edge[tot].u = u;
  edge[tot].v = v;
  edge[tot].vis = 0;
  edge[tot].next = head[u];
  head[u] = tot++;
}
int du[1000000 + 5];
int visp[1000000 + 5];
int top = 0;
int stk[4000000 + 5];
vector<pair<int, int>> que;
void dfs(int u) {
  visp[u]++;
  int id_now = visp[u];
  for (int i = head[u]; i != -1; i = edge[i].next) {
    head[u] = edge[i].next;
    if (edge[i].vis) continue;
    edge[i].vis = edge[i ^ 1].vis = 1;
    dfs(edge[i].v);
    if (visp[u] > id_now) break;
  }
  stk[top++] = u;
}
int main() {
  memset(head, -1, sizeof head);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &u, &v);
    add(u, v);
    add(v, u);
    du[u]++;
    du[v]++;
  }
  for (int i = 1; i <= n; i++)
    if (du[i] & 1) add(0, i), add(i, 0);
  for (int i = 1; i <= n; i++) {
    if (!visp[i]) {
      top = 0;
      dfs(i);
      for (int i = 0; i + 1 < top; i += 2)
        if (stk[i] && stk[i + 1]) que.push_back({stk[i], stk[i + 1]});
      for (int i = 1; i + 1 < top; i += 2) {
        int l = i - 1, r = (i + 2) % top;
        if (stk[i] && stk[i + 1]) {
          if (!(stk[l] && stk[i] && stk[i + 1] && stk[r]))
            que.push_back({stk[i], stk[i + 1]});
        }
      }
    }
  }
  printf("%d\n", que.size());
  for (auto x : que) printf("%d %d\n", x.first, x.second);
  return 0;
}
