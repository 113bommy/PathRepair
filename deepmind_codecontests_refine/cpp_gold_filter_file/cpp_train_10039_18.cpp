#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int sum = 0;
  char c = getchar();
  bool f = 0;
  while (c < '0' || c > '9') {
    if (c == '-') f = 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  if (f) return -sum;
  return sum;
}
const int N = 200005;
const int orz = 2000000;
const int otz = 1000000005;
int n, K, d, a[N], b[N], c[N];
namespace Seg {
int lazy[N * 4], t[N * 4], v, rch;
inline void push(int p) {
  if (!lazy[p]) return;
  int x = lazy[p], l = p << 1, r = (l | 1);
  t[l] += x;
  t[r] += x;
  lazy[l] += x;
  lazy[r] += x;
  lazy[p] = 0;
}
inline void ch(int p, int l, int r, int L, int R) {
  if (l == L && r == R) {
    lazy[p] += v;
    t[p] += v;
    return;
  }
  int mid = (l + r) >> 1;
  push(p);
  if (R <= mid)
    ch(p << 1, l, mid, L, R);
  else if (L > mid)
    ch(p << 1 | 1, mid + 1, r, L, R);
  else
    ch(p << 1, l, mid, L, mid), ch(p << 1 | 1, mid + 1, r, mid + 1, R);
  t[p] = min(t[p << 1], t[p << 1 | 1]);
}
inline void ask(int p, int l, int r) {
  if (l == r) {
    rch = l;
    return;
  }
  int mid = (l + r) >> 1;
  push(p);
  if (t[p << 1] < K)
    ask(p << 1, l, mid);
  else
    ask(p << 1 | 1, mid + 1, r);
}
}  // namespace Seg
using namespace Seg;
int s1[N], s2[N], t1, t2;
map<int, int> H;
int main() {
  int i, r, st = 1, ed = 1, ans = 1, ino = 0;
  n = read();
  K = read();
  d = read();
  for (i = 1; i <= n; i++) a[i] = read() + otz;
  if (!d) {
    for (i = 1; i <= n; i = r) {
      r = i;
      while (r <= n && a[r] == a[i]) r++;
      if (r - i > ans) ans = r - i, st = i, ed = r - 1;
    }
    printf("%d %d", st, ed);
    return 0;
  }
  for (i = 1; i <= n; i++) b[i] = a[i] % d, c[i] = a[i] / d;
  a[0] = a[1];
  b[0] = b[1];
  v = orz;
  ch(1, 1, n, 1, n);
  for (i = 1; i <= n; i++) {
    if (b[i] != b[i - 1]) v = orz, ch(1, 1, n, ino + 1, i - 1), ino = i - 1;
    if (H[a[i]] > ino) v = orz, ch(1, 1, n, ino + 1, H[a[i]]), ino = H[a[i]];
    while (t1 && a[i] > a[s1[t1]])
      v = c[i] - c[s1[t1]], ch(1, 1, n, s1[t1 - 1] + 1, s1[t1]), t1--;
    while (t2 && a[i] < a[s2[t2]])
      v = c[s2[t2]] - c[i], ch(1, 1, n, s2[t2 - 1] + 1, s2[t2]), t2--;
    H[a[i]] = i;
    s1[++t1] = i;
    s2[++t2] = i;
    v = -1;
    ch(1, 1, n, 1, i);
    v = -orz;
    ch(1, 1, n, i, i);
    ask(1, 1, n);
    if (i - rch + 1 > ans) ans = i - rch + 1, st = rch, ed = i;
  }
  printf("%d %d", st, ed);
  return 0;
}
