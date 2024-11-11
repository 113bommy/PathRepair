#include <bits/stdc++.h>
const int N = 300010, MO = 998244353;
struct Edge {
  int nex, v, len;
};
int n, m, col[N], pw[N << 1], fr[N], imp[N], K, stk[N], top, f[N], h[N];
std::vector<int> v[N];
inline void ERR() {
  puts("0");
  exit(0);
  return;
}
struct G {
  Edge edge[N << 1];
  int tp;
  int e[N], d[N], fa[N], pos[N], num, ST[N << 1][20];
  G() {}
  inline void add(int x, int y, int z = 0) {
    edge[++tp].v = y;
    edge[tp].len = z;
    edge[tp].nex = e[x];
    e[x] = tp;
    return;
  }
  void DFS_1(int x, int f) {
    d[x] = d[f] + 1;
    fa[x] = f;
    pos[x] = ++num;
    ST[num][0] = x;
    for (int i = e[x]; i; i = edge[i].nex) {
      int y = edge[i].v;
      if (y == f) continue;
      DFS_1(y, x);
      ST[++num][0] = x;
    }
    return;
  }
  inline void pre1(int x = 1) {
    DFS_1(x, 0);
    return;
  }
  inline void lcapre() {
    for (int j = 1; j <= pw[num]; j++) {
      for (int i = 1; i + (1 << j) - 1 <= num; i++) {
        if (d[ST[i][j - 1]] < d[ST[i + (1 << (j - 1))][j - 1]]) {
          ST[i][j] = ST[i][j - 1];
        } else {
          ST[i][j] = ST[i + (1 << (j - 1))][j - 1];
        }
      }
    }
    return;
  }
  inline int lca(int x, int y) {
    x = pos[x];
    y = pos[y];
    if (x > y) std::swap(x, y);
    int t = pw[y - x + 1];
    if (d[ST[x][t]] < d[ST[y - (1 << t) + 1][t]]) {
      return ST[x][t];
    } else {
      return ST[y - (1 << t) + 1][t];
    }
  }
  int recol(int x) {
    int Col = 0;
    for (int i = e[x]; i; i = edge[i].nex) {
      int y = edge[i].v;
      if (y == fa[x]) {
        continue;
      }
      int c = recol(y);
      if (c && Col && c != Col) {
        ERR();
      }
      if (c && !Col) {
        Col = c;
      }
    }
    if (col[x]) {
      if (Col && col[x] != Col) {
        ERR();
      } else {
        Col = col[x];
      }
    }
    col[x] = Col;
    if (fr[x]) {
      Col = 0;
    }
    return Col;
  }
  inline int build_t(G &gr) {
    stk[top = 1] = imp[1];
    for (int i = 2; i <= K; i++) {
      int x = imp[i], y = lca(x, stk[top]);
      while (top > 1 && pos[y] <= pos[stk[top - 1]]) {
        gr.add(stk[top - 1], stk[top], d[stk[top]] - d[stk[top - 1]]);
        top--;
      }
      if (y != stk[top]) {
        gr.add(y, stk[top], d[stk[top]] - d[y]);
        stk[top] = y;
      }
      stk[++top] = x;
    }
    while (top > 1) {
      gr.add(stk[top - 1], stk[top], d[stk[top]] - d[stk[top - 1]]);
      top--;
    }
    return stk[top];
  }
  int cal(int x) {
    int ans = 1;
    for (int i = e[x]; i; i = edge[i].nex) {
      int y = edge[i].v;
      int t = cal(y);
      ans = 1ll * ans * t % MO * edge[i].len % MO;
    }
    return ans;
  }
  void DP(int x, int father) {
    f[x] = col[x] ? 1 : 0;
    h[x] = col[x] ? 0 : 1;
    for (int i = e[x]; i; i = edge[i].nex) {
      int y = edge[i].v;
      if (y == father) continue;
      DP(y, x);
      int t, t2;
      t = 1ll * f[x] * (f[y] + h[y]) % MO + f[y] * h[x] % MO;
      t2 = 1ll * h[x] * (h[y] + f[y]) % MO;
      f[x] = t % MO;
      h[x] = t2;
    }
    return;
  }
} g[3];
inline bool cmp(const int &a, const int &b) {
  return g[1].pos[a] < g[1].pos[b];
}
void out(int x, G &gr) {
  for (int i = gr.e[x]; i; i = gr.edge[i].nex) {
    int y = gr.edge[i].v;
    if (y == gr.fa[x]) continue;
    out(y, gr);
  }
  return;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 2; i <= n * 2; i++) pw[i] = pw[i >> 1] + 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &col[i]);
    if (col[i]) {
      v[col[i]].push_back(i);
    }
  }
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    g[0].add(x, y);
    g[0].add(y, x);
  }
  g[0].pre1();
  g[0].lcapre();
  for (int i = 1; i <= m; i++) {
    int len = v[i].size(), x = v[i][0];
    for (int j = 1; j < len; j++) {
      x = g[0].lca(x, v[i][j]);
    }
    fr[x] = i;
  }
  g[0].recol(1);
  for (int x = 1; x <= n; x++) {
    for (int i = g[0].e[x]; i; i = g[0].edge[i].nex) {
      int y = g[0].edge[i].v;
      if (!col[x] && !col[y]) {
        g[1].add(x, y);
      } else if (!col[x]) {
        g[1].add(x, v[col[y]][0]);
      } else if (!col[y]) {
        g[1].add(v[col[x]][0], y);
      } else if (col[x] != col[y]) {
        g[1].add(v[col[x]][0], v[col[y]][0]);
      }
    }
  }
  g[1].DP(v[1][0], 0);
  printf("%d\n", f[v[1][0]]);
  return 0;
  g[1].pre1(v[1][0]);
  g[1].lcapre();
  for (int i = 1; i <= m; i++) {
    imp[++K] = v[i][0];
  }
  std::sort(imp + 1, imp + K + 1, cmp);
  int rt = g[1].build_t(g[2]);
  int ans = g[2].cal(rt);
  printf("%d\n", ans);
  return 0;
}
