#include <bits/stdc++.h>
using namespace std;
int read() {
  int nm = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) nm = nm * 10 + c - '0';
  return nm * f;
}
bitset<63> t[400010 << 2], laz[400010 << 2], tmp, pa, di, ans;
int as;
const int mod = 1000000007;
int zz[66], tp, inv[400010], mul[400010 << 2], lz[400010 << 2],
    len[400010 << 2];
int poww(int a, int b) {
  int ass = 1, tmp = a;
  for (; b; b >>= 1, tmp = 1ll * tmp * tmp % mod)
    if (b & 1) ass = 1ll * ass * tmp % mod;
  return ass;
}
void work(int x) {
  tmp.reset();
  for (int i = 1; i <= tp; i++) {
    if (x < zz[i]) break;
    if (x % zz[i] == 0) tmp[i] = 1;
  }
}
void pushup(int now) {
  t[now] = t[now << 1] | t[now << 1 | 1];
  mul[now] = 1ll * mul[now << 1] * mul[now << 1 | 1] % mod;
}
void add(int now, bitset<63> a, int x) {
  t[now] |= a;
  if (x != 1) mul[now] = 1ll * mul[now] * poww(x, len[now]) % mod;
  laz[now] |= a;
  lz[now] = 1ll * lz[now] * x % mod;
}
void pushdown(int now) {
  add(now << 1, laz[now], lz[now]);
  add(now << 1 | 1, laz[now], lz[now]);
  laz[now].reset();
  lz[now] = 1;
}
void build(int l, int r, int now) {
  lz[now] = 1;
  len[now] = (r - l + 1);
  if (l == r) {
    mul[now] = read();
    work(mul[now]);
    t[now] = tmp;
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, now << 1);
  build(mid + 1, r, now << 1 | 1);
  pushup(now);
}
void modify(int l, int r, int now, int ln, int rn, int x) {
  if (l > rn || r < ln) return;
  if (l >= ln && r <= rn) {
    add(now, tmp, x);
    return;
  }
  pushdown(now);
  int mid = (l + r) >> 1;
  modify(l, mid, now << 1, ln, rn, x);
  modify(mid + 1, r, now << 1 | 1, ln, rn, x);
  pushup(now);
}
bitset<63> query(int l, int r, int now, int ln, int rn) {
  if (l > rn || r < ln) return pa;
  if (l >= ln && r <= rn) {
    as = 1ll * as * mul[now] % mod;
    return t[now];
  }
  pushdown(now);
  int mid = (l + r) >> 1;
  return query(l, mid, now << 1, ln, rn) |
         query(mid + 1, r, now << 1 | 1, ln, rn);
}
int n, q;
char s[11111];
int main() {
  n = read(), q = read();
  for (int i = 2; i <= 300; i++) {
    bool f = true;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) f = false;
    }
    if (f) zz[++tp] = i;
  }
  for (int i = 1; i <= tp; i++) {
    inv[i] = 1ll * (zz[i] - 1) * poww(zz[i], mod - 2) % mod;
  }
  build(1, n, 1);
  while (q--) {
    scanf("%s", s + 1);
    int l = read(), r = read(), x;
    if (s[1] == 'T') {
      as = 1;
      ans = query(1, n, 1, l, r);
      for (int i = 1; i <= tp; i++) {
        if (ans[i]) as = 1ll * as * inv[i] % mod;
      }
      cout << as << "\n";
    } else {
      x = read();
      work(x);
      modify(1, n, 1, l, r, x);
    }
  }
  return 0;
}
