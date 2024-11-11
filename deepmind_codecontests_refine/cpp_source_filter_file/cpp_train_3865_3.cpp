#include <bits/stdc++.h>
using namespace std;
const long long int K = 998244353;
long long int f[1055][25][25], d[1055][25][25];
long long int vsf[1055][25][25], vsd[1055][25][25];
long long int sf[1055][25][25], sd[1055][25][25];
long long int vssf[1055][25][25], vssd[1055][25][25];
long long int mu[24];
long long int k, a[20];
long long int calc_f(long long int bit, long long int n, long long int st) {
  if (n == -1) {
    if (bit == 0 && st == 0) return 1;
    return 0;
  }
  if (__builtin_popcountll(bit) > k || (bit & (1 << st)) == 0) return 0;
  if (vsf[bit][n][st]) return f[bit][n][st];
  vsf[bit][n][st] = 1;
  long long int Res = 0;
  for (int i = 0; i <= 9; i++) {
    if ((bit & (1 << st)))
      Res =
          (Res + calc_f(bit, n - 1, i) + calc_f(bit - (1 << st), n - 1, i)) % K;
  }
  return f[bit][n][st] = Res;
}
long long int calc_sf(long long int bit, long long int n, long long int st) {
  if (n == -1) {
    return 0;
  }
  if (__builtin_popcountll(bit) > k || (bit & (1 << st)) == 0) return 0;
  if (vssf[bit][n][st]) return sf[bit][n][st];
  vssf[bit][n][st] = 1;
  long long int Res = 0;
  for (int i = 0; i <= 9; i++) {
    if ((bit & (1 << st))) {
      Res =
          (Res + calc_sf(bit, n - 1, i) + calc_sf(bit - (1 << st), n - 1, i)) %
          K;
    }
  }
  Res = (Res + st * mu[n] % K * calc_f(bit, n, st) % K) % K;
  return sf[bit][n][st] = Res;
}
long long int calc_d(long long int bit, long long int n, long long int st) {
  if (n == -1) {
    if (bit == 0 && st == 0) return 1;
    return 0;
  }
  if (__builtin_popcountll(bit) > k || st > a[n] || (bit & (1 << st)) == 0)
    return 0;
  if (vsd[bit][n][st]) return d[bit][n][st];
  vsd[bit][n][st] = 1;
  long long int Res = 0;
  if (st == a[n]) {
    Res = (calc_d(bit, n - 1, a[n - 1]) +
           calc_d(bit - (1 << st), n - 1, a[n - 1]));
    Res %= K;
    for (int i = 0; i <= a[n - 1] - 1; i++) {
      Res =
          (Res + calc_f(bit, n - 1, i) + calc_f(bit - (1 << st), n - 1, i)) % K;
    }
  } else if (st < a[n]) {
    Res = calc_f(bit, n, st);
  }
  return d[bit][n][st] = Res;
}
long long int calc_sd(long long int bit, long long int n, long long int st) {
  if (n == -1) {
    return 0;
  }
  if (__builtin_popcountll(bit) > k || st > a[n] || (bit & (1 << st)) == 0)
    return 0;
  if (vssd[bit][n][st]) return sd[bit][n][st];
  vssd[bit][n][st] = 1;
  long long int Res = 0;
  if (st == a[n]) {
    Res = (calc_sd(bit, n - 1, a[n - 1]) +
           calc_sd(bit - (1 << st), n - 1, a[n - 1]));
    Res %= K;
    for (int i = 0; i <= a[n - 1] - 1; i++) {
      Res =
          (Res + calc_sf(bit, n - 1, i) + calc_sf(bit - (1 << st), n - 1, i)) %
          K;
    }
    Res = (Res + st * mu[n] % K * calc_d(bit, n, st) % K) % K;
  } else if (st < a[n]) {
    Res = calc_sf(bit, n, st);
  }
  return sd[bit][n][st] = Res;
}
void pre(long long int r) {
  int C = -1;
  while (r) {
    a[++C] = r % 10;
    r /= 10;
  }
}
long long int calc(long long int r) {
  if (r == 0) return 0;
  int C = -1;
  for (int i = 0; i <= 1024; i++) {
    for (int j = 0; j <= 10; j++) {
      for (int k = 0; k <= 10; k++) {
        vssf[i][j][k] = vssd[i][j][k] = vsf[i][j][k] = vsd[i][j][k] = 0;
      }
    }
  }
  while (r) {
    a[++C] = r % 10;
    r /= 10;
  }
  long long int Res = 0;
  for (int i = 1; i <= 1023; i++) {
    if (__builtin_popcountll(i) <= k) {
      for (int j = 1; j <= 9; j++) {
        for (int z = 0; z <= C - 1; z++) {
          Res = (Res + calc_sf(i, z, j)) % K;
        }
        Res = (Res + calc_sd(i, C, j)) % K;
      }
    }
  }
  return Res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  mu[0] = 1;
  for (int i = 1; i <= 18; i++) mu[i] = mu[i - 1] * 10 % K;
  long long int l, r;
  cin >> l >> r >> k;
  long long int res = (calc(r) - calc(l - 1) + K) % K;
  cout << res << endl;
  return 0;
}
