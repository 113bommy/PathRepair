#include <bits/stdc++.h>
using namespace std;
template <class _Tp>
void ckmax(_Tp &a, _Tp b) {
  if (a < b) a = b;
}
template <class _Tp>
void ckmin(_Tp &a, _Tp b) {
  if (a > b) a = b;
}
template <class _Tp>
_Tp gcd(_Tp a, _Tp b) {
  return (b == 0) ? (a) : (gcd(b, a % b));
}
int read() {
  char ch = getchar();
  bool f = 1;
  int x = 0;
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') f = 0, ch = getchar();
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch & 15);
    ch = getchar();
  }
  return f ? x : -x;
}
const int inf = 1000000000;
const long long Inf = 1000000000000000000ll;
const long long mod = 1000000007;
bool vis[1000050];
int p[1000050], minp[1000050], cnt;
int f[1000050][22], sum[1000050][22];
int main() {
  for (int i = 2; i < 1000050; ++i) {
    if (!vis[i]) {
      p[++cnt] = i;
      minp[i] = i;
    }
    for (int j = 1; j <= cnt && i * p[j] < 1000050; ++j) {
      vis[i * p[j]] = 1;
      minp[i * p[j]] = p[j];
      if (i % p[j] == 0) break;
    }
  }
  f[0][0] = 1;
  sum[0][0] = 1;
  for (int i = 1; i < 22; ++i) {
    f[0][i] = 2;
    sum[0][i] = i * 2 + 1;
  }
  for (int i = 1; i < 1000050; ++i) {
    for (int j = 0; j < 22; ++j) f[i][j] = sum[i - 1][j];
    sum[i][0] = f[i][0];
    for (int j = 1; j < 22; ++j) sum[i][j] = (sum[i][j - 1] + f[i][j]) % mod;
  }
  int T = read();
  while (T--) {
    int r = read(), n = read();
    int ans = 1;
    int tot;
    while (n > 1) {
      int t = minp[n];
      tot = 0;
      while (minp[n] == t) n /= t, ++tot;
      ans = (1ll * ans * f[r][tot]) % mod;
    }
    printf("%d\n", ans);
  }
  return 0;
}
