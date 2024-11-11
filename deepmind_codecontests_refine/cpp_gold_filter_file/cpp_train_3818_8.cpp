#include <bits/stdc++.h>
const int N = 3e5;
long long u, v, p, q[N + 10], l = 1, r = 0, s[N], tot;
std::map<long long, long long> pre, used, opt, pre0, opt0;
void in(long long now, long long to, long long op) {
  if (!used[to]) {
    used[to] = 1;
    opt[to] = op;
    pre[to] = now;
    q[++r] = to;
  }
}
long long quickpow(long long d, long long k) {
  long long f = 1;
  while (k) {
    if (k & 1) f = f * d % p;
    d = d * d % p;
    k >>= 1;
  }
  return f;
}
int bfs0() {
  q[++r] = u;
  while (l <= r && r <= N) {
    long long now = q[l++];
    if (now == v) {
      while (now != u) s[++tot] = opt[now], now = pre[now];
      printf("%lld\n", tot);
      for (int i = tot; i; i--) printf("%lld ", s[i]);
      return 1;
    }
    long long to = (now + 1) % p;
    in(now, to, 1);
    to = (now + p - 1) % p;
    in(now, to, 2);
    to = quickpow(now, p - 2);
    in(now, to, 3);
  }
  return 0;
}
void in0(long long now, long long to, long long op) {
  if (!used[to]) {
    used[to] = 1;
    opt0[to] = op;
    pre0[to] = now;
    q[++r] = to;
  }
}
long long tmp;
void swap(long long &x, long long &y) { tmp = x, x = y, y = tmp; }
void bfs1() {
  used.clear();
  l = 1, r = 0;
  q[++r] = v;
  while (l <= r && r <= N) {
    long long now = q[l++];
    if (pre.find(now) != pre.end()) {
      long long t = now;
      while (now != u) s[++tot] = opt[now], now = pre[now];
      for (int i = 1; i <= tot >> 1; i++) swap(s[i], s[tot + 1 - i]);
      now = t;
      while (now != v) s[++tot] = opt0[now], now = pre0[now];
      printf("%lld\n", tot);
      for (int i = 1; i <= tot; i++) printf("%lld ", s[i]);
      return;
    }
    long long to = (now + 1) % p;
    in0(now, to, 2);
    to = (now + p - 1) % p;
    in0(now, to, 1);
    to = quickpow(now, p - 2);
    in0(now, to, 3);
  }
}
int main() {
  scanf("%lld%lld%lld", &u, &v, &p);
  if (bfs0()) return 0;
  bfs1();
  return 0;
}
