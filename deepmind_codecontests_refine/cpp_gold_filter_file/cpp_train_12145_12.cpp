#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
inline char nc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline void read(int &x) {
  char c = nc();
  x = 0;
  for (; c > '9' || c < '0'; c = nc())
    ;
  for (; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = nc())
    ;
}
int n, k, p, a[N], Q[N], t;
namespace Case1 {
int a[N], f[110][105], g[N][105];
void solve() {
  for (int i = 1; i <= n; i++) read(a[i]), a[i] %= p;
  memset(f, 0x7f / 2, sizeof(f));
  f[0][0] = 0;
  int pre = 0;
  for (int i = 1; i <= n; i++) {
    pre = (pre + a[i]) % p;
    for (int j = k; j; j--) {
      g[i][j] = (1 << 30);
      for (int s = 0; s < p; s++) {
        int cur = (pre - s + p) % p;
        g[i][j] = min(g[i][j], f[cur][j - 1] + s);
      }
      f[pre][j] = min(f[pre][j], g[i][j]);
    }
  }
  printf("%d\n", g[n][k]);
}
}  // namespace Case1
int main() {
  read(n);
  read(k);
  read(p);
  if (k * p >= n) return Case1::solve(), 0;
  for (int i = 1; i <= n; i++) read(a[i]), a[i] = (a[i] + a[i - 1]) % p;
  for (int i = 1; i < n; i++) {
    if (!t || Q[t] <= a[i])
      Q[++t] = a[i];
    else {
      int p = upper_bound(Q + 1, Q + 1 + t, a[i]) - Q;
      Q[p] = a[i];
    }
  }
  int ps;
  if (!t || Q[t] <= a[n])
    ps = t + 1;
  else {
    ps = upper_bound(Q + 1, Q + 1 + t, a[n]) - Q;
  }
  if (ps >= k)
    printf("%d\n", a[n]);
  else
    printf("%d\n", a[n] + p);
  return 0;
}
