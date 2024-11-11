#include <bits/stdc++.h>
using namespace std;
const int N = 100100, M = 1010, D = 32;
int i, j, k, n, m, q, o, x, y, ch, Pn, En;
int a[N], h[N], l[N], r[N], p[N], Cnt[65536];
struct Bitset {
  unsigned int a[D];
  void W() {
    for (i = 63; i >= 0; i--) {
      if (a[i >> 5] & 1u << (i & 31))
        putchar('1');
      else
        putchar('0');
    }
    puts("");
  }
  int count() {
    int i, cnt = 0;
    for (i = 0; i < D; i++) cnt += Cnt[a[i] >> 16] + Cnt[a[i] & 65535];
    return cnt;
  }
  void clear() {
    for (int i = 0; i < D; i++) a[i] = 0;
  }
  void operator|=(const int &n) { a[n >> 5] |= 1u << (n & 31); }
  Bitset operator|(const Bitset &n) {
    Bitset t;
    for (int i = 0; i < D; i++) t.a[i] = a[i] | n.a[i];
    return t;
  }
  Bitset operator&(const Bitset &n) {
    Bitset t;
    for (int i = 0; i < D; i++) t.a[i] = a[i] & n.a[i];
    return t;
  }
  Bitset operator<<(const int &n) {
    Bitset t;
    t.clear();
    for (int i = 0; i < D; i++) {
      if ((n >> 5) + i < D) t.a[(n >> 5) + i] |= a[i] << (n & 31);
      if (!(n & 31) && (n >> 5) + i + 1 < D)
        t.a[(n >> 5) + i + 1] |= a[i] >> (32 - (n & 31));
    }
    return t;
  }
  Bitset operator>>(const int &n) {
    Bitset t;
    t.clear();
    for (int i = 0; i < D; i++) {
      if (i - (n >> 5) >= 0) t.a[i - (n >> 5)] |= a[i] >> (n & 31);
      if (!(n & 31) && i - (n >> 5) - 1 >= 0)
        t.a[i - (n >> 5) - 1] |= a[i] << (32 - (n & 31));
    }
    return t;
  }
} pr;
struct tree {
  int ad;
  Bitset Bit;
} T[N << 2];
struct edge {
  int s, n;
} E[N << 1];
void R(int &x) {
  x = 0;
  ch = getchar();
  while (ch < '0' || '9' < ch) ch = getchar();
  while ('0' <= ch && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
}
void W(int x) {
  if (x >= 10) W(x / 10);
  putchar(x % 10 + '0');
}
void pre(int m) {
  for (int i = 2, j; i < m; i++) {
    for (j = 2; j * j <= i; j++)
      if (i % j == 0) break;
    if (j * j > i) pr |= i;
  }
  for (int i = 0; i < 65536; i++) {
    int j = i;
    while (j) Cnt[i] += j & 1, j >>= 1;
  }
}
void E_add(int x, int y) {
  E[++En].s = y;
  E[En].n = h[x];
  h[x] = En;
  E[++En].s = x;
  E[En].n = h[y];
  h[y] = En;
}
void dfs(int x, int F) {
  l[x] = ++Pn;
  p[Pn] = x;
  for (int k = h[x]; k; k = E[k].n)
    if (E[k].s != F) dfs(E[k].s, x);
  r[x] = Pn;
}
void up(int k) { T[k].Bit = T[k << 1].Bit | T[k << 1 | 1].Bit; }
void down(int k) {
  if (T[k].ad) {
    T[k << 1].ad = (T[k << 1].ad + T[k].ad) % m;
    T[k << 1 | 1].ad = (T[k << 1 | 1].ad + T[k].ad) % m;
    T[k << 1].Bit =
        (T[k << 1].Bit << T[k].ad) | (T[k << 1].Bit >> (m - T[k].ad));
    T[k << 1 | 1].Bit =
        (T[k << 1 | 1].Bit << T[k].ad) | (T[k << 1 | 1].Bit >> (m - T[k].ad));
    T[k].ad = 0;
  }
}
void T_build(int L, int R, int k) {
  if (L == R) {
    T[k].ad = 0;
    T[k].Bit |= a[p[L]];
    return;
  }
  int mid = (L + R) >> 1;
  T_build(L, mid, k << 1);
  T_build(mid + 1, R, k << 1 | 1);
  up(k);
}
void T_add(int L, int R, int l, int r, int ad, int k) {
  if (L == l && R == r) {
    T[k].ad = (T[k].ad + ad) % m;
    T[k].Bit = (T[k].Bit << ad) | (T[k].Bit >> (m - ad));
    return;
  }
  down(k);
  int mid = (L + R) >> 1;
  if (r <= mid)
    T_add(L, mid, l, r, ad, k << 1);
  else {
    if (l > mid)
      T_add(mid + 1, R, l, r, ad, k << 1 | 1);
    else
      T_add(L, mid, l, mid, ad, k << 1),
          T_add(mid + 1, R, mid + 1, r, ad, k << 1 | 1);
  }
  up(k);
}
Bitset T_query(int L, int R, int l, int r, int k) {
  if (L == l && R == r) return T[k].Bit;
  down(k);
  int mid = (L + R) >> 1;
  if (r <= mid) return T_query(L, mid, l, r, k << 1);
  if (l > mid) return T_query(mid + 1, R, l, r, k << 1 | 1);
  return T_query(L, mid, l, mid, k << 1) |
         T_query(mid + 1, R, mid + 1, r, k << 1 | 1);
}
int main() {
  R(n);
  R(m);
  pre(m);
  for (i = 1; i <= n; i++) R(a[i]), a[i] %= m;
  for (i = 1; i < n; i++) R(x), R(y), E_add(x, y);
  dfs(1, 0);
  T_build(1, n, 1);
  R(q);
  for (i = 1; i <= q; i++) {
    R(o);
    if (o == 1)
      R(x), R(y), T_add(1, n, l[x], r[x], y % m, 1);
    else
      R(x), W((T_query(1, n, l[x], r[x], 1) & pr).count()), puts("");
  }
}
