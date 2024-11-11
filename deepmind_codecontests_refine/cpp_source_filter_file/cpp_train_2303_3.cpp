#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char ch = getchar();
  long long s = 0, w = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return s * w;
}
int n, m, q;
int a[100010], f[100010 << 2][2][32], M, d[100010], tot, tag[100010 << 2];
inline void push(int x) {
  for (register int i = 0; i <= M - 1; i++) swap(f[x][0][i], f[x][1][i]);
  tag[x] ^= 1;
}
inline void pushdown(int x) {
  if (tag[x]) {
    push((x << 1));
    push((x << 1 | 1));
    tag[x] = 0;
  }
}
inline void pushup(int x) {
  for (register int i = 0; i <= 1; i++)
    for (register int j = 0; j <= M - 1; j++)
      f[x][i][j] = f[(x << 1)][i][f[(x << 1 | 1)][i][j]];
}
void update(int l, int r, int x, int left, int right) {
  if (l == left && right == r) {
    push(x);
    return;
  }
  pushdown(x);
  if (right <= ((l + r) >> 1))
    update(l, ((l + r) >> 1), (x << 1), left, right);
  else if (left > ((l + r) >> 1))
    update(((l + r) >> 1) + 1, r, (x << 1 | 1), left, right);
  else
    update(l, ((l + r) >> 1), (x << 1), left, ((l + r) >> 1)),
        update(((l + r) >> 1) + 1, r, (x << 1 | 1), ((l + r) >> 1) + 1, right);
  pushup(x);
}
void query(int l, int r, int x, int left, int right) {
  if (l == left && right == r) {
    d[++tot] = x;
    return;
  }
  pushdown(x);
  if (right <= ((l + r) >> 1))
    query(l, ((l + r) >> 1), (x << 1), left, right);
  else if (left > ((l + r) >> 1))
    query(((l + r) >> 1) + 1, r, (x << 1 | 1), left, right);
  else
    query(l, ((l + r) >> 1), (x << 1), left, ((l + r) >> 1)),
        query(((l + r) >> 1) + 1, r, (x << 1 | 1), ((l + r) >> 1) + 1, right);
}
void build(int l, int r, int x) {
  if (l == r) {
    for (register int j = 0; j <= M - 1; j++) {
      f[x][a[l]][j] = (j << 1) % M + 1;
      f[x][a[l] ^ 1][j] = (j == M - 1) ? (j << 1) % M : (j << 1) % M + 1;
    }
    return;
  }
  build(l, ((l + r) >> 1), (x << 1));
  build(((l + r) >> 1) + 1, r, (x << 1 | 1));
  pushup(x);
}
int main() {
  n = read(), m = read(), q = read();
  M = (1 << m);
  for (register int i = 1; i <= n; i++) a[i] = read() % 2;
  build(1, n, 1);
  while (q--) {
    int opt = read();
    if (opt == 1) {
      int l = read(), r = read(), v = read() % 2;
      if (v & 1) update(1, n, 1, l, r);
    }
    if (opt == 2) {
      int l = read(), r = read();
      tot = 0;
      query(1, n, 1, l, r);
      int x = (1 << m) - 1;
      for (register int i = tot; i >= 1; i--) x = f[d[i]][0][x];
      puts(x & 1 ? "1" : "2");
    }
  }
  return 0;
}
