#include <bits/stdc++.h>
using namespace std;
int du[101000];
int Next[201000], head[101000], edge[201000], tot;
void Insert(int u, int v) {
  edge[tot] = v;
  Next[tot] = head[u];
  head[u] = tot++;
}
int pos = 0;
int bianxu[201000];
bool pd[101000];
void dfs(int u) {
  pd[u] = true;
  for (int i = head[u]; ~i; i = Next[i]) {
    int v = edge[i];
    if (!pd[v]) {
      printf("2 %d %d\n", u, v);
      bianxu[i] = ++pos;
      dfs(v);
    }
  }
}
void dfs1(int u, int op) {
  pd[u] = true;
  for (int i = head[u]; ~i; i = Next[i]) {
    int v = edge[i];
    if (!pd[v]) {
      if (~op) printf("%d %d\n", bianxu[op], bianxu[i]);
      dfs1(v, i);
    }
  }
}
int main() {
  int n;
  while (~scanf("%d", &n)) {
    memset(du, 0, sizeof(du));
    memset(head, -1, sizeof(head));
    memset(pd, 0, sizeof(pd));
    tot = 0;
    pos = 0;
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      Insert(u, v);
      Insert(v, u);
      ++du[u];
      ++du[v];
    }
    int ans;
    printf("%d\n", n - 1);
    for (int i = 1; i <= n; ++i)
      if (du[i] == 1) {
        dfs(i);
        ans = i;
        break;
      }
    memset(pd, 0, sizeof(pd));
    dfs1(ans, -1);
  }
  return 0;
}
