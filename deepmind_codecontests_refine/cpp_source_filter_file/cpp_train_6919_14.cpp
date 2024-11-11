#include <bits/stdc++.h>
using namespace std;
template <class t>
inline t read(t &x) {
  char c = getchar();
  bool f = 0;
  x = 0;
  while (!isdigit(c)) f |= c == '-', c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  if (f) x = -x;
  return x;
}
template <class t>
inline void write(t x) {
  if (x < 0)
    putchar('-'), write(-x);
  else {
    if (x > 9) write(x / 10);
    putchar('0' + x % 10);
  }
}
const int M = 5e4 + 5;
int n, k, m, num[M << 1], un, ans, tr[M << 3], tg[M << 3];
struct oper {
  int x, l, r, o;
} q[M << 1];
void pushup(int x, int l, int r) {
  if (tg[x])
    tr[x] = num[r] ^ num[l - 1];
  else
    tr[x] = l == r ? 0 : tr[x << 1] ^ tr[x << 1 | 1];
}
void up(int x, int l, int r, int p, int q, int v) {
  if (p <= l && r <= q) return tg[x] += v, pushup(x, l, r);
  int mid = l + r >> 1;
  if (p <= mid) up(x << 1, l, mid, p, q, v);
  if (q > mid) up(x << 1 | 1, mid + 1, r, p, q, v);
  pushup(x, l, r);
}
signed main() {
  int K;
  k = 1;
  read(n);
  read(m);
  read(K);
  while (k <= K) k <<= 1;
  for (int i = 1, x1, ysghysgh, x2, y2; i <= m; i++) {
    read(x1);
    read(ysghysgh);
    read(x2);
    read(y2);
    q[i] = {x1 - 1, ysghysgh - 1, y2, 1};
    q[i + m] = {x2, ysghysgh - 1, y2, -1};
    num[i] = ysghysgh - 1;
    num[i + m] = y2;
  }
  sort(q + 1, q + 1 + m * 2, [](oper a, oper b) { return a.x < b.x; });
  sort(num + 1, num + 1 + m * 2);
  un = unique(num + 1, num + 1 + m * 2) - num - 1;
  for (int i = 1; i <= m << 1; i++) {
    ans ^= (q[i].x ^ q[i - 1].x) & tr[1];
    int l = lower_bound(num + 1, num + 1 + un, q[i].l) - num;
    int r = lower_bound(num + 1, num + 1 + un, q[i].r) - num;
    up(1, 1, un, l + 1, r, q[i].o);
  }
  puts(ans & k - 1 ? "kmd" : "mak");
}
