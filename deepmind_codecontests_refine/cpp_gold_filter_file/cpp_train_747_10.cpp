#include <bits/stdc++.h>
using namespace std;
template <class T>
T gi() {
  T x = 0;
  bool f = 0;
  char c = getchar();
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  if (c == '-') f = 1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return f ? -x : x;
}
const int N = 1e6 + 10, Mod = 998244353;
char str[N];
int fac[N], ifac[N], c1[N], c2[N], d1[N], d2[N];
int fpow(int a, int b) {
  int res = 1;
  for (; b; b >>= 1, a = 1ll * a * a % Mod)
    if (b & 1) res = 1ll * res * a % Mod;
  return res;
}
int C(int n, int m) {
  if (n < m) return 0;
  if (n < 0 || m < 0) return 0;
  return 1ll * fac[n] * ifac[m] % Mod * ifac[n - m] % Mod;
}
int main() {
  scanf("%s", str + 1);
  int n = strlen(str + 1);
  for (int i = 1; i <= n; i++) {
    c1[i] = c1[i - 1] + (str[i] == '?');
    d1[i] = d1[i - 1] + (str[i] == '(');
  }
  for (int i = n; i; i--) {
    c2[i] = c2[i + 1] + (str[i] == '?');
    d2[i] = d2[i + 1] + (str[i] == ')');
  }
  int ans = 0;
  for (int i = fac[0] = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % Mod;
  ifac[n] = fpow(fac[n], Mod - 2);
  for (int i = n; i; i--) ifac[i - 1] = 1ll * ifac[i] * i % Mod;
  for (int i = 1; i <= n; i++) {
    int t = d2[i + 1] - d1[i];
    (ans += (1ll * d1[i] * C(c1[i] + c2[i + 1], c2[i + 1] + t) % Mod +
             1ll * c1[i] * C(c1[i] + c2[i + 1] - 1, c2[i + 1] + t - 1) % Mod) %
            Mod) %= Mod;
  }
  printf("%d\n", ans);
  return 0;
}
