#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0;
  char ch = getchar(), w = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * w;
}
void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writeln(long long x) {
  write(x);
  puts("");
}
const int N = 100100;
int h, w, n;
struct No {
  int u, l, r, s;
  int h, c;
} a[N];
bool cmph(No _x, No _y) { return _x.u > _y.u; }
int ls[N * 4], rs[N * 4], mn[N * 4];
const int MOD = 1e9 + 7;
stack<int> t[N * 4];
void build(int o, int l, int r) {
  ls[o] = l, rs[o] = r;
  if (l == r) {
    t[o].push(0);
    t[o].push(n + 1);
    return;
  }
  int mid = (l + r) >> 1;
  if (l <= mid) build((o << 1), l, mid);
  if (r > mid) build((o << 1 | 1), mid + 1, r);
}
void up(int o) { mn[o] = min(mn[(o << 1)], mn[(o << 1 | 1)]); }
int ask(int o, int l, int r, int val) {
  if (mn[o] > val) return 0;
  if (ls[o] == rs[o]) {
    int res = 0;
    while (t[o].size() && a[t[o].top()].u <= val) {
      (res += a[t[o].top()].c) %= MOD;
      t[o].pop();
    }
    mn[o] = a[t[o].top()].u;
    return res;
  }
  int mid = (ls[o] + rs[o]) >> 1;
  long long res = 0;
  if (l <= mid) res += ask((o << 1), l, r, val);
  if (r > mid) res += ask((o << 1 | 1), l, r, val);
  up(o);
  return res % MOD;
}
void change(int o, int x, int val) {
  if (ls[o] == rs[o]) {
    t[o].push(val);
    mn[o] = a[val].u;
    return;
  }
  int mid = (ls[o] + rs[o]) >> 1;
  if (x <= mid)
    change((o << 1), x, val);
  else
    change((o << 1 | 1), x, val);
  up(o);
}
long long ans;
int main() {
  h = read(), w = read(), n = read();
  for (int i = 1; i <= n; ++i) {
    a[i].u = read(), a[i].l = read(), a[i].r = read(), a[i].s = read();
    a[i].l += 1;
    a[i].r += 1;
    a[i].h = a[i].u + a[i].s;
  }
  ++w;
  sort(a + 1, a + 1 + n, cmph);
  a[0].u = 2e9 + 9;
  a[n + 1].c = 1;
  a[n + 1].u = h + 1;
  build(1, 1, w);
  for (int i = 1; i <= n; ++i) {
    a[i].c = ask(1, a[i].l, a[i].r, a[i].h);
    if (a[i].l == 2)
      change(1, a[i].r + 1, i), change(1, a[i].r + 1, i);
    else if (a[i].r == w)
      change(1, a[i].l - 1, i), change(1, a[i].l - 1, i);
    else
      change(1, a[i].l - 1, i), change(1, a[i].r + 1, i);
  }
  for (int i = 2; i <= w; ++i) (ans += ask(1, i, i, h + 1)) %= MOD;
  writeln(ans);
  return 0;
}
