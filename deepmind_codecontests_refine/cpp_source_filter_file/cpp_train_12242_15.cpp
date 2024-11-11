#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
const int MOD = 1000000007;
int n, m, i, j, k, pre[MAXN], inv[MAXN], phi[MAXN], po[MAXN], ans;
int mu[MAXN], prim[MAXN], cnt, sa, sb, sc, ta, tb, tc, sum, sam = 1, lena, lenb;
int f[MAXN];
char a[MAXN], b[MAXN];
bool ok[MAXN];
inline int get() {
  char c;
  while ((c = getchar()) < 48 || c > 57)
    ;
  int res = c - 48;
  while ((c = getchar()) >= 48 && c <= 57) res = res * 10 + c - 48;
  return res;
}
inline int gcd(int x, int y) {
  int z = x % y;
  while (z) {
    x = y;
    y = z;
    z = x % y;
  }
  return y;
}
inline int ksm(int x, int y, int z) {
  int b = 1;
  while (y) {
    if (y & 1) b = b * (long long)x % z;
    x = x * (long long)x % z;
    y >>= 1;
  }
  return b;
}
inline int C(int n, int m) {
  return (long long)pre[n] * inv[m] % MOD * inv[n - m] % MOD;
}
inline int solve(int p, int q, int d) {
  if (!p && !q) {
    int A = C(sc + tc, tc + d) - sam;
    if (A < 0) A += MOD;
    int B = (po[n + 1] - 2 + MOD) * (long long)(po[n + 1] - 2 + MOD) % MOD;
    return ((long long)A * sum + sam * (long long)B) % MOD;
  }
  if ((p >= 0 && q >= 0) || (p <= 0 && q <= 0))
    return 0;
  else {
    if (p < 0) p = -p;
    if (q < 0) q = -q;
    int A = C(sc + tc, tc + d);
    int g = gcd(p, q);
    int B = po[n / (max(p, q) / g) + 1] - 2;
    if (B < 0) B += MOD;
    return A * (long long)B % MOD;
  }
}
int main() {
  pre[0] = 1;
  for (i = 1; i <= 600000; i++) pre[i] = pre[i - 1] * (long long)i % MOD;
  inv[600000] = ksm(pre[600000], MOD - 2, MOD);
  for (i = 599999; i >= 0; i--) inv[i] = inv[i + 1] * (long long)(i + 1) % MOD;
  scanf("%s", a + 1);
  scanf("%s", b + 1);
  lena = strlen(a + 1);
  lenb = strlen(b + 1);
  cin >> n;
  for (i = 1; i <= lena; i++)
    if (a[i] == 'A')
      sa++;
    else if (a[i] == 'B')
      sb++;
    else
      sc++;
  for (i = 1; i <= lenb; i++)
    if (b[i] == 'A')
      ta++;
    else if (b[i] == 'B')
      tb++;
    else
      tc++;
  if (lena == lenb) {
    for (i = 1; i <= lena; i++)
      if (a[i] == b[i] && a[i] == '?')
        sam = sam * 2 % MOD;
      else if (a[i] == 'A' && b[i] == 'B')
        sam = 0;
      else if (a[i] == 'B' && b[i] == 'A')
        sam = 0;
  }
  mu[1] = 1;
  for (i = 2; i <= n; i++) {
    if (!ok[i]) prim[++cnt] = i, mu[i] = -1, phi[i] = i - 1;
    for (j = 1; j <= cnt && prim[j] * i <= n; i++) {
      ok[i * prim[j]] = 1;
      if (i % prim[j] == 0) {
        mu[i * prim[j]] = 0;
        phi[i * prim[j]] = phi[i] * prim[j];
        break;
      } else
        mu[i * prim[j]] = -mu[i], phi[i * prim[j]] = phi[i] * phi[prim[j]];
    }
  }
  po[0] = 1;
  for (i = 1; i <= n + 1; i++) po[i] = po[i - 1] * 2 % MOD;
  f[1] = 1;
  for (i = 2; i <= n; i++)
    f[i] = f[i - 1] + 2 * phi[i], (f[i] >= MOD) ? f[i] -= MOD : f[i];
  for (i = 1; i <= n; i++)
    sum = ((long long)sum + po[i] * (long long)f[n / i]) % MOD;
  int p = sa - ta, q = sb - tb + sc - tc;
  for (i = -tc; i <= sc; i++) ans = (ans + solve(p + i, q - i, i)) % MOD;
  cout << ans << endl;
}
