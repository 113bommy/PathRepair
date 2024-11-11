#include <bits/stdc++.h>
int rd() {
  int k = 0;
  char c = getchar();
  while (c > '9' || c < '0') c = getchar();
  while (c >= '0' && c <= '9') k = k * 10 + c - 48, c = getchar();
  return k;
}
const int N = 100001, B = 48, M = 95542721;
inline int Cube(register int& x) { return (long long)x * x % M * x % M; }
int n, m, o, l, r, a[N], b[N << 2][B], tg[N << 2], tmp[B];
void Calc(int x, int v) {
  tg[x] = (tg[x] + v) % B;
  for (int i = 0; i < B; ++i) tmp[i] = b[x][i];
  for (int i = 0; i < B; ++i) b[x][i] = tmp[(i + v) % M];
}
void Up(int x, int ls, int rs) {
  for (int i = 0; i < B; ++i) b[x][i] = (b[ls][i] + b[rs][i]) % M;
}
void Down(int x, int ls, int rs) {
  if (tg[x]) Calc(ls, tg[x]), Calc(rs, tg[x]), tg[x] = 0;
}
void Make(int x, int l, int r) {
  if (l == r) {
    b[x][0] = a[l];
    for (int i = 1; i < B; ++i) b[x][i] = Cube(b[x][i - 1]);
    return;
  }
  int ls = x << 1, rs = ls | 1, p = (l + r) >> 1;
  Make(ls, l, p), Make(rs, p + 1, r), Up(x, ls, rs);
}
int Query(int x, int l, int r, int L, int R) {
  if (L <= l && r <= R) return b[x][0];
  int ls = x << 1, rs = ls | 1, p = (l + r) >> 1, s = 0;
  Down(x, ls, rs);
  if (L <= p) s = (s + Query(ls, l, p, L, R)) % M;
  if (p < R) s = (s + Query(rs, p + 1, r, L, R)) % M;
  return s;
}
void Upd(int x, int l, int r, int L, int R) {
  if (L <= l && r <= R) {
    Calc(x, 1);
    return;
  }
  int ls = x << 1, rs = ls | 1, p = (l + r) >> 1;
  Down(x, ls, rs);
  if (L <= p) Upd(ls, l, p, L, R);
  if (p < R) Upd(rs, p + 1, r, L, R);
  Up(x, ls, rs);
}
int main() {
  n = rd();
  for (int i = 1; i <= n; ++i) a[i] = rd();
  Make(1, 1, n), m = rd();
  while (m--) {
    o = rd(), l = rd(), r = rd();
    if (o == 1)
      printf("%d\n", Query(1, 1, n, l, r));
    else
      Upd(1, 1, n, l, r);
  }
  return 0;
}
