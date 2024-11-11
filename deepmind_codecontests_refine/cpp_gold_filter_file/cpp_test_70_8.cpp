#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long read() {
  long long x = 0, f = 1;
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
void write(long long x) {
  if (x < 0) x = -x, putchar('-');
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
long long quickmod(long long x, long long y) {
  long long Ans = 1;
  while (y) {
    if (y & 1) Ans = (Ans * x) % mod;
    x = (x * x) % mod;
    y >>= 1;
  }
  return Ans;
}
long long a[500005], b[500005], vis[500005];
struct Seg_Tree {
  struct st {
    long long l, r;
    long long _min, _max;
    long long ans;
  } t[2000005];
  void build(long long id, long long l, long long r) {
    t[id].l = l, t[id].r = r;
    if (l == r) {
      t[id]._max = t[id]._min = a[l];
      t[id].ans = (a[l] * a[l]) % mod;
      return;
    }
    long long mid = (l + r) / 2;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    t[id]._min = min(t[id << 1]._min, t[id << 1 | 1]._min);
    t[id]._max = max(t[id << 1]._max, t[id << 1 | 1]._max);
    t[id].ans = (t[id << 1].ans + t[id << 1 | 1].ans) % mod;
  }
  void push_down(long long id, long long x, long long y) {
    if (t[id].l == t[id].r) {
      t[id]._min = t[id]._max = y;
      t[id].ans = y * y % mod;
      return;
    }
    long long mid = (t[id].l + t[id].r) / 2;
    if (x <= mid)
      push_down(id << 1, x, y);
    else
      push_down(id << 1 | 1, x, y);
    t[id]._min = min(t[id << 1]._min, t[id << 1 | 1]._min);
    t[id]._max = max(t[id << 1]._max, t[id << 1 | 1]._max);
    t[id].ans = (t[id << 1].ans + t[id << 1 | 1].ans) % mod;
  }
  long long get_min(long long id, long long l, long long r) {
    if (l <= t[id].l && t[id].r <= r) {
      return t[id]._min;
    }
    long long mid = (t[id].l + t[id].r) / 2, _min = 1e12;
    if (l <= mid) _min = min(_min, get_min(id << 1, l, r));
    if (r > mid) _min = min(_min, get_min(id << 1 | 1, l, r));
    return _min;
  }
  long long get_max(long long id, long long l, long long r) {
    if (l <= t[id].l && t[id].r <= r) {
      return t[id]._max;
    }
    long long mid = (t[id].l + t[id].r) / 2, _max = 0;
    if (l <= mid) _max = max(_max, get_max(id << 1, l, r));
    if (r > mid) _max = max(_max, get_max(id << 1 | 1, l, r));
    return _max;
  }
  long long get_sum(long long id, long long l, long long r) {
    if (l <= t[id].l && t[id].r <= r) {
      return t[id].ans;
    }
    long long mid = (t[id].l + t[id].r) / 2, cnt = 0;
    if (l <= mid) cnt += get_sum(id << 1, l, r);
    if (r > mid) cnt += get_sum(id << 1 | 1, l, r);
    return cnt % mod;
  }
} T;
long long s1[500005], s2[500005];
long long fac[500005], f[500005];
long long check(long long l, long long r, long long k) {
  long long len = r - l + 1;
  long long sum = (s1[r] - s1[l - 1] + mod) % mod;
  long long cnt = ((sum - f[len - 1] * k) % mod + mod) % mod;
  long long _min = cnt * quickmod(len, mod - 2) % mod;
  long long _max = (_min + k * (len - 1)) % mod;
  if ((_min + _max) * len % mod * quickmod(2, mod - 2) % mod != sum) return 0;
  if (T.get_sum(1, l, r) ==
      (len * (_min % mod) % mod * (_min % mod) % mod +
       fac[len - 1] * k % mod * k % mod +
       f[len - 1] * k % mod * (_min % mod) % mod * 2ll % mod) %
          mod) {
    return 1;
  }
  return 0;
}
signed main() {
  for (long long i = 1; i <= 500000; i++)
    fac[i] = (fac[i - 1] + i * i) % mod, f[i] = (f[i - 1] + i) % mod;
  long long n = read(), Q = read();
  for (long long i = 1; i <= n; i++)
    a[i] = read(), s1[i] = (s1[i - 1] + a[i]) % mod,
    s2[i] = (s2[i - 1] + a[i] * a[i]) % mod;
  T.build(1, 1, n);
  while (Q--) {
    long long l = read(), r = read(), k = read();
    if (l > r) swap(l, r);
    if (check(l, r, k) || (check(l, r, mod - k)))
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}
