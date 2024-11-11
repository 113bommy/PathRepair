#include <bits/stdc++.h>
using namespace std;
int read() {
  int r = 0, t = 1, c = getchar();
  while (c < '0' || c > '9') {
    t = c == '-' ? -1 : 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    r = r * 10 + c - 48;
    c = getchar();
  }
  return r * t;
}
const int N = 510, M = 1000010, mod = 998244353;
long long n, m, f[N][N], a[M], nex[M], lst[N], b[N], k, vis[N][N];
long long dfs2(long long l, long long r) {
  if (l > r) return 1;
  if (vis[l][r]) return f[l][r];
  vis[l][r] = 1;
  long long& ans = f[l][r];
  ans = 0;
  long long p = l;
  for (int i = (l + 1), end_i = (r); i <= end_i; i++)
    if (b[i] < b[p]) p = i;
  long long ans1 = 0, ans2 = 0;
  for (int i = (l), end_i = (p); i <= end_i; i++)
    ans1 = (ans1 + dfs2(l, i - 1) * dfs2(i, p - 1)) % mod;
  for (int i = (p), end_i = (r); i <= end_i; i++)
    ans2 = (ans2 + dfs2(p + 1, i) * dfs2(i + 1, r)) % mod;
  return ans = ans1 * ans2 % mod;
}
long long dfs1(long long l, long long r, long long mx) {
  if (l > r) return 1;
  int p = l;
  long long ans = 1;
  while (p <= r) {
    if (a[p] < mx) return 0;
    while (nex[p]) {
      if (nex[p] > r) return 0;
      ans = ans * dfs1(p + 1, nex[p] - 1, a[p]) % mod;
      p = nex[p];
    }
    p++;
  }
  p = l;
  k = 0;
  while (p <= r) {
    b[++k] = a[p];
    p = lst[a[p]] + 1;
  }
  for (int i = (1), end_i = (k); i <= end_i; i++)
    for (int j = (1), end_j = (k); j <= end_j; j++) vis[i][j] = 0;
  return ans * dfs2(1, k) % mod;
}
int main() {
  n = read();
  m = read();
  for (int i = (1), end_i = (m); i <= end_i; i++) {
    a[i] = read();
    nex[lst[a[i]]] = i;
    lst[a[i]] = i;
  }
  printf("%d\n", (int)dfs1(1, m, 0));
  return 0;
}
