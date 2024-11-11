#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T &x, T y) {
  return y < x ? x = y, 1 : 0;
}
template <class T>
bool umax(T &x, T y) {
  return y > x ? x = y, 1 : 0;
}
const int N = 3e5 + 5, mod = 1e9 + 7;
char x[N], y[N];
int n, mu[2 * N], pr[N], tot, W, sum[N * 2], pi[N * 2], iv[N * 2];
bool notpr[N * 2];
int qpow(int x, int y) {
  int res = 1;
  for (int i = 0; (1 << i) <= y; ++i, x = 1ll * x * x % mod)
    if (y & (1 << i)) res = 1ll * res * x % mod;
  return res;
}
void Init() {
  tot = 0;
  mu[1] = 1;
  for (int i = 2; i < 2 * N; ++i) {
    if (!notpr[i]) {
      pr[++tot] = i;
      mu[i] = -1;
    }
    for (int j = 1; j <= tot && pr[j] * i < 2 * N; ++j) {
      notpr[pr[j] * i] = 1;
      if (i % pr[j] == 0) {
        mu[i * pr[j]] = 0;
        break;
      }
      mu[i * pr[j]] = -mu[i];
    }
  }
  W = 0;
  for (int k = 1, po = 2; k <= n; ++k, po = 2ll * po % mod) {
    int T = 0;
    for (int d = 1; d <= n / k; ++d) {
      T = T + 1ll * mu[d] * (n / (d * k)) * (n / (d * k)) % mod;
      T = (T % mod + mod) % mod;
    }
    W = (W + 1ll * po * T % mod) % mod;
  }
  sum[0] = 0;
  pi[0] = 1;
  for (int i = 1, po = 2; i < N * 2; ++i, po = 2ll * po % mod) {
    sum[i] = (sum[i - 1] + po) % mod;
    pi[i] = 1ll * pi[i - 1] * i % mod;
  }
  iv[N * 2 - 1] = qpow(pi[N * 2 - 1], mod - 2);
  for (int i = N * 2 - 2; i >= 0; --i) iv[i] = 1ll * iv[i + 1] * (i + 1) % mod;
}
int C(int n, int m) {
  if (m < 0 || m > n) return 0;
  return 1ll * pi[n] * iv[m] % mod * iv[n - m] % mod;
}
int gcd(int x, int y) { return !y ? x : gcd(y, x % y); }
int f(int a, int b) {
  if (a == 0 && b == 0) return W;
  if (1ll * a * b >= 0) return 0;
  a = abs(a);
  b = abs(b);
  int g = gcd(a, b);
  return sum[n / max(a / g, b / g)];
}
signed main() {
  scanf("%s", x + 1);
  scanf("%s", y + 1);
  scanf("%d", &n);
  Init();
  int xa = 0, xb = 0, ya = 0, yb = 0, xq = 0, yq = 0;
  for (int i = 1; i <= (int)strlen(x + 1); ++i) {
    if (x[i] == 'A') xa++;
    if (x[i] == 'B') xb++;
    if (x[i] == '?') xq++;
  }
  for (int i = 1; i <= (int)strlen(y + 1); ++i) {
    if (y[i] == 'A') ya++;
    if (y[i] == 'B') yb++;
    if (y[i] == '?') yq++;
  }
  int a, b, ans = 0;
  a = xa - ya;
  b = xb - yb;
  for (int k = -yq; k <= xq; ++k) {
    ans = (ans + 1ll * f(a + k, b + xq - yq - k) * C(xq + yq, yq + k) % mod) %
          mod;
  }
  if (strlen(x + 1) == strlen(y + 1)) {
    int T = 1;
    for (int i = 1; i <= (int)strlen(x + 1); ++i) {
      if (x[i] == '?' || y[i] == '?') {
        if (x[i] == y[i]) T = 2ll * T % mod;
      } else if (x[i] != y[i])
        T = 0;
    }
    ans = ans + 1ll * T * (1ll * sum[n] * sum[n] % mod - W + mod) % mod;
    ans = (ans % mod + mod) % mod;
  }
  cout << ans << "\n";
  return 0;
}
