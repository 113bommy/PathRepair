#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long double eps = 1e-7;
const int inf = 1000000010;
const long long INF = 10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 110, LOG = 20;
struct MAT {
  long long a[MAXN][MAXN];
  MAT() {
    for (int i = 0; i < MAXN; i++)
      for (int j = 0; j < MAXN; j++) a[i][j] = 0;
  }
  void relax() {
    for (int i = 0; i < MAXN; i++)
      for (int j = 0; j < MAXN; j++) a[i][j] %= mod;
  }
} T;
void zarb(MAT &m1, MAT &m2) {
  MAT tmp;
  for (int i = 0; i < MAXN; i++)
    for (int j = 0; j < MAXN; j++)
      for (int k = 0; k < MAXN; k++)
        tmp.a[i][j] += m1.a[i][k] * m2.a[k][j] % mod;
  tmp.relax();
  for (int i = 0; i < MAXN; i++)
    for (int j = 0; j < MAXN; j++) m1.a[i][j] = tmp.a[i][j];
}
void tavan(MAT &M, int x) {
  MAT tmp;
  for (int i = 0; i < MAXN; i++)
    for (int j = 0; j < MAXN; j++) tmp.a[i][j] = M.a[i][j];
  x--;
  for (; x; x >>= 1, zarb(tmp, tmp))
    if (x & 1) zarb(M, tmp);
}
long long n, m, k, u, v, x, y, t, a, b, ans;
long long C[45][45];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (int i = 0; i < 45; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
  }
  for (int i = 0; i <= 40; i++)
    for (int j = 0; j <= 40; j++)
      T.a[i][j + 41] = T.a[i + 41][j] = T.a[i + 41][j + 41] = C[i][j];
  T.a[82][82] = 1;
  cin >> n >> k;
  T.a[82][41 + k] = 1;
  tavan(T, n);
  for (int i = 0; i < 82; i++) ans = (ans + T.a[82][i]) % mod;
  cout << ans << '\n';
  return 0;
}
