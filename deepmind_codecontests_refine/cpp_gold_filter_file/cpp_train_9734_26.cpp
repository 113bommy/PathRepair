#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
inline int addmod(int x) { return x >= mod ? x - mod : x; }
inline int submod(int x) { return x < 0 ? x + mod : x; }
int fpow(int x, int y) {
  int ans = 1;
  while (y) {
    if (y & 1) ans = 1ll * ans * x % mod;
    x = 1ll * x * x % mod;
    y /= 2;
  }
  return ans;
}
char s[100005];
int b, n, k, m;
long long a[100005];
int f[4005][4005][2][2];
void getadd(int x) {
  a[1] += x;
  int las = n;
  for (int i = 1; a[i] || i <= las; i++) {
    a[i + 1] += a[i] / b;
    a[i] %= b;
    n = i;
  }
}
void getmul() {
  for (int i = 1; i <= n; i++) a[i] *= 10;
  int las = n;
  for (int i = 1; a[i] || i <= las; i++) {
    a[i + 1] += a[i] / b;
    a[i] %= b;
    n = i;
  }
}
inline int F(int x) { return 1ll * x * (x + 1) / 2 % mod; }
inline int G(int x) { return 1ll * x * (2 * b - x - 1) / 2 % mod; }
inline int G2(int x) { return 1ll * (x + 1) * (2 * b - x) / 2 % mod; }
int dfs(int dep, int ct, int lim, int fl) {
  if (dep == n + 1) {
    if (fl || ct < k) return 0;
    return 1;
  }
  if (f[dep][ct][lim][fl] != -1) return f[dep][ct][lim][fl];
  int ans = 0;
  if (!lim) {
    if (!fl) {
      ans = addmod(ans + 1ll * dfs(dep + 1, ct, lim, 0) * F(b) % mod);
      ans = addmod(ans + 1ll * dfs(dep + 1, ct + 1, lim, 1) * F(b - 1) % mod);
    } else {
      ans = addmod(ans + 1ll * dfs(dep + 1, ct, lim, 0) * F(b - 1) % mod);
      ans = addmod(ans + 1ll * dfs(dep + 1, ct + 1, lim, 1) * F(b) % mod);
    }
  } else {
    if (!fl) {
      ans = addmod(ans + 1ll * dfs(dep + 1, ct, 0, 0) * F(a[dep]) % mod);
      ans = addmod(ans + 1ll * dfs(dep + 1, ct, 1, 0) * (a[dep] + 1) % mod);
      ans =
          addmod(ans + 1ll * dfs(dep + 1, ct + 1, 0, 1) * F(a[dep] - 1) % mod);
      ans = addmod(ans + 1ll * dfs(dep + 1, ct + 1, 1, 1) * a[dep] % mod);
    } else {
      ans = addmod(ans + 1ll * dfs(dep + 1, ct, 0, 0) * G(a[dep]) % mod);
      ans = addmod(ans + 1ll * dfs(dep + 1, ct, 1, 0) * (b - a[dep] - 1) % mod);
      ans =
          addmod(ans + 1ll * dfs(dep + 1, ct + 1, 0, 1) * G2(a[dep] - 1) % mod);
      ans = addmod(ans + 1ll * dfs(dep + 1, ct + 1, 1, 1) * (b - a[dep]) % mod);
    }
  }
  return f[dep][ct][lim][fl] = ans;
}
int main() {
  memset(f, 0xff, sizeof(f));
  scanf("%d%d%s", &b, &k, s + 1);
  m = strlen(s + 1);
  a[1] = 0;
  n = 1;
  for (int i = 1; i <= m; i++) {
    getmul();
    getadd(s[i] - '0');
  }
  reverse(a + 1, a + n + 1);
  printf("%d\n", dfs(1, 0, 1, 0));
  return 0;
}
