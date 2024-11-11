#include <bits/stdc++.h>
const int N = 4e5 + 3;
int fa[N], R[N], root[N];
long long Ans;
struct Segment_Tree {
  int tot, sz[N * 20], son[N * 20][2];
  long long sum[N * 20];
  void Insert(int &x, int l, int r, int pos) {
    if (!x) x = ++tot;
    if (l == r) {
      sz[x] = 1, sum[x] = pos;
      return;
    }
    int m = l + r >> 1;
    pos <= m ? Insert(son[x][0], l, m, pos) : Insert(son[x][1], m + 1, r, pos);
    sz[x] = sz[son[x][0]] + sz[son[x][1]],
    sum[x] = sum[son[x][0]] + sum[son[x][1]];
  }
  int Merge(int x, int y) {
    if (!x || !y) return x | y;
    Ans -= sum[son[x][0]] * sz[son[x][1]] + sum[son[y][0]] * sz[son[y][1]];
    son[x][0] = Merge(son[x][0], son[y][0]),
    son[x][1] = Merge(son[x][1], son[y][1]);
    Ans += sum[son[x][0]] * sz[son[x][1]],
        sz[x] = sz[son[x][0]] + sz[son[x][1]],
        sum[x] = sum[son[x][0]] + sum[son[x][1]];
    return x;
  }
} T;
inline int read() {
  int now = 0;
  register char c = getchar();
  for (; !isdigit(c); c = getchar())
    ;
  for (; isdigit(c); now = now * 10 + c - 48, c = getchar())
    ;
  return now;
}
int Find(int x) { return x == fa[x] ? x : fa[x] = Find(fa[x]); }
void Merge(int x, int y) {
  x = Find(x), y = Find(y), fa[y] = x;
  Ans -= T.sum[root[x]] * x + T.sum[root[y]] * y;
  root[x] = T.Merge(root[x], root[y]);
  Ans += T.sum[root[x]] * x;
  R[x] = R[y];
}
int main() {
  const int n = read();
  for (int i = 1; i < N; ++i) R[i] = i, fa[i] = i;
  for (int i = 1; i <= n; ++i) {
    int a = read(), b = read(), p = root[a] ? R[Find(a)] + 1 : a;
    Ans -= 1ll * a * b, T.Insert(root[p], 1, n, b), Ans += 1ll * p * b;
    if (root[p - 1]) Merge(p - 1, p);
    if (root[p + 1]) Merge(p, p + 1);
    printf("%I64d\n", Ans);
  }
  return 0;
}
