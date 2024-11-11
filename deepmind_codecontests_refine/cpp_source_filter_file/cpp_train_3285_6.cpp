#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
const int MOD = 998244353;
inline int inc(int a, int b) {
  return (a + b >= MOD) ? (a + b - MOD) : (a + b);
}
inline int dec(int a, int b) { return (a >= b) ? (a - b) : (a + MOD - b); }
inline int mul(int a, int b) { return 1LL * a * b % MOD; }
inline int power(int x, int k) {
  int tmp = 1;
  while (k) {
    if (k & 1) tmp = mul(tmp, x);
    x = mul(x, x);
    k >>= 1;
  }
  return tmp;
}
int n, a[maxn], b[maxn], s1, s2, s3, s4, sfa[maxn], S[maxn][maxn];
int f[maxn], g[maxn], fac[maxn], ifac[maxn];
int findfa(int u) { return (sfa[u] == u) ? (u) : (sfa[u] = findfa(sfa[u])); }
inline int C(int n, int m) {
  if (n < 0 || m < 0 || n < m) return 0;
  return mul(fac[n], mul(ifac[m], ifac[n - m]));
}
inline int A(int n, int m) {
  if (n < 0 || m < 0) return 0;
  return mul(fac[n], ifac[n - m]);
}
int vis[maxn], d[maxn], nxt[maxn];
void dfs(int u, int fa) {
  vis[u] = 1;
  if (nxt[u]) {
    if (!vis[nxt[u]])
      dfs(nxt[u], fa);
    else
      s3++;
  } else {
    if (u > n && fa > n) s4++;
    if (fa > n && u <= n) s2++;
    if (fa <= n && u > n) s1++;
  }
}
inline void prepare() {
  s1 = s2 = s3 = s4 = 0;
  for (int i = 1; i <= n * 2; i++) sfa[i] = i;
  fac[0] = ifac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = mul(fac[i - 1], i);
  ifac[n] = power(fac[n], MOD - 2);
  for (int i = n - 1; i >= 1; i--) ifac[i] = mul(ifac[i + 1], i + 1);
  S[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      S[i][j] = inc(mul(i - 1, S[i - 1][j]), S[i - 1][j - 1]);
    }
  }
  for (int i = 1; i <= (n << 1); i++) vis[i] = 1;
  for (int i = 1; i <= n; i++) {
    int tmp1 = (a[i]) ? (a[i]) : (i + n);
    int tmp2 = (b[i]) ? (b[i]) : (i + n);
    vis[tmp1] = 0;
    vis[tmp2] = 0;
    if (tmp1 <= n || tmp2 <= n) {
      nxt[tmp1] = tmp2;
      d[tmp2]++;
    }
  }
  for (int i = 1; i <= (n << 1); i++)
    if (!vis[i] && !d[i]) {
      dfs(i, i);
    }
  for (int i = 1; i <= (n << 1); i++)
    if (!vis[i]) {
      dfs(i, i);
    }
}
int F[maxn];
inline void get_val(int *dp, int s) {
  for (int k = 0; k <= s; k++) {
    F[k] = 0;
    for (int i = k; i <= s; i++) {
      int tmp = mul(mul(C(s, i), S[i][k]), A(s + s4 - i, s - i));
      F[k] = inc(F[k], tmp);
    }
  }
  for (int k = 0; k <= s; k++) {
    dp[k] = 0;
    for (int i = k; i <= s; i++) {
      int kd = ((i - k) & 1) ? (MOD - 1) : (1);
      int tmp = mul(kd, F[i]);
      tmp = mul(tmp, C(i, k));
      dp[k] = inc(dp[k], tmp);
    }
  }
}
int ans[maxn], Ans[maxn];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  prepare();
  get_val(f, s1);
  get_val(g, s2);
  for (int i = 0; i <= n; i++) {
    ans[i] = 0;
    for (int j = 0; j <= n; j++) {
      ans[i] = inc(ans[i], mul(f[j], g[i - j]));
    }
  }
  for (int i = 0; i <= n; i++) {
    Ans[i] = 0;
    for (int j = 0; j <= i; j++) {
      int tmp = mul(ans[j], S[s4][i - j]);
      Ans[i] = inc(Ans[i], tmp);
    }
  }
  for (int i = 0; i < n; i++) Ans[i] = mul(Ans[i], fac[s4]);
  for (int i = 0; i < n; i++) printf("%d ", Ans[n - i - s3]);
  puts("");
  return 0;
}
