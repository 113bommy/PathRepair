#include <bits/stdc++.h>
using namespace std;
const int N = 2000;
const int inf = 1e9;
struct Pr {
  int x, y;
  Pr() {}
  Pr(int X, int Y) : x(X), y(Y) {}
  inline bool operator==(const Pr& b) const { return x == b.x && y == b.y; }
  inline bool operator!=(const Pr& b) const { return !(*this == b); }
} a[N + 5], NIL;
int n, m, q;
bool op[N + 5][N + 5];
int U[N + 5][N + 5], D[N + 5][N + 5];
int l[N + 5], r[N + 5];
int ans[N + 5];
struct Segment_Tree {
  int cnt;
  struct node {
    int l, r;
    int MinU, MinD;
  } T[(N << 2) + 5];
  inline void Update(int i) {
    T[i].MinU = min(T[(i << 1)].MinU, T[(i << 1 | 1)].MinU);
    T[i].MinD = min(T[(i << 1)].MinD, T[(i << 1 | 1)].MinD);
  }
  inline void Build(int i, int l, int r, int x) {
    T[i].l = l;
    T[i].r = r;
    if (l == r) {
      T[i].MinU = U[x][l];
      T[i].MinD = D[x][l];
      return;
    }
    Build((i << 1), l, (l + (r - l) / 2), x);
    Build((i << 1 | 1), (l + (r - l) / 2) + 1, r, x);
    Update(i);
  }
  inline Pr Find(int i, Pr p) {
    if (T[i].r < p.x || T[i].l > p.y) return NIL;
    if (p.x <= T[i].l && T[i].r <= p.y) return Pr(T[i].MinU, T[i].MinD);
    Pr res = Find((i << 1), p);
    Pr res2 = Find((i << 1 | 1), p);
    return Pr(min(res.x, res2.x), min(res.y, res2.y));
  }
} Seg;
int calc() {
  int res = 0;
  for (register int i = 1; i <= n; i++) {
    for (register int j = 1; j <= m; j++) {
      int x = j;
      while (x > 1 && U[i][x - 1] >= U[i][j]) x = l[x - 1];
      l[j] = x;
    }
    for (register int j = m; j >= 1; j--) {
      int x = j;
      while (x < m & U[i][x + 1] >= U[i][j]) x = r[x + 1];
      r[j] = x;
    }
    for (register int j = 1; j <= m; j++)
      res = max(res, min(U[i][j], r[j] - l[j] + 1));
  }
  return res;
}
bool Check(int size, int y) {
  if (size > min(n, m)) return 0;
  int t1 = max(1, y - size + 1);
  int t2 = m - size + 1;
  for (register int i = t1; i <= t2; i++) {
    Pr k = Seg.Find(1, Pr(i, i + size - 1));
    if (k.x + k.y - 1 >= size) return true;
  }
  return false;
}
int main() {
  scanf("%d %d %d", &n, &m, &q);
  for (register int i = 1; i <= n; i++) {
    getchar();
    for (register int j = 1; j <= m; j++) op[i][j] = (getchar() == '.');
  }
  for (register int i = 1; i <= q; i++) {
    scanf("%d %d", &a[i].x, &a[i].y);
    op[a[i].x][a[i].y] = 0;
  }
  for (register int i = 1; i <= n; i++)
    for (register int j = 1; j <= m; j++)
      U[i][j] = op[i][j] ? U[i - 1][j] + 1 : 0;
  for (register int i = n; i >= 1; i--)
    for (register int j = 1; j <= m; j++)
      D[i][j] = op[i][j] ? D[i + 1][j] + 1 : 0;
  int size = calc();
  NIL = Pr(inf, inf);
  for (register int i = q; i >= 1; i--) {
    ans[i] = size;
    int tx = a[i].x;
    int ty = a[i].y;
    op[tx][ty] = 1;
    U[tx][ty] = U[tx - 1][ty] + 1;
    for (register int j = tx + 1; j <= n && op[j][ty]; j++)
      U[j][ty] += U[tx][ty];
    D[tx][ty] = D[tx + 1][ty] + 1;
    for (register int j = tx - 1; j >= 1 && op[j][ty]; j--)
      D[j][ty] += D[tx][ty];
    Seg.Build(1, 1, m, tx);
    while (Check(size + 1, ty)) size++;
  }
  for (register int i = 1; i <= q; i++) printf("%d\n", ans[i]);
  return 0;
}
