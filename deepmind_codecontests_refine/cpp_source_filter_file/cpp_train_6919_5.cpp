#include <bits/stdc++.h>
using namespace std;
int n, m, k, lim, ans = 0;
int calc(int x) {
  int res = 0;
  for (int i = 0; (1 << i) <= x; ++i) {
    int c = (((x >> i) + 1) >> 1) & 1;
    if (c) res ^= (1 << min(lim, i));
  }
  return res;
}
int calc(int l, int r) { return calc(r) - calc(l - 1); }
int mul(int x, int y) {
  int res = 0, z = y;
  for (int i = lim; ~i; --i)
    if ((z >> (i + 1)) & 1) z ^= (1 << i);
  for (int i = 0; (1 << i) <= x; ++i)
    if ((x >> i) & 1) {
      int mask = (1 << i) - 1;
      res ^= (y & mask);
      if ((z >> i) & 1) res ^= (1 << i);
    }
  return res;
}
template <typename T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  bool f = 0;
  while (c < '0' || c > '9') f |= (c == '-'), c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + (c ^ 48), c = getchar();
  if (f) x = -x;
}
const char Yes[] = "Hamed", No[] = "Malek";
const int N = 500050;
struct Line {
  int l, r, y, w;
  friend bool operator<(Line a, Line b) { return a.y < b.y; }
} line[N * 2];
int tot;
int mapX[N * 2], val[N * 2], cnt;
int cover[N << 3], num[N << 3];
void pushup(int x, int l, int r) {
  if (cover[x] > 0)
    num[x] = val[r] ^ val[l - 1];
  else
    num[x] = num[x << 1] ^ num[x << 1 | 1];
}
void modify(int x, int l, int r, int ql, int qr, int w) {
  if (ql <= l && r <= qr) {
    cover[x] += w;
    return pushup(x, l, r);
  }
  int mid = (l + r) >> 1;
  if (ql <= mid) modify(x << 1, l, mid, ql, qr, w);
  if (qr > mid) modify(x << 1 | 1, mid + 1, r, ql, qr, w);
  pushup(x, l, r);
}
void Modify(Line &x) { return modify(1, 1, n, x.l + 1, x.r, x.w); }
int main() {
  read(n), read(m), read(k);
  while ((1 << (lim + 1)) <= k) lim++;
  while (m--) {
    int a, b, c, d;
    read(a), read(b), read(c), read(d);
    a--, b--;
    line[++tot].l = a, line[tot].r = c, line[tot].y = b, line[tot].w = 1;
    line[++tot].l = a, line[tot].r = c, line[tot].y = d, line[tot].w = -1;
    mapX[++cnt] = a, mapX[++cnt] = c;
  }
  sort(mapX + 1, mapX + 1 + cnt);
  cnt = unique(mapX + 1, mapX + 1 + cnt) - mapX;
  for (int i = 1; i <= cnt; ++i) val[i] = calc(mapX[i]);
  for (int i = 1; i <= tot; ++i) {
    line[i].l = lower_bound(mapX + 1, mapX + 1 + cnt, line[i].l) - mapX;
    line[i].r = lower_bound(mapX + 1, mapX + 1 + cnt, line[i].r) - mapX;
  }
  sort(line + 1, line + 1 + tot);
  for (int i = 1, j = 1, last = 0, cur; i <= tot; i = j) {
    cur = calc(line[i].y);
    ans ^= mul(num[1], cur ^ last);
    last = cur;
    while (line[i].y == line[j].y && j <= tot) Modify(line[j++]);
  }
  if (ans)
    puts(Yes);
  else
    puts(No);
  return 0;
}
