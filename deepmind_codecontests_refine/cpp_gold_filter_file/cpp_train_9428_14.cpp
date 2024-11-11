#include <bits/stdc++.h>
using namespace std;
int read() {
  int w = 0, flg = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flg = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    w = w * 10 - '0' + ch, ch = getchar();
  }
  return w * flg;
}
int head[200010], ednum;
struct edge {
  int nxt, to;
} ed[200010 * 2];
void add_Edge(int u, int v) {
  ednum++;
  ed[ednum].nxt = head[u];
  ed[ednum].to = v;
  head[u] = ednum;
}
int n, p[200010][2], col[200010];
void dfs(int u, int val) {
  col[u] = val;
  for (int i = head[u]; i; i = ed[i].nxt) {
    int v = ed[i].to;
    if (!col[v]) dfs(v, 3 - val);
  }
}
int main() {
  n = read();
  for (int i = (1); i <= (n); i++)
    add_Edge(2 * i - 1, 2 * i), add_Edge(2 * i, 2 * i - 1);
  for (int i = (1); i <= (n); i++) {
    int u = read(), v = read();
    p[i][0] = u, p[i][1] = v;
    add_Edge(u, v);
    add_Edge(v, u);
  }
  for (int i = (1); i <= (2 * n); i++)
    if (!col[i]) dfs(i, 1);
  for (int i = (1); i <= (n); i++)
    printf("%d %d\n", col[p[i][0]], col[p[i][1]]);
  return 0;
}
