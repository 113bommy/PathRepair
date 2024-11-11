#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7, INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long qpow(long long a, long long n) {
  long long r = 1 % P;
  for (a %= P; n; a = a * a % P, n >>= 1)
    if (n & 1) r = r * a % P;
  return r;
}
long long inv(long long first) {
  return first <= 1 ? 1 : inv(P % first) * (P - P / first) % P;
}
inline int rd() {
  int first = 0;
  char p = getchar();
  while (p < '0' || p > '9') p = getchar();
  while (p >= '0' && p <= '9') first = first * 10 + p - '0', p = getchar();
  return first;
}
const int N = 18;
int n, cnt;
long long dp[1 << N][N], f[N + 1][1 << N], h[1 << N], d[400], ans[1 << N];
char a[N][N];
map<vector<int>, int> ID;
vector<int> g[400], v;
void dfs(int d, int s) {
  if (s > n) return;
  if (s == n) {
    ID[v] = ++cnt;
    g[cnt] = v;
    return;
  }
  for (int i = d; i <= n; ++i) v.push_back(i), dfs(i, s + i), v.pop_back();
}
void FMT(long long *a, int n, int tp) {
  int mx = (1 << n) - 1;
  for (int i = 0; i <= n - 1; ++i)
    for (int j = 0; j <= mx; ++j) {
      if (j >> i & 1) a[j] += tp * a[j ^ 1 << i];
    }
}
void FMT_and(long long *a, int n, int tp) {
  int mx = (1 << n) - 1;
  for (int i = 0; i <= n - 1; ++i)
    for (int j = 0; j <= mx; ++j) {
      if (j >> i & 1) a[j ^ 1 << i] += tp * a[j];
    }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i <= n - 1; ++i) scanf("%s", a[i]);
  dfs(1, 0);
  for (int i = 0; i <= n - 1; ++i) dp[1 << i][i] = 1;
  int mx = (1 << n) - 1;
  for (int i = 0; i <= mx; ++i) {
    for (int j = 0; j <= n - 1; ++j)
      if (i >> j & 1)
        for (int k = 0; k <= n - 1; ++k)
          if (i >> k & 1 ^ 1) {
            if (a[j][k] == '1') dp[i ^ 1 << k][k] += dp[i][j];
          }
    int len = __builtin_popcount(i);
    for (int j = 0; j <= n - 1; ++j) f[len][i] += dp[i][j];
  }
  for (int i = 1; i <= n - 1; ++i) FMT(f[i], n, 1);
  for (int i = 1; i <= cnt; ++i) {
    for (int j = 0; j <= mx; ++j) h[j] = 1;
    for (int j : g[i])
      for (int k = 0; k <= mx; ++k) h[k] *= f[j][k];
    FMT(h, n, -1);
    d[i] = h[mx];
  }
  mx = (1 << n - 1) - 1;
  for (int i = 0; i <= mx; ++i) {
    v.clear();
    for (int j = 0; j <= n - 1; ++j) {
      int k = j;
      while (k < n - 1 && (i >> k & 1)) ++k;
      v.push_back(k - j + 1);
      j = k;
    }
    sort(v.begin(), v.end());
    ans[i] = d[ID[v]];
  }
  FMT_and(ans, n - 1, -1);
  for (int i = 0; i <= mx; ++i) printf("%lld ", ans[i]);
  putchar(10);
}
