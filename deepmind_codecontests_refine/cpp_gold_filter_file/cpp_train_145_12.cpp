#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct node {
  int v;
  node* next;
} E[N + N], *tot, *head[N];
int n, m, u, v, clk, dfn[N], cnt, ans[N][3];
void add(int u, int v) {
  tot->v = v;
  tot->next = head[u];
  head[u] = tot++;
}
void pc(int a, int b, int c) {
  ans[cnt][0] = a;
  ans[cnt][1] = b;
  ans[cnt][2] = c;
  ++cnt;
}
int dfs(int u) {
  int ret = 0;
  dfn[u] = ++clk;
  for (node* p = head[u]; p; p = p->next) {
    int v = p->v;
    if (!dfn[v]) {
      int w = dfs(v);
      if (w)
        pc(u, v, w);
      else {
        if (ret) {
          pc(v, u, ret);
          ret = 0;
        } else
          ret = v;
      }
    } else if (dfn[v] > dfn[u]) {
      if (ret) {
        pc(v, u, ret);
        ret = 0;
      } else
        ret = v;
    }
  }
  return ret;
}
void print() {
  for (int i = 0; i < cnt; ++i) {
    printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
  }
}
int main() {
  tot = E;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &u, &v);
    add(u, v);
    add(v, u);
  }
  if (m & 1)
    printf("No solution\n");
  else {
    dfs(1);
    print();
  }
  return 0;
}
