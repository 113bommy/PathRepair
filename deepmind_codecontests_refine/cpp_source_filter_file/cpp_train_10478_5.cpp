#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000009;
const int mod = 1e9 + 7;
long long fac[maxn], inv[maxn];
int cnt[maxn], a[maxn], t[maxn];
int n, m;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
long long C(int x, int y) { return fac[x] * inv[y] % mod * inv[x - y] % mod; }
int main() {
  n = read();
  fac[0] = inv[0] = inv[1] = 1;
  for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
  for (int i = 2; i <= n; i++) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
  for (int i = 2; i <= n; i++) inv[i] = inv[i - 1] * inv[i] % mod;
  for (int i = 1; i <= n; i++) t[i] = a[i] = read();
  sort(t + 1, t + 1 + n);
  m = unique(t + 1, t + 1 + n) - t - 1;
  for (int i = 1; i <= n; i++)
    a[i] = lower_bound(t + 1, t + 1 + m, a[i]) - t, cnt[a[i]]++;
  int now = cnt[m];
  long long ans = 0;
  for (int i = m - 1; i >= 1; i--)
    if (cnt[i]) {
      now += (cnt[i] - 1);
      ans = (ans + cnt[i] * fac[now] % mod * t[i] % mod * C(n, now + 1) *
                       fac[n - now - 1] % mod) %
            mod;
      now++;
    }
  cout << ans << endl;
  return 0;
}
