#include <bits/stdc++.h>
const int N = 3e4 + 10;
long long ri() {
  char c = getchar();
  long long x = 0, f = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) - '0' + c;
  return x * f;
}
long long len[66];
int n, d, m, tot, gen[25], b[N];
std::bitset<N> all;
struct info {
  long long ans, len;
  std::bitset<N> pre, suf;
  info operator+(const info &b) {
    info c;
    c.ans = ans + b.ans;
    c.len = len + b.len;
    c.pre = pre;
    c.suf = b.suf;
    if (len < n - 1) c.pre &= (b.pre << len) | (all >> n - 1 - len);
    if (b.len < n - 1) c.suf &= (suf >> b.len) | (all << n - 1 - b.len);
    if (len + b.len >= n) {
      std::bitset<N> res = suf & b.pre;
      if (len < n - 1) res &= (all >> n - 1 - len);
      if (b.len < n - 1) res &= (all << n - 1 - b.len);
      c.ans += res.count();
    }
    return c;
  }
  void operator+=(const info &b) { *this = !len ? b : *this + b; }
} f[66][66];
long long Query(long long x) {
  info res;
  res.ans = res.len = 0;
  int add = 0;
  for (int i = tot; ~i; --i)
    for (int j = 1; j <= d; ++j) {
      if (x >= len[i]) {
        x -= len[i];
        res += f[i][(add + gen[j]) % m];
      } else {
        (add += gen[j]) %= m;
        break;
      }
    }
  return res.ans;
}
int main() {
  d = ri();
  m = ri();
  for (int i = 1; i <= d; ++i) gen[i] = ri();
  n = ri();
  for (int i = 1; i <= n; ++i) b[i] = ri();
  for (int i = 1; i < n; ++i) all.set(i);
  len[tot = 0] = 1;
  for (int i = 0; i < m; ++i) {
    f[0][i].len = 1;
    if (n == 1)
      f[0][i].ans = i <= b[1];
    else {
      for (int j = 1; j <= n - 1; ++j) {
        f[0][i].pre[j] = i <= b[n - j + 1];
        f[0][i].suf[j] = i <= b[n - j];
      }
    }
  }
  long long L = ri(), R = ri();
  for (; len[tot] <= R / d;) {
    ++tot;
    len[tot] = len[tot - 1] * d;
    for (int i = 0; i < m; ++i)
      for (int j = 1; j <= d; ++j) f[tot][i] += f[tot - 1][(i + gen[j]) % m];
  }
  printf("%lld\n", Query(R) - Query(L + n - 2));
  return 0;
}
