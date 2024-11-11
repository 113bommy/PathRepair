#include <bits/stdc++.h>
using namespace std;
const int N = 2002000, P = 1000000007;
int i, j, k, n, m, lx, ly, nm, xa, xb, ya, yb, xc, yc, sum, a, b, g, ans, da;
int Jc[N], Jc_[N], phi[N], f[N], fg[N], pr[N], tm2[N];
char x[N], y[N];
int ksm(int x, int y) {
  int z = 1;
  for (; y; y >>= 1, x = (long long)x * x % P)
    if (y & 1) z = (long long)z * x % P;
  return z;
}
int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
void pre(int n) {
  int i, j, k;
  tm2[0] = 1;
  for (i = 1; i <= n; i++) tm2[i] = (tm2[i - 1] * 2) % P;
  Jc[0] = Jc_[0] = 1;
  for (i = 1; i <= n; i++) Jc[i] = (long long)Jc[i - 1] * i % P;
  Jc_[n] = ksm(Jc[n], P - 2);
  for (i = n - 1; i; i--) Jc_[i] = (long long)Jc_[i + 1] * (i + 1) % P;
  phi[1] = 1;
  for (i = 2; i <= n; i++) {
    if (!fg[i]) {
      pr[++nm] = i;
      phi[i] = i - 1;
    }
    for (j = 1; j <= nm; j++) {
      if (i * pr[j] > n) break;
      fg[i * pr[j]] = 1;
      if (i % pr[j] == 0) {
        phi[i * pr[j]] = phi[i] * pr[j];
        break;
      }
      phi[i * pr[j]] = phi[i] * phi[pr[j]];
    }
  }
  for (i = 1; i <= n; i++) f[i] = (phi[i] + f[i - 1]) % P;
  for (i = 1; i <= n; i++) {
    f[i] = (2 * f[i] - 1) % P;
    if (f[i] < 0) f[i] += P;
  }
}
int C(int n, int m) {
  if (n < m) return 0;
  return (long long)Jc[n] * Jc_[m] % P * Jc_[n - m] % P;
}
int main() {
  scanf("%s", x + 1);
  lx = strlen(x + 1);
  scanf("%s", y + 1);
  ly = strlen(y + 1);
  scanf("%d", &n);
  pre(2000000);
  for (i = 1; i <= n; i++) sum = ((long long)tm2[i] * f[n / i] + sum) % P;
  for (i = 1; i <= lx; i++) {
    if (x[i] == 'A') da++;
    if (x[i] == '?') xc++;
  }
  for (i = 1; i <= ly; i++) {
    if (y[i] == 'A') da--;
    if (y[i] == '?') yc++;
  }
  for (i = -yc + da; i <= xc + da; i++) {
    j = ly - lx + i;
    if (i < 0)
      a = -i, b = -j;
    else
      a = i, b = j;
    if (b < 0) continue;
    if (a && b) {
      g = gcd(a, b);
      if (a > b)
        ans = ((long long)C(xc + yc, yc - da + i) *
                   (tm2[n / (a / g) + 1] + P - 2) +
               ans) %
              P;
      else
        ans = ((long long)C(xc + yc, yc - da + i) *
                   (tm2[n / (b / g) + 1] + P - 2) +
               ans) %
              P;
      continue;
    }
    if (!a && !b) {
      ans = ((long long)C(xc + yc, yc - da + i) * sum + ans) % P;
      continue;
    }
  }
  if (lx == ly) {
    int Fg = 0, c = 0;
    for (i = 1; i <= lx; i++) {
      if (x[i] == 'A' && y[i] == 'B') {
        Fg = 1;
        break;
      }
      if (x[i] == 'B' && y[i] == 'A') {
        Fg = 1;
        break;
      }
      if (x[i] == '?' && y[i] == '?') c++;
    }
    if (!Fg) {
      int tmp = (long long)(tm2[n + 1] + P - 2) * (tm2[n + 1] + P - 2) % P;
      tmp = (tmp + P - sum) % P;
      ans = ((long long)tm2[c] * tmp + ans) % P;
    }
  }
  printf("%d\n", ans);
}
