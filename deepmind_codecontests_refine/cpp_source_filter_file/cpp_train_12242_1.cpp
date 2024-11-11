#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5, mod = 1e9 + 7;
char A[maxn], B[maxn];
int a, b, K, n, m;
int p[maxn];
int ksm(int x, int k) {
  int ans = 1;
  while (k) {
    if (k & 1) ans = 1ll * ans * x % mod;
    x = 1ll * x * x % mod;
    k >>= 1;
  }
  return ans;
}
inline int upd(const int &x) {
  if (x < 0) return x + mod;
  if (x >= mod) return x - mod;
  return x;
}
inline void add(int &x, const int &y) { x = upd(x + y); }
int jc[maxn], inv[maxn];
void init(int n) {
  jc[0] = 1;
  for (int i(1), endi(n); i <= endi; i++) jc[i] = 1ll * jc[i - 1] * i % mod;
  inv[n] = ksm(jc[n], mod - 2);
  for (int i(n - 1), endi(0); i >= endi; i--)
    inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
}
int C(int n, int m) {
  if (n < 0 || m < 0 || n < m) return 0;
  return 1ll * jc[n] * inv[n - m] % mod * inv[m] % mod;
}
int gcd(int a, int b) {
  if (!a) return b;
  return gcd(b % a, a);
}
int v;
int sqr(int x) { return 1ll * x * x % mod; }
int f(int a, int b) {
  if (a < 0 && b < 0) a = -a, b = -b;
  if (a < 0 || b < 0) return 0;
  if (!a && !b) {
    static int s[maxn], mu[maxn];
    mu[1] = 1;
    for (int i(1), endi(K); i <= endi; i++)
      for (int j(2), endj(K / i); j <= endj; j++) mu[i * j] -= mu[i];
    for (int i(1), endi(K); i <= endi; i++)
      for (int j(1), endj(K / i); j <= endj; j++)
        add(s[i * j], 1ll * p[i] * mu[j] % mod);
    int ans = 0;
    for (int i(1), endi(K); i <= endi; i++)
      add(ans, 1ll * sqr(K / i) * s[i] % mod);
    v = ans;
    return ans;
  }
  if (!a || !b) return 0;
  int g = gcd(a, b);
  return p[K / max(a / g, b / g) + 1] - 2;
}
int main() {
  scanf("%s%s", A + 1, B + 1);
  cin >> K;
  p[0] = 1;
  for (int i(1), endi(K + 2); i <= endi; i++) p[i] = 2ll * p[i - 1] % mod;
  int la = strlen(A + 1), lb = strlen(B + 1);
  for (int i(1), endi(la); i <= endi; i++) {
    if (A[i] == 'A')
      a++;
    else if (B[i] == 'B')
      b--;
    else
      n++;
  }
  for (int i(1), endi(lb); i <= endi; i++) {
    if (B[i] == 'A')
      a--;
    else if (B[i] == 'B')
      b++;
    else
      m++;
  }
  init(n + m);
  int ans = 0;
  for (int k(-m), endk(n); k <= endk; k++)
    add(ans, 1ll * f(a + k, b + m - n + k) * C(n + m, m + k) % mod);
  if (la == lb) {
    bool flag = 1;
    for (int i(1), endi(la); i <= endi; i++)
      if ((A[i] == 'A' && B[i] == 'B') || (A[i] == 'B' && B[i] == 'A')) {
        flag = 0;
        break;
      }
    if (flag) {
      int cnt = 0;
      for (int i(1), endi(la); i <= endi; i++)
        if (A[i] == '?' && B[i] == '?') cnt++;
      cnt = ksm(2, cnt);
      add(ans, 1ll * (sqr(p[K + 1] - 2) - v) * cnt % mod);
    }
  }
  cout << ans;
  return 0;
}
