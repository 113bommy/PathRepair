#include <bits/stdc++.h>
using namespace std;
inline int Isdigit(char c) {
  if (c < '0' || c > '9') return 0;
  return 1;
}
inline int readint() {
  register int x = 0, flag = 1;
  register char ch;
  while (!Isdigit(ch = getchar()))
    if (ch == '-') flag = -1;
  while (x = x * 10 + (ch & 15), Isdigit(ch = getchar()))
    ;
  return x * flag;
}
inline long long readlong() {
  register long long x = 0, flag = 1;
  register char ch;
  while (!Isdigit(ch = getchar()))
    if (ch == '-') flag = -1;
  while (x = x * 10 + (ch & 15), Isdigit(ch = getchar()))
    ;
  return x * flag;
}
template <class T>
inline void write(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
template <class T>
inline bool Chkmax(T& x, const T& y) {
  return x < y ? x = y, true : false;
}
template <class T>
inline bool Chkmin(T& x, const T& y) {
  return x > y ? x = y, true : false;
}
const long long maxn = 4e5 + 40;
long long n;
struct Point {
  long long x, y;
} aa[maxn];
long long cmp(Point a, Point b) { return a.x < b.x; }
long long Sum[maxn * 4], Minn[maxn * 4];
inline void pushup(long long rt) {
  if (Minn[rt << 1] < Minn[rt << 1 | 1]) {
    Minn[rt] = Minn[rt << 1];
    Sum[rt] = Sum[rt << 1];
    return;
  }
  if (Minn[rt << 1] == Minn[rt << 1 | 1]) {
    Minn[rt] = Minn[rt << 1];
    Sum[rt] = Sum[rt << 1] + Sum[rt << 1 | 1];
    return;
  }
  if (Minn[rt << 1] > Minn[rt << 1 | 1]) {
    Minn[rt] = Minn[rt << 1 | 1];
    Sum[rt] = Sum[rt << 1 | 1];
    return;
  }
}
long long tag[maxn * 4];
inline void pushdown(long long rt, long long l, long long r) {
  Minn[rt << 1] += tag[rt], Minn[rt << 1 | 1] += tag[rt];
  tag[rt << 1] += tag[rt], tag[rt << 1 | 1] += tag[rt];
  tag[rt] = 0;
}
void insert(long long rt, long long l, long long r, long long x, long long v) {
  if (l == r) {
    Minn[rt] = v;
    Sum[rt] = 1;
    tag[rt] = 0;
    return;
  }
  long long mid = (l + r) / 2;
  if (tag[rt]) pushdown(rt, l, r);
  if (x <= mid) insert(rt << 1, l, mid, x, v);
  if (x > mid) insert(rt << 1 | 1, mid + 1, r, x, v);
  pushup(rt);
}
void Update(long long rt, long long l, long long r, long long L, long long R,
            long long v) {
  if (L > R) return;
  if (L <= l && r <= R) {
    Minn[rt] += v;
    tag[rt] += v;
    return;
  }
  long long mid = (l + r) / 2;
  if (tag[rt]) pushdown(rt, l, r);
  if (L <= mid) Update(rt << 1, l, mid, L, R, v);
  if (R > mid) Update(rt << 1 | 1, mid + 1, r, L, R, v);
  pushup(rt);
}
long long Query(long long rt, long long l, long long r, long long L,
                long long R) {
  if (L > R) return 0;
  if (L <= l && r <= R) {
    if (Minn[rt] == 0) return Sum[rt];
    return 0;
  }
  long long ans = 0;
  if (tag[rt]) pushdown(rt, l, r);
  long long mid = (l + r) / 2;
  if (L <= mid) ans += Query(rt << 1, l, mid, L, R);
  if (R > mid) ans += Query(rt << 1 | 1, mid + 1, r, L, R);
  pushup(rt);
  return ans;
}
void Build(long long rt, long long l, long long r) {
  if (l == r) {
    Minn[rt] = 0x3f3f3f3f;
    tag[rt] = 0;
    Sum[rt] = 1;
    return;
  }
  long long mid = (l + r) / 2;
  Build(rt << 1, l, mid);
  Build(rt << 1 | 1, mid + 1, r);
  pushup(rt);
}
long long mii[maxn], maa[maxn];
long long tot1, tot2;
long long a[maxn];
signed main() {
  n = readint();
  for (long long i = 1; i <= n; i++) {
    aa[i].x = readint();
    aa[i].y = readint();
  }
  sort(aa + 1, aa + 1 + n, cmp);
  for (long long i = 1; i <= n; i++) {
    a[i] = aa[i].y;
  }
  Build(1, 1, n);
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    Update(1, 1, n, 1, i - 1, -1);
    long long pre = i;
    while (tot1 > 0 && a[i] < a[mii[tot1]]) {
      Update(1, 1, n, mii[tot1 - 1] + 1, mii[tot1], a[mii[tot1]] - a[i]),
          pre = mii[tot1], tot1--;
    }
    pre = i;
    while (tot2 > 0 && a[i] > a[maa[tot2]]) {
      Update(1, 1, n, maa[tot2 - 1] + 1, maa[tot2], a[i] - a[maa[tot2]]),
          pre = maa[tot2], tot2--;
    }
    mii[++tot1] = i, maa[++tot2] = i;
    insert(1, 1, n, i, i + a[i] - a[i] - i);
    ans += Query(1, 1, n, 1, i);
  }
  cout << ans;
  return 0;
}
