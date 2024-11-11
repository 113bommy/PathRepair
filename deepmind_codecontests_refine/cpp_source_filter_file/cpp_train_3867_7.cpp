#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 10, maxp = 305, P = 1e9 + 7;
inline char gc() {
  return getchar();
  static const int maxs = 1 << 16;
  static char buf[maxs], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, maxs, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline long long rd() {
  long long x = 0;
  char c = gc();
  bool neg = 0;
  while (c < '0' || c > '9') {
    if (c == '-') neg = 1;
    c = gc();
  }
  while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + c - '0', c = gc();
  return neg ? (~x + 1) : x;
}
int pri[maxp], cnt, ipri[maxp];
bool np[maxp];
bitset<63> hav[maxn << 2], lazz[maxn << 2];
int sum[maxn << 2], a[maxn], N, M, laz[maxn << 2];
inline int fpow(int x, int y) {
  int re = 1;
  while (y) {
    if (y & 1) re = 1ll * re * x % P;
    x = 1ll * x * x % P, y >>= 1;
  }
  return re;
}
inline void update(int p) {
  sum[p] = 1ll * sum[p << 1] * sum[p << 1 | 1] % P;
  hav[p] = hav[p << 1] | hav[p << 1 | 1];
}
void build(int p, int l, int r) {
  laz[p] = 1;
  if (l == r) {
    sum[p] = a[l];
    for (int i = 1; i <= cnt; i++)
      if (a[l] % pri[i] == 0) hav[p][i] = 1;
    return;
  }
  int m = l + r >> 1;
  build(p << 1, l, m);
  build(p << 1 | 1, m + 1, r);
  update(p);
}
inline void deal(int p, int l, int r, int x, bitset<63> &xx) {
  sum[p] = 1ll * sum[p] * fpow(x, r - l + 1) % P;
  hav[p] = hav[p] | xx;
  laz[p] = 1ll * laz[p] * x % P;
  lazz[p] = lazz[p] | xx;
}
inline void pushdown(int p, int l, int r) {
  if (laz[p] == 1) return;
  int m = l + r >> 1;
  deal(p << 1, l, m, laz[p], lazz[p]);
  deal(p << 1 | 1, m + 1, r, laz[p], lazz[p]);
  laz[p] = 1, lazz[p].reset();
}
void mul(int p, int l, int r, int x, int y, int z, bitset<63> &zz) {
  if (x <= l && r <= y) {
    deal(p, l, r, z, zz);
    return;
  }
  int m = l + r >> 1;
  pushdown(p, l, r);
  if (x <= m) mul(p << 1, l, m, x, y, z, zz);
  if (y >= m + 1) mul(p << 1 | 1, m + 1, r, x, y, z, zz);
  update(p);
}
void query(int p, int l, int r, int x, int y, int &z, bitset<63> &zz) {
  if (x <= l && r <= y) {
    z = 1ll * z * sum[p];
    zz = zz | hav[p];
    return;
  }
  int m = l + r >> 1;
  pushdown(p, l, r);
  if (x <= m) query(p << 1, l, m, x, y, z, zz);
  if (y >= m + 1) query(p << 1 | 1, m + 1, r, x, y, z, zz);
}
int main() {
  for (int i = 2; i <= 300; i++) {
    if (!np[i]) pri[++cnt] = i, ipri[cnt] = fpow(i, P - 2);
    for (int j = 1; j <= cnt && pri[j] * i <= 300; j++) {
      np[i * pri[j]] = 1;
      if (i % pri[j] == 0) break;
    }
  }
  N = rd();
  M = rd();
  for (int i = 1; i <= N; i++) a[i] = rd();
  build(1, 1, N);
  for (int i = 1; i <= M; i++) {
    char s[20];
    scanf("%s", s + 1);
    if (s[1] == 'M') {
      int l = rd(), r = rd(), x = rd();
      bitset<63> bb;
      bb.reset();
      for (int i = 1; i <= cnt; i++)
        if (x % pri[i] == 0) bb[i] = 1;
      mul(1, 1, N, l, r, x, bb);
    } else {
      int l = rd(), r = rd();
      bitset<63> bb;
      bb.reset();
      int x = 1;
      query(1, 1, N, l, r, x, bb);
      for (int i = 1; i <= cnt; i++) {
        if (bb[i]) x = 1ll * x * (1 - ipri[i]) % P;
      }
      printf("%d\n", (x + P) % P);
    }
  }
  return 0;
}
