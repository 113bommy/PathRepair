#include <bits/stdc++.h>
using namespace std;
inline char nc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline void read(int &x) {
  char c = nc(), b = 1;
  for (; !(c >= '0' && c <= '9'); c = nc())
    if (c == '-') b = -1;
  for (x = 0; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = nc())
    ;
  x *= b;
}
const int P = 1e9 + 7;
inline void _add(int &x, int y) {
  x += y;
  if (x >= P) x -= P;
}
const int N = 1000005;
int T[N << 2], F[N << 2];
inline void modify(int x, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) {
    T[x] = 0;
    F[x] = 1;
    return;
  }
  if (F[x])
    T[x << 1] = T[x << 1 | 1] = 0, F[x << 1] = F[x << 1 | 1] = 1, F[x] = 0;
  int mid = (l + r) >> 1;
  if (ql <= mid) modify(x << 1, l, mid, ql, qr);
  if (qr > mid) modify(x << 1 | 1, mid + 1, r, ql, qr);
  T[x] = (T[x << 1] + T[x << 1 | 1]) % P;
}
inline void add(int x, int l, int r, int t, int a) {
  if (l == r) return void(_add(T[x], a));
  if (F[x])
    T[x << 1] = T[x << 1 | 1] = 0, F[x << 1] = F[x << 1 | 1] = 1, F[x] = 0;
  int mid = (l + r) >> 1;
  if (t <= mid)
    add(x << 1, l, mid, t, a);
  else
    add(x << 1 | 1, mid + 1, r, t, a);
  T[x] = (T[x << 1] + T[x << 1 | 1]) % P;
}
inline int query(int x, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return T[x];
  if (F[x])
    T[x << 1] = T[x << 1 | 1] = 0, F[x << 1] = F[x << 1 | 1] = 1, F[x] = 0;
  int ret = 0, mid = (l + r) >> 1;
  if (ql <= mid) _add(ret, query(x << 1, l, mid, ql, qr));
  if (qr > mid) _add(ret, query(x << 1 | 1, mid + 1, r, ql, qr));
  return ret;
}
struct event {
  int f, x, y, y2;
  event(int f = 0, int x = 0, int y = 0, int y2 = 0)
      : f(f), x(x), y(y), y2(y2) {}
  bool operator<(const event &B) const {
    return x == B.x ? (f == B.f ? y > B.y : f < B.f) : x < B.x;
  }
} ev[N << 1];
int tot;
int n, m;
set<int> Set;
inline int Ans(int x) {
  int y = -(*Set.lower_bound(-x));
  return query(1, 1, m, y, x);
}
namespace BIT {
int c[N], maxn;
inline void init(int n) { maxn = n; }
inline void add(int x, int r) {
  for (int i = x; i <= maxn; i += i & -i) c[i] += r;
}
inline void add(int l, int r, int x) { add(l, x), add(r + 1, -x); }
inline int C(int x) {
  int ret = 0;
  for (int i = x; i; i -= i & -i) ret += c[i];
  return ret;
}
}  // namespace BIT
int main() {
  int K, x1, x2, y1, y2;
  read(n);
  read(m);
  read(K);
  while (K--) {
    read(x1);
    read(y1);
    read(x2);
    read(y2);
    ev[++tot] = event(1, x1, y1, y2);
    ev[++tot] = event(2, x2 + 1, y1, y2);
  }
  ev[++tot] = event(3, 1, 1, 0);
  sort(ev + 1, ev + tot + 1);
  int p = 1;
  Set.insert(-1);
  BIT::init(m);
  for (int i = 1; i <= n; i++) {
    int l = p, r;
    for (; p <= tot && ev[p].x == i; p++)
      ;
    r = p - 1;
    int last = m + 1;
    for (int j = l; j <= r; j++)
      if (ev[j].f == 1) {
        if (ev[j].y2 < m && BIT::C(ev[j].y2 + 1) == 0 &&
            BIT::C(ev[j].y2) == 0 && ev[j].y2 + 1 != last) {
          int tmp = Ans(ev[j].y2);
          add(1, 1, m, ev[j].y2 + 1, tmp);
        }
        modify(1, 1, m, ev[j].y, ev[j].y2);
        last = ev[j].y;
      } else if (ev[j].f == 3)
        add(1, 1, m, 1, 1);
    for (int j = l; j <= r; j++)
      if (ev[j].f == 2) {
        BIT::add(ev[j].y, ev[j].y2, -1);
        Set.erase(-(ev[j].y2 + 1));
      }
    for (int j = l; j <= r; j++)
      if (ev[j].f == 1) {
        BIT::add(ev[j].y, ev[j].y2, 1);
        Set.insert(-(ev[j].y2 + 1));
      }
  }
  int ans = Ans(m);
  printf("%d\n", ans);
  return 0;
}
