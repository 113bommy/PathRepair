#include <bits/stdc++.h>
using namespace std;
const int N = 210000, mod = 1e9 + 7;
int n, m, fa[N], ra[N], siz[N], huan[N], x[N], y[N], cnt;
long long ans = 1;
map<int, int> xp, yp;
int _max(int a, int b) { return a > b ? a : b; }
int _min(int a, int b) { return a < b ? a : b; }
inline int read() {
  int s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return s * w;
}
long long qp(long long a, int k) {
  long long p = 1;
  while (k > 0) {
    if ((k & 1)) {
      p = a * p % mod;
    }
    a = a * a % mod;
    k >>= 1;
  }
  return p;
}
int find(int x) {
  if (x == fa[x])
    return x;
  else
    return fa[x] = find(fa[x]);
}
void merge(int a, int b) {
  int x = find(a);
  int y = find(b);
  if (x == y) {
    huan[x] = 1;
    return;
  }
  siz[x] += siz[y], fa[y] = x, huan[x] |= huan[y];
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    x[i] = read();
    y[i] = read();
    if (!xp[x[i]]) xp[x[i]] = ++cnt;
    if (!yp[y[i]]) yp[y[i]] = ++cnt;
  }
  for (int i = 1; i <= cnt; i++) fa[i] = i, siz[i] = 1;
  for (int i = 1; i <= n; i++) {
    merge(xp[x[i]], yp[y[i]]);
  }
  ans = 1;
  for (int i = 1; i <= cnt; i++) {
    if (fa[i] == i) {
      if (huan[i])
        ans *= qp(2, siz[i]), ans %= mod;
      else
        ans *= (qp(2, siz[i]) - 1 + mod) % mod, ans %= mod;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
