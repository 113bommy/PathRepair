#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
const int N = 4e5 + 1000;
struct Front_star {
  int u, v, nxt;
} e[N << 2];
int cnt = 0;
int first[N];
void add(int u, int v) {
  ++cnt;
  e[cnt].u = u;
  e[cnt].v = v;
  e[cnt].nxt = first[u];
  first[u] = cnt;
}
int n, m;
int dep[N];
int fa[N][21];
int st[N];
int ed[N];
int tot = 0;
void DFS(int u, int fat) {
  st[u] = ++tot;
  fa[u][0] = fat;
  for (int i = 1; i <= 20; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
  for (int i = first[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if (v == fat) continue;
    dep[v] = dep[u] + 1;
    DFS(v, u);
  }
  ed[u] = tot;
}
int GetLCA(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  for (int i = 20; i >= 0; --i) {
    if (dep[x] - (1 << i) >= dep[y]) x = fa[x][i];
  }
  if (x == y) return x;
  for (int i = 20; i >= 0; --i) {
    if (fa[x][i] != fa[y][i]) {
      x = fa[x][i];
      y = fa[y][i];
    }
  }
  return fa[x][0];
}
int f[N][22];
void DFS2(int u, int fat) {
  for (int i = first[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if (v == fat) continue;
    DFS2(v, u);
    if (!f[u][0] || (f[v][0] && dep[f[v][0]] < dep[f[u][0]])) f[u][0] = f[v][0];
  }
}
struct Node {
  int x, y, val, Id;
} A[N << 2];
bool cmp(Node A, Node B) { return A.x < B.x || (A.x == B.x && A.Id < B.Id); }
int qcnt = 0;
int ans[N];
int Delta[N];
struct BIT {
  int T[N];
  inline int lowbit(int x) { return x & (-x); }
  inline void Update(int x, int v) {
    while (x < N) {
      T[x] += v;
      x += lowbit(x);
    }
  }
  inline int Query(int x) {
    int ret = 0;
    while (x) {
      ret += T[x];
      x -= lowbit(x);
    }
    return ret;
  }
} Tree;
int main() {
  read(n);
  for (int i = 2; i <= n; ++i) {
    int fa;
    read(fa);
    add(fa, i);
    add(i, fa);
  }
  dep[1] = 1;
  DFS(1, 0);
  int Q;
  read(Q);
  while (Q--) {
    int u, v;
    read(u);
    read(v);
    int LCA = GetLCA(u, v);
    if (st[u] > st[v]) swap(u, v);
    if (!f[u][0] || dep[LCA] < dep[f[u][0]]) f[u][0] = LCA;
    if (!f[v][0] || dep[LCA] < dep[f[v][0]]) f[v][0] = LCA;
    A[++qcnt] = (Node){st[u], st[v], 1, 0};
  }
  DFS2(1, 0);
  for (int i = 1; i <= n; ++i)
    if (f[i][0] == i) f[i][0] = 0;
  for (int j = 1; j <= 20; ++j) {
    for (int i = 1; i <= n; ++i) {
      f[i][j] = f[f[i][j - 1]][j - 1];
    }
  }
  read(Q);
  for (int i = 1; i <= Q; ++i) {
    int u, v;
    read(u);
    read(v);
    if (st[u] > st[v]) swap(u, v);
    int LCA = GetLCA(u, v);
    for (int j = 20; j >= 0; --j)
      if (f[u][j] && dep[LCA] < dep[f[u][j]]) u = f[u][j], ans[i] += (1 << j);
    for (int j = 20; j >= 0; --j)
      if (f[v][j] && dep[LCA] < dep[f[v][j]]) v = f[v][j], ans[i] += (1 << j);
    if ((!f[u][0] && u != LCA) || (!f[v][0] && v != LCA)) {
      ans[i] = -1;
      continue;
    }
    if (u == LCA || v == LCA) {
      ans[i] += 1;
    } else {
      ans[i] += 2;
      A[++qcnt] = (Node){st[u] - 1, st[v] - 1, 1, i};
      A[++qcnt] = (Node){st[u] - 1, ed[v], -1, i};
      A[++qcnt] = (Node){ed[u], st[v] - 1, -1, i};
      A[++qcnt] = (Node){ed[u], ed[v], 1, i};
    }
  }
  sort(A + 1, A + 1 + qcnt, cmp);
  for (int i = 1; i <= qcnt; ++i) {
    if (!A[i].Id) {
      Tree.Update(A[i].y, A[i].val);
    } else {
      Delta[A[i].Id] += A[i].val * Tree.Query(A[i].y);
    }
  }
  for (int i = 1; i <= Q; ++i) {
    if (ans[i] == -1)
      cout << -1 << '\n';
    else {
      cout << ans[i] - (Delta[i] > 0) << '\n';
    }
  }
  return 0;
}
