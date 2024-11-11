#include <bits/stdc++.h>
template <typename T>
inline void read(T &x) {
  char c;
  bool nega = 0;
  while ((!isdigit(c = getchar())) && (c != '-'))
    ;
  if (c == '-') {
    nega = 1;
    c = getchar();
  }
  x = c - 48;
  while (isdigit(c = getchar())) x = x * 10 + c - 48;
  if (nega) x = -x;
}
template <typename T>
inline void writep(T x) {
  if (x > 9) writep(x / 10);
  putchar(x % 10 + 48);
}
template <typename T>
inline void write(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  writep(x);
  putchar(' ');
}
template <typename T>
inline void writeln(T x) {
  write(x);
  putchar('\n');
}
using namespace std;
long long n, m, seed, vmax, a[100005], top;
pair<long long, long long> q[100005];
struct no {
  long long x, val;
  long long tag, flag;
} t[100005 * 4];
void build(long long node, long long l, long long r) {
  if (l == r) {
    t[node].x = a[l];
    t[node].flag = 1;
    t[node].tag = 0;
    t[node].val = 0;
    return;
  }
  long long mid = (l + r) / 2;
  build(node * 2, l, mid);
  build(node * 2 + 1, mid + 1, r);
  t[node].x = t[node * 2].x;
  t[node].flag = (t[node * 2].flag & t[node * 2 + 1].flag &&
                  t[node * 2].x == t[node * 2 + 1].x);
}
void push(long long node, long long l, long long r) {
  if (t[node].tag) {
    t[node * 2].tag = 1;
    t[node * 2].x = t[node].val;
    t[node * 2].val = t[node].val;
    t[node * 2].flag = 1;
    t[node * 2 + 1].tag = 1;
    t[node * 2 + 1].x = t[node].val;
    t[node * 2 + 1].val = t[node].val;
    t[node * 2 + 1].flag = 1;
    t[node].val = t[node].tag = 0;
    return;
  }
  if (t[node].val) {
    t[node * 2].x += t[node].val;
    t[node * 2].val += t[node].val;
    t[node * 2 + 1].x += t[node].val;
    t[node * 2 + 1].val += t[node].val;
    t[node].val = t[node].tag = 0;
  }
}
void add(long long node, long long l, long long r, long long u, long long v,
         long long val) {
  if (l > v || r < u) return;
  if (u <= l && r <= v) {
    t[node].val += val;
    t[node].x += val;
    return;
  }
  long long mid = (l + r) / 2;
  push(node, l, r);
  add(node * 2, l, mid, u, v, val);
  add(node * 2 + 1, mid + 1, r, u, v, val);
  t[node].x = t[node * 2].x;
  t[node].flag = (t[node * 2].flag & t[node * 2 + 1].flag &&
                  t[node * 2].x == t[node * 2 + 1].x);
}
void change(long long node, long long l, long long r, long long u, long long v,
            long long val) {
  if (l > v || r < u) return;
  if (u <= l && r <= v) {
    t[node].tag = 1;
    t[node].flag = 1;
    t[node].x = t[node].val = val;
    return;
  }
  push(node, l, r);
  long long mid = (l + r) / 2;
  change(node * 2, l, mid, u, v, val);
  change(node * 2 + 1, mid + 1, r, u, v, val);
  t[node].x = t[node * 2].x;
  t[node].flag = (t[node * 2].flag & t[node * 2 + 1].flag &&
                  t[node * 2].x == t[node * 2 + 1].x);
}
void get(long long node, long long l, long long r, long long u, long long v) {
  if (l > v || r < u) return;
  if (u <= l && r <= v)
    if (t[node].flag) {
      q[++top] = make_pair(t[node].x, r - l + 1);
      return;
    }
  push(node, l, r);
  long long mid = (l + r) / 2;
  get(node * 2, l, mid, u, v);
  get(node * 2 + 1, mid + 1, r, u, v);
}
long long mu(long long x, long long y, long long moo) {
  if (y == 1) return x % moo;
  long long ans = mu(x, y / 2, moo);
  if (y % 2) return (((ans * ans) % moo) * x) % moo;
  return (ans * ans) % moo;
}
long long randd() {
  long long ret = seed;
  seed = (seed * 7 + 13) % 1000000007;
  return ret;
}
void setup() {
  read(n);
  read(m);
  read(seed);
  read(vmax);
  for (long long i = (1); i <= (n); i++) a[i] = randd() % vmax + 1;
  build(1, 1, n);
}
void work() {
  while (m--) {
    long long op = randd() % 4 + 1;
    long long l = randd() % n + 1;
    long long r = randd() % n + 1;
    if (l > r) swap(l, r);
    if (op == 1)
      add(1, 1, n, l, r, randd() % vmax + 1);
    else if (op == 2)
      change(1, 1, n, l, r, randd() % vmax + 1);
    else if (op == 3) {
      top = 0;
      long long k = randd() % (r - l + 1) + 1;
      get(1, 1, n, l, r);
      sort(q + 1, q + top + 1);
      for (long long i = (1); i <= (top); i++)
        if (k <= q[i].second) {
          writeln(q[i].first);
          break;
        } else
          k -= q[i].second;
    } else {
      top = 0;
      long long res = 0;
      get(1, 1, n, l, r);
      long long x = randd() % vmax + 1, y = randd() % vmax + 1;
      for (long long i = (1); i <= (top); i++)
        res = (res + (q[i].second * mu(q[i].first, x, y)) % y) % y;
      writeln(res);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  setup();
  work();
  return 0;
}
