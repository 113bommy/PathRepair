#include <bits/stdc++.h>
using namespace std;
struct node {
  int t, next;
} a[1000010];
long long f[500010][2], h[500010][2];
int head[500010], n, tot;
inline int rd() {
  int x = 0;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar())
    ;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return x;
}
inline long long pls(const long long &x, const long long &y) {
  return (x + y < 998244353LL) ? x + y : x + y - 998244353LL;
}
inline long long mns(const long long &x, const long long &y) {
  return (x - y < 0) ? x - y + 998244353LL : x - y;
}
inline long long ksm(long long x, long long y) {
  long long res = 1;
  for (; y; y >>= 1, x = x * x % 998244353LL)
    if (y & 1) res = res * x % 998244353LL;
  return res;
}
const long long inv2 = ksm(2, 998244353LL - 2);
inline void add(int x, int y) {
  a[++tot].t = y;
  a[tot].next = head[x];
  head[x] = tot;
}
inline void dfs(int x, int y) {
  h[x][0] = 1;
  for (int i = head[x]; i; i = a[i].next) {
    int t = a[i].t;
    if (t == y) continue;
    dfs(t, x);
    long long h1 = f[x][0], h2 = f[x][1];
    f[x][0] =
        pls(pls(h1 * h[t][0] % 998244353LL, f[t][0] * h[x][0] % 998244353LL) %
                998244353LL,
            pls(h1 * h[t][1] % 998244353LL, f[t][1] * h[x][0] % 998244353LL) *
                2 % 998244353LL);
    f[x][1] = pls(
        pls(pls(h2 * h[t][0] % 998244353LL, f[t][0] * h[x][1] % 998244353LL) %
                998244353LL,
            pls(h2 * h[t][1] % 998244353LL, f[t][1] * h[x][1] % 998244353LL) %
                998244353LL) *
            2 % 998244353LL,
        pls(pls(h1 * h[t][0] % 998244353LL, f[t][0] * h[x][0] % 998244353LL),
            h[x][0] * h[t][0] % 998244353LL) %
            998244353LL);
    long long hh = h[x][0];
    h[x][0] = pls(
        pls(h[x][0] * h[t][0] % 998244353LL, h[x][0] * h[t][1] % 998244353LL),
        h[x][0] * h[t][1] % 998244353LL);
    h[x][1] =
        pls(h[x][1] * pls(h[t][0], h[t][1]) % 998244353LL * 2 % 998244353LL,
            hh * h[t][0] % 998244353LL);
  }
}
int main() {
  n = rd();
  tot = 0;
  for (int i = 1; i < n; i++) {
    int x = rd(), y = rd();
    add(x, y);
    add(y, x);
  }
  dfs(1, 0);
  long long ans = pls(f[1][0], f[1][1]);
  ans = ans * 2 % 998244353LL;
  printf("%lld\n", ans);
  return 0;
}
