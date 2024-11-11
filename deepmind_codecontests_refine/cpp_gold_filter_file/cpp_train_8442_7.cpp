#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int maxn = 200005;
int fac[maxn], rev[maxn], a[maxn], b[maxn];
int n, m, c00, c01, c10, c11;
char A[maxn], B[maxn];
inline int power(int x, int p) {
  int res = 1;
  while (p) {
    if (p & 1) res = 1ll * res * x % mod;
    x = 1ll * x * x % mod;
    p >>= 1;
  }
  return res;
}
void init() {
  fac[0] = rev[0] = 1;
  for (int i = (1), _E = (maxn - 1); i <= _E; i++) {
    fac[i] = 1ll * fac[i - 1] * i % mod;
    rev[i] = power(fac[i], mod - 2);
  }
}
inline int C(int n, int m) {
  if (m < 0 || m > n) return 0;
  return 1ll * fac[n] * rev[m] % mod * rev[n - m] % mod;
}
int chk(int a[maxn], int n) {
  int C00 = 0, C01 = 0, C10 = 0, C11 = 0;
  for (int i = (1), _E = (n - 1); i <= _E; i++)
    if (!a[i] && !a[i + 1])
      C00++;
    else if (!a[i] && a[i + 1])
      C10++;
    else if (a[i] && !a[i + 1])
      C01++;
    else
      C11++;
  return C00 == c00 && C01 == c01 && C10 == c10 && C11 == c11;
}
int cut(int n, int m) {
  if (!n && !m) return 1;
  return C(n + m - 1, m - 1);
}
int f(int c00, int c01, int c10, int c11, int head) {
  if (c00 < 0 || c01 < 0 || c10 < 0 || c11 < 0) return 0;
  if (head == 1) swap(c00, c11), swap(c01, c10);
  if (c10 == c01 - 1)
    return 1ll * cut(c00, c01) * cut(c11, c01) % mod;
  else if (c10 == c01)
    return 1ll * cut(c00, c01 + 1) * cut(c11, c01) % mod;
  return 0;
}
int solve(int a[maxn], int n) {
  if (c00 + c01 + c10 + c11 + 1 > n) return 0;
  if (c00 + c01 + c10 + c11 + 1 < n) return f(c00, c01, c10, c11, 1);
  int ans = 0, C00 = 0, C01 = 0, C10 = 0, C11 = 0;
  for (int i = (n - 1), _E = (1); i >= _E; i--) {
    if (a[i])
      ans = (ans + f(c00 - C00 - !a[i + 1], c01 - C01, c10 - C10 - a[i + 1],
                     c11 - C11, 0)) %
            mod;
    if (!a[i] && !a[i + 1])
      C00++;
    else if (!a[i] && a[i + 1])
      C10++;
    else if (a[i] && !a[i + 1])
      C01++;
    else
      C11++;
  }
  return ans;
}
int main() {
  init();
  scanf("%s%s", A, B);
  scanf("%d%d%d%d", &c00, &c01, &c10, &c11);
  n = strlen(A);
  m = strlen(B);
  for (int i = 0, _E = (n); i < _E; i++) a[i + 1] = A[n - 1 - i] - '0';
  for (int i = 0, _E = (m); i < _E; i++) b[i + 1] = B[m - 1 - i] - '0';
  int ans = solve(b, m) - solve(a, n) + chk(b, m);
  while (ans < 0) ans += mod;
  while (ans >= mod) ans -= mod;
  cout << ans << endl;
  return 0;
}
