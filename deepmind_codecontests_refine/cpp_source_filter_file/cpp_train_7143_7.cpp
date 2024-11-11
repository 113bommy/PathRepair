#include <bits/stdc++.h>
using namespace std;
const int N = 3010, M = 400100;
int n, m, q, tot, tot_r, Next[N], head[N], tree[N], Next_r[N], head_r[N],
    tree_r[N], tot_q, Next_q[M], head_q[N], tree_q[M];
int num_q[M], id_q[M], f[N][18], Ans[M];
bool visit[N];
void add(int x, int y) {
  tot++;
  Next[tot] = head[x];
  head[x] = tot;
  tree[tot] = y;
}
void add_r(int x, int y) {
  tot_r++;
  Next_r[tot_r] = head_r[x];
  head_r[x] = tot_r;
  tree_r[tot_r] = y;
}
void add1(int x, int y, int z, int ID) {
  tot_q++;
  Next_q[tot_q] = head_q[x];
  head_q[x] = tot_q;
  tree_q[tot_q] = y;
  num_q[tot_q] = z;
  id_q[tot_q] = ID;
}
void dfs(int u) {
  visit[u] = true;
  for (int i = head_r[u]; i; i = Next_r[i])
    if (!visit[tree_r[i]]) dfs(tree_r[i]);
}
void pre(int u) {
  for (int i = 1; i <= n; i++) {
    if (u == i) {
      f[i][0] = 0;
      continue;
    }
    int Min = n + 1;
    for (int j = head[i]; j; j = Next[j]) {
      int v = tree[j];
      if (visit[v]) Min = min(Min, v);
    }
    if (Min == n + 1)
      f[i][0] = 0;
    else
      f[i][0] = Min;
  }
  for (int j = 1; j <= 15; j++)
    for (int i = 1; i <= n; i++) f[i][j] = f[f[i][j - 1]][j - 1];
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  tot = tot_r = 0;
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    add(x, y);
    add_r(y, x);
  }
  tot_q = 0;
  for (int i = 1; i <= q; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    add1(y, x, z, i);
  }
  for (int i = 1; i <= n; i++) {
    memset(visit, 0, sizeof(visit));
    memset(f, 0, sizeof(f));
    dfs(i);
    pre(i);
    for (int j = head_q[i]; j; j = Next_q[j]) {
      int u = tree_q[j], k = num_q[j], ID = id_q[j];
      if (!visit[u] || f[u][15] != 0) {
        Ans[ID] = -1;
        continue;
      }
      for (int l = 15; l >= 0; l--)
        if (k >= (1 << l)) {
          k -= 1 << l;
          u = f[u][l];
          if (k == 0) break;
        }
      Ans[ID] = (u) ? u : -1;
    }
  }
  for (int i = 1; i <= q; i++) printf("%d\n", Ans[i]);
  return 0;
}
