#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
long long qpow(long long a, long long n) {
  long long r = 1 % P;
  for (a %= P; n; a = a * a % P, n >>= 1)
    if (n & 1) r = r * a % P;
  return r;
}
long long inv(long long first) {
  return first <= 1 ? 1 : inv(P % first) * (P - P / first) % P;
}
const int N = 1e5 + 10, K = 555;
int n, m, k, pw[N], ipw[N], a[N], tot;
struct node {
  int *s, len;
  node() { s = NULL, len = 0; }
  int val() { return s[len]; }
  int calc(int first) {
    return (long long)(s[len] - s[len - first] + P) * ipw[len - first] % P;
  }
  int del(int v, int first) { return calc(first) == v && (len -= first, 1); }
  int ins(int first) {
    if (first > 0)
      return s[len + 1] = (s[len] + (long long)first * pw[len]) % P, ++len;
    return !len || calc(1) == -first && len--;
  }
} v[N];
int get(int l, int r, int d, node &first) {
  static int p, tmp[4][K + 1];
  if (first.s == NULL) first.s = tmp[p], ++p &= 3;
  for (first.len = 0; l != r + d; l += d)
    if (!first.ins(a[l] * d)) return 0;
  return 1;
}
int pop(node first) {
  for (int len; tot && first.len; first.len -= len) {
    len = min(first.len, v[tot].len);
    if (!v[tot].del(first.calc(len), len)) return 0;
    tot -= !v[tot].len;
  }
  return !first.len;
}
void push(node first) {
  if (first.len) v[++tot] = first;
}
struct {
  int L, R, need, tag, f[K + 1], g[K + 1];
  node pre, nxt;
  void init(int l, int r) {
    L = l, R = r, need = 1;
    pre.s = f, nxt.s = g;
  }
  void build() {
    if (!need) return;
    need = 0;
    tag = get(R, L, -1, pre) && get(L, R, 1, nxt);
  }
  int chk(int l, int r) {
    l = max(L, l);
    r = min(R, r);
    if (l > r) return 1;
    int ret;
    node first, second;
    if (L == l && r == R)
      build(), first = pre, second = nxt, ret = tag;
    else
      ret = get(r, l, -1, first) && get(l, r, 1, second);
    return ret && pop(first) && (push(second), 1);
  }
} e[N / K + 1];
int ask(int l, int r) {
  if (r - l + 1 & 1) return 0;
  tot = 0;
  for (int i = 1; i <= m; ++i)
    if (!e[i].chk(l, r)) return 0;
  return 1;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  pw[0] = ipw[0] = 1;
  pw[1] = 19260817, ipw[1] = 494863259;
  for (int i = 2; i <= N - 1; ++i) {
    pw[i] = (long long)pw[i - 1] * pw[1] % P;
    ipw[i] = (long long)ipw[i - 1] * ipw[1] % P;
  }
  for (int l = 1, r; l <= n; l = r + 1) {
    r = min(n, l + K - 1);
    e[++m].init(l, r);
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int op, first, second;
    scanf("%d%d%d", &op, &first, &second);
    if (op == 1)
      a[first] = second, e[(first - 1) / K + 1].need = 1;
    else if (ask(first, second))
      puts("Yes");
    else
      puts("No");
  }
}
