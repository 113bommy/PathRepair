#include <bits/stdc++.h>
using namespace std;
const int mo = 998244353;
const int N = 3005;
int n, c, a[N];
void UPD(int &x, int y) { (x += y) >= mo ? x -= mo : 233; }
namespace solver1 {
long long f[N][(1 << 12) + 5];
void solve() {
  f[0][0] = 1;
  int L = (1 << c) - 1;
  int S = 0, ST = 0;
  for (int i = (int)(1); i <= (int)(n); i++) {
    int sta = 1 << (a[i] - 1);
    for (int j = (int)(0); j <= (int)(S); j++)
      for (int k = (int)(L); k >= (int)(0); k--) f[j][k | sta] += f[j][k];
    for (int j = (int)(0); j <= (int)(S); j++)
      f[j + 1][0] += f[j][L], f[j][L] = 0;
    ST |= sta;
    if (ST == L) ST = 0, S++;
    if (i % 18 == 0 || i == n)
      for (int j = (int)(0); j <= (int)(S); j++)
        for (int k = (int)(0); k <= (int)(L); k++) f[j][k] %= mo;
  }
  for (int i = (int)(0); i <= (int)(n / c); i++) {
    int ans = 0;
    for (int j = (int)(0); j <= (int)(L); j++) UPD(ans, f[i][j]);
    if (i == 0) UPD(ans, mo - 1);
    printf("%d ", ans);
  }
  for (int i = (int)(n / c + 1); i <= (int)(n); i++) printf("%d ", 0);
}
}  // namespace solver1
namespace solver2 {
int power(int x, int y) {
  int s = 1;
  for (; y; y /= 2, x = 1ll * x * x % mo)
    if (y & 1) s = 1ll * s * x % mo;
  return s;
}
int V[N], IV[N], tr2[N];
int cnt[N], tr1[N][N];
long long f[N][N];
void solve() {
  for (int i = (int)(0); i <= (int)(n); i++) {
    V[i] = power(2, i) - 1;
    IV[i] = power(V[i], mo - 2);
  }
  for (int i = (int)(1); i <= (int)(n); i++) {
    for (int j = (int)(1); j <= (int)(c); j++) cnt[j] = 0;
    int GG = c, val = 1;
    for (int j = (int)(i); j <= (int)(n); j++) {
      if (!cnt[a[j]])
        --GG;
      else
        val = 1ll * val * IV[cnt[a[j]]] % mo;
      tr1[i][j] = (GG ? 0 : val);
      val = 1ll * val * V[++cnt[a[j]]] % mo;
    }
    tr2[i] = power(2, n - i + 1);
    UPD(tr2[i], mo - (GG ? 0 : val));
  }
  f[0][0] = tr2[n + 1] = 1;
  for (int i = (int)(0); i <= (int)(n / c); i++)
    for (int j = (int)(i * c + c); j <= (int)(n); j++) {
      unsigned long long tmp = 0;
      for (int k = (int)(i * c); k <= (int)(j - c); k++) {
        tmp += 1ll * f[i][k] * tr1[k + 1][j];
        if ((k & 15) == 15) tmp %= mo;
      }
      f[i + 1][j] = tmp;
    }
  for (int i = (int)(0); i <= (int)(n / c); i++) {
    int ans = 0;
    for (int j = (int)(0); j <= (int)(n); j++)
      UPD(ans, 1ll * f[i][j] * tr2[j + 1] % mo);
    if (i == 0) UPD(ans, mo - 1);
    printf("%d ", ans);
  }
  for (int i = (int)(n / c + 1); i <= (int)(n); i++) printf("%d ", 0);
}
}  // namespace solver2
int main() {
  scanf("%d%d", &n, &c);
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%d", &a[i]);
  if (c <= 11)
    solver1::solve();
  else
    solver2::solve();
}
