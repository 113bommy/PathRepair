#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6;
const long long mod = 1e9 + 7;
inline long long read() {
  long long s = 0;
  register bool neg = 0;
  register char c = getchar();
  for (; c < '0' || c > '9'; c = getchar()) neg |= (c == '-');
  for (; c >= '0' && c <= '9'; s = s * 10 + (c ^ 48), c = getchar())
    ;
  s = (neg ? -s : s);
  return s;
}
long long a, b, c, dp[N + 10], top, p[N + 10], id;
struct node {
  long long h, l, r, t, real;
  bool operator<(const node &o) const {
    return real < o.real || real == o.real && h != real;
  }
} s[N + 10];
struct segment {
  long long l, r;
  set<long long> st;
} q[N * 4 + 10];
inline void build(long long n, long long l, long long r) {
  q[n].l = l;
  q[n].r = r;
  q[n].st.insert(0);
  if (l == r) {
    return;
  }
  long long mid = (l + r) >> 1;
  build(n << 1, l, mid);
  build(n << 1 | 1, mid + 1, r);
}
inline void change(long long n, long long l, long long r, long long k,
                   long long opt) {
  if (q[n].l >= l && q[n].r <= r) {
    if (opt == -1)
      q[n].st.erase(k);
    else
      q[n].st.insert(k);
    return;
  }
  long long mid = (q[n].l + q[n].r) >> 1;
  if (l <= mid) change(n << 1, l, r, k, opt);
  if (mid < r) change(n << 1 | 1, l, r, k, opt);
}
inline long long query(long long n, long long k) {
  long long res = 0;
  if (q[n].st.size()) res = *q[n].st.rbegin();
  if (q[n].l == q[n].r) return res;
  long long mid = (q[n].l + q[n].r) >> 1;
  if (k <= mid)
    res = max(res, query(n << 1, k));
  else
    res = max(res, query(n << 1 | 1, k));
  return res;
}
signed main() {
  a = read();
  b = read();
  c = read();
  for (long long i = 1; i <= c; i++) {
    s[++id].h = p[++top] = read();
    s[id].l = read();
    s[id].r = read();
    s[id].t = read();
    s[id].real = s[id].h;
    if (s[id].h + s[id].t + 1 <= a + 1) {
      ++id;
      s[id].h = s[id - 1].h;
      s[id].real = p[++top] = s[id - 1].h + s[id - 1].t + 1;
      s[id].l = s[id - 1].l;
      s[id].r = s[id - 1].r;
    }
  }
  sort(p + 1, p + top + 1);
  top = unique(p + 1, p + top + 1) - p - 1;
  for (long long i = 1; i <= id; i++) {
    s[i].h = lower_bound(p + 1, p + top + 1, s[i].h) - p;
    s[i].real = lower_bound(p + 1, p + top + 1, s[i].real) - p;
  }
  sort(s + 1, s + id + 1);
  build(1, 1, b);
  dp[0] = 1;
  for (long long i = 1; i <= id; i++) {
    if (s[i].real != s[i].h)
      change(1, s[i].l, s[i].r, s[i].h, -1);
    else {
      if (s[i].l == 1) {
        long long tmp = query(1, s[i].r + 1);
        dp[s[i].h] = 2 * dp[tmp] % mod;
      } else if (s[i].r == b) {
        long long tmp = query(1, s[i].l - 1);
        dp[s[i].h] = 2 * dp[tmp] % mod;
      } else {
        long long tmp1 = query(1, s[i].l - 1), tmp2 = query(1, s[i].r + 1);
        dp[s[i].h] = dp[tmp1] + dp[tmp2];
      }
      change(1, s[i].l, s[i].r, s[i].h, 1);
    }
  }
  long long ans = 0;
  for (long long i = 1; i <= b; i++) ans = (ans + dp[query(1, i)]) % mod;
  printf("%lld", ans);
  return 0;
}
