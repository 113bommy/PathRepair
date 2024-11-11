#include <bits/stdc++.h>
using namespace std;
const int maxn = 300000 + 7;
const int mod = 1e9 + 9;
int n, m;
long long f[maxn] = {0, 1, 1};
long long sum[maxn << 2];
long long fa[maxn << 2], fb[maxn << 2];
long long get_fib(long long a, long long b, int rt) {
  if (rt == 1) return a;
  if (rt == 2) return b;
  return (b * f[rt - 1] + a * f[rt - 2]) % mod;
}
long long get_sum(long long a, long long b, int len) {
  return (get_fib(a, b, len + 2) - b + mod) % mod;
}
void add_fib(int rt, int l, int r, long long a, long long b) {
  (fa[rt] += a) % mod;
  (fb[rt] += b) % mod;
  (sum[rt] += get_sum(a, b, r - l + 1)) % mod;
}
void pushUp(int rt) { sum[rt] = (sum[rt << 1] + sum[rt << 1 | 1]) % mod; }
void pushDown(int rt, int l, int r) {
  int m = (l + r) >> 1;
  add_fib(rt << 1, l, m, fa[rt], fb[rt]);
  add_fib(rt << 1 | 1, m + 1, l, get_fib(fa[rt], fb[rt], m - l + 2),
          get_fib(fa[rt], fb[rt], m - l + 3));
  fa[rt] = fb[rt] = 0;
}
void build(int l, int r, int rt) {
  if (l == r) {
    cin >> sum[rt];
    return;
  }
  int m = (l + r) >> 1;
  build(l, m, rt << 1);
  build(m + 1, r, rt << 1 | 1);
  pushUp(rt);
}
long long query(int L, int R, int l, int r, int rt) {
  if (L <= l && r <= R) {
    return sum[rt];
  }
  pushDown(rt, l, r);
  long long ret = 0;
  int m = (l + r) >> 1;
  if (L <= m) (ret += query(L, R, l, m, rt << 1)) % mod;
  if (m < R) (ret += query(L, R, m + 1, r, rt << 1 | 1)) % mod;
  return ret;
}
void update(int L, int R, int l, int r, int rt) {
  if (L <= l && r <= R) {
    add_fib(rt, l, r, f[l - L + 1], f[l - L + 2]);
    return;
  }
  pushDown(rt, l, r);
  int m = (l + r) >> 1;
  if (L <= m) update(L, R, l, m, rt << 1);
  if (m < R) update(L, R, m + 1, r, rt << 1 | 1);
  pushUp(rt);
}
int main() {
  ios::sync_with_stdio(false);
  for (int i = 3; i < maxn; ++i) f[i] = (f[i - 1] + f[i - 2]) % mod;
  cin >> n >> m;
  build(1, n, 1);
  while (m--) {
    int cmd, l, r;
    cin >> cmd >> l >> r;
    if (cmd == 1) {
      update(l, r, 1, n, 1);
    } else {
      cout << query(l, r, 1, n, 1) % mod << endl;
    }
  }
  return 0;
}
