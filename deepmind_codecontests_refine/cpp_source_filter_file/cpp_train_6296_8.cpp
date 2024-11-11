#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int x = 0;
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}
struct node {
  int nxt, to;
} edge[400005 << 1];
int head[100005], d[100005];
bool vis[400005 << 1];
int n, m, tot, pos;
inline void add(int u, int v) {
  edge[++tot].nxt = head[u];
  edge[tot].to = v;
  head[u] = tot;
}
inline void addedge(int u, int v) { d[u]++, d[v]++, add(u, v), add(v, u); }
void dfs(int u) {
  for (int &i = head[u]; i; i = edge[i].nxt) {
    if (!vis[i]) {
      int v = edge[i].to;
      vis[i] = vis[i ^ 1] = true;
      dfs(v);
      if ((++pos) & 1)
        printf("%d %d\n", u, v);
      else
        printf("%d %d\n", v, u);
    }
  }
}
int main(void) {
  n = read(), m = read();
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read();
    addedge(u, v);
  }
  vector<int> q;
  for (int i = 1; i <= n; i++)
    if (d[i] & 1) q.push_back(i);
  for (int i = 0; i < q.size(); i += 2) addedge(q[i], q[i + 1]), m++;
  if (m & 1) m++, addedge(1, 1);
  printf("%d\n", m);
  dfs(1);
  return 0;
}
