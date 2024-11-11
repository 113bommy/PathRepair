#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7, p = 998244353;
int n, ans, w[N], g[N], q[N], fac[N], ifac[N];
bool fl[N];
inline int read() {
  int num = 0;
  char g = getchar();
  while (g < 48 || 57 < g) g = getchar();
  while (47 < g && g < 58)
    num = (num << 1) + (num << 3) + g - 48, g = getchar();
  return num;
}
inline int pows(long long u, int v) {
  long long ans = 1;
  while (v > 0) {
    if (v & 1) ans = ans * u % p;
    u = u * u % p, v = v >> 1;
  }
  return ans;
}
inline int binom(int a, int b) {
  if (a < b) return 0;
  return 1ll * fac[a] * ifac[b] % p * ifac[a - b] % p;
}
int main() {
  n = read(), fac[0] = ifac[0] = 1;
  for (int i = 1; i <= n; i++) w[i] = read() + 1;
  for (int i = 1; i <= 1000000; i++)
    fac[i] = 1ll * fac[i - 1] * i % p, ifac[i] = pows(fac[i], p - 2);
  sort(w + 1, w + n + 1), w[n + 1] = 1919810;
  for (int i = 1; i <= n; i++) {
    if (w[i] < i) break;
    fl[i] = 1;
  }
  for (int i = 1; i <= n; i++) {
    int op = i - 1;
    if (!fl[i]) continue;
    for (int j = 0; j < w[i]; j++) {
      q[j % n] += g[j];
      ans = (ans + binom(j - op + n - 2, n - 2)) % p;
      op += q[(j + 1) % n];
    }
    g[w[i]]++;
    for (int j = 1; j <= w[i]; j++) g[j % n] = 0;
  }
  cout << ans << endl;
}
