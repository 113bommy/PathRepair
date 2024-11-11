#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, K;
int c[200010][2], L[200010], R[200010], t1[11], t2[11];
int v1[200010][11], size[200010], v2[200010][11];
int tot, fa[200010], Rt, tmp[11], vl[200010], sum[200010];
inline void updata(int x) {
  L[x] = x;
  R[x] = x;
  size[x] = 1;
  sum[x] = vl[x];
  if (c[x][0])
    L[x] = L[c[x][0]], size[x] += size[c[x][0]], sum[x] += sum[c[x][0]];
  if (c[x][1])
    R[x] = R[c[x][1]], size[x] += size[c[x][1]], sum[x] += sum[c[x][1]];
}
inline void rotate(int x, int &k) {
  int y = fa[x], z = fa[y], l = c[y][1] == x, r = l ^ 1;
  if (k == y)
    k = x;
  else
    c[z][c[z][1] == y] = x;
  if (c[x][r]) fa[c[x][r]] = y;
  fa[y] = x;
  fa[x] = z;
  c[y][l] = c[x][r];
  c[x][r] = y;
  updata(y);
  updata(x);
}
inline void splay(int x, int &k) {
  while (x != k) {
    int y = fa[x], z = fa[y];
    if (y != k) {
      if ((c[z][0] == y) ^ (c[y][0] == x))
        rotate(y, k);
      else
        rotate(x, k);
    }
    rotate(x, k);
  }
}
inline int find(int x, int y) {
  if (y == size[c[x][0]] + 1) return x;
  if (size[c[x][0]] >= y) return find(c[x][0], y);
  return find(c[x][1], y - size[c[x][0]] - 1);
}
inline void split(int l, int r) {
  int x = find(Rt, l - 1), y = find(Rt, r + 1);
  splay(x, Rt);
  splay(y, c[Rt][1]);
}
inline int cut(int l, int r) {
  split(l, r);
  int al = sum[c[c[Rt][1]][0]];
  c[c[Rt][1]][0] = 0;
  updata(c[Rt][1]);
  updata(Rt);
  return al;
}
inline void init() {
  Rt = 1;
  size[1] = 2;
  tot = 2;
  c[1][1] = 2;
  fa[2] = 1;
  size[2] = 1;
  for (int i = 1; i <= K; i++)
    v1[1][i] = v2[1][i] = 0x3fffffff, v1[2][i] = v2[2][i] = 0;
  updata(2);
  updata(1);
}
inline bool jug(int bs[], int bp[]) {
  for (int i = 1; i <= K; i++)
    if (bs[i] < bp[i]) return 1;
  return 0;
}
inline int q1(int x, int y) {
  if (c[x][0] && jug(v1[R[c[x][0]]], tmp)) return q1(c[x][0], y);
  if (jug(v1[x], tmp)) {
    for (int i = 1; i <= K; i++) t2[i] = v2[x][i];
    return y + size[c[x][0]] + 1;
  }
  return q1(c[x][1], y + size[c[x][0]] + 1);
}
inline int q2(int x, int y) {
  if (c[x][1] && jug(tmp, v2[L[c[x][1]]]))
    return q2(c[x][1], y + size[c[x][0]] + 1);
  if (jug(tmp, v2[x])) {
    for (int i = 1; i <= K; i++) t1[i] = v1[x][i];
    return y + size[c[x][0]] + 1;
  }
  return q2(c[x][0], y);
}
inline void solve() {
  for (int i = 1; i <= K; i++) tmp[i] = read();
  int l = q1(Rt, 0), r = q2(Rt, 0);
  if (l > r) {
    split(r + 1, l - 1);
    ++tot;
    for (int i = 1; i <= K; i++) v1[tot][i] = v2[tot][i] = tmp[i];
    fa[tot] = c[Rt][1];
    c[c[Rt][1]][0] = tot;
    vl[tot] = 1;
    updata(tot);
    updata(c[Rt][1]);
    updata(Rt);
  } else {
    int bs = cut(l + 1, r);
    for (int i = 1; i <= K; i++) v1[Rt][i] = t1[i];
    vl[Rt] += bs + 1;
    updata(Rt);
    for (int i = 1; i <= K; i++)
      v2[Rt][i] = max(v2[Rt][i], tmp[i]), v1[Rt][i] = min(v1[Rt][i], tmp[i]);
  }
  printf("%d\n", vl[find(Rt, 2)]);
}
int main() {
  n = read();
  K = read();
  init();
  for (int i = 1; i <= n; i++) solve();
  return 0;
}
