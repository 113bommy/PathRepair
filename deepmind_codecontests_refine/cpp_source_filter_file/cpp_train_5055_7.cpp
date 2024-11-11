#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 62;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= 1000000007;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
  }
  return res;
}
template <typename T>
inline bool chkmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
int read() {
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
struct Segment {
  long long sum, mio, mie;
  int len, laz;
} t[301000 << 2];
Segment up(Segment a, Segment b) {
  Segment res;
  res.len = a.len + b.len;
  res.sum = b.sum + ((b.len & 1) ? -a.sum : a.sum);
  res.laz = 0;
  if (a.len & 1) {
    res.mie = min(a.mie, b.mio - a.sum);
    res.mio = min(a.mio, b.mie + a.sum);
  } else {
    res.mie = min(a.mie, b.mie + a.sum);
    res.mio = min(a.mio, b.mio - a.sum);
  }
  return res;
}
void build(int rt, int ll, int rr) {
  t[rt] = {0, 0, 0, rr - ll + 1, 0};
  if (ll == rr) return;
  build((rt << 1), ll, ((ll + rr) / 2));
  build(((rt << 1) | 1), ((ll + rr) / 2) + 1, rr);
}
void add(int rt, int v) {
  if (t[rt].len & 1) t[rt].sum += v;
  t[rt].mio += v;
  t[rt].laz += v;
}
void push(int rt) {
  if (t[rt].laz) {
    add((rt << 1), t[rt].laz);
    add(((rt << 1) | 1), t[rt].laz);
    t[rt].laz = 0;
  }
}
void update(int rt, int ll, int rr, int l, int r, int v) {
  if (ll >= l && rr <= r) {
    add(rt, v);
    return;
  }
  push(rt);
  if (l <= ((ll + rr) / 2)) update((rt << 1), ll, ((ll + rr) / 2), l, r, v);
  if (r > ((ll + rr) / 2))
    update(((rt << 1) | 1), ((ll + rr) / 2) + 1, rr, l, r, v);
  t[rt] = up(t[(rt << 1)], t[((rt << 1) | 1)]);
}
Segment query(int rt, int ll, int rr, int l, int r) {
  if (l == ll && rr == r) return t[rt];
  push(rt);
  Segment res;
  if (r <= ((ll + rr) / 2))
    res = query((rt << 1), ll, ((ll + rr) / 2), l, r);
  else if (l > ((ll + rr) / 2))
    res = query(((rt << 1) | 1), ((ll + rr) / 2) + 1, rr, l, r);
  else
    res = up(query((rt << 1), ll, ((ll + rr) / 2), l, ((ll + rr) / 2)),
             query(((rt << 1) | 1), ((ll + rr) / 2) + 1, rr,
                   ((ll + rr) / 2) + 1, r));
  t[rt] = up(t[(rt << 1)], t[((rt << 1) | 1)]);
  return res;
}
int main() {
  int n = read();
  build(1, 0, n - 1);
  for (int i = 0; i < n; i++) {
    int v = read();
    update(1, 0, n - 1, i, i, v);
  }
  int m = read();
  for (int i = 0; i < m; i++) {
    int t = read(), a = read(), b = read();
    if (t == 1) {
      int k = read();
      update(1, 0, n - 1, a, b, k);
    } else {
      Segment ans = query(1, 0, n - 1, a, b);
      if (ans.sum == ((ans.len & 1) && ans.mie >= 0 && ans.mio >= 1))
        puts("1");
      else
        puts("0");
    }
  }
}
