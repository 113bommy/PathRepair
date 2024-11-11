#include <bits/stdc++.h>
using namespace std;
typedef long long mat[100][100];
const long long N = 1e2, mod = 1e9 + 7;
long long n, b, k, x, mark[N + 10];
mat base, a1, ans;
void mul(mat a, mat b, mat c) {
  for (long long i = 0; i < N; i++)
    for (long long j = 0; j < N; j++) c[i][j] = 0;
  for (long long i = 0; i < N; i++)
    for (long long j = 0; j < N; j++)
      for (long long k = 0; k < N; k++)
        c[i][j] = (c[i][j] + (a[i][k] * b[k][j]) % mod) % mod;
}
void swp(mat a, mat b) {
  for (long long i = 0; i < N; i++)
    for (long long j = 0; j < N; j++) swap(a[i][j], b[i][j]);
}
void power(long long k, mat a) {
  mat b, c;
  for (long long i = 0; i < N; i++)
    for (long long j = 0; j < N; j++) {
      if (i == j)
        b[i][j] = 1;
      else
        b[i][j] = 0;
    }
  for (; k; k /= 2) {
    if (k % 2) {
      mul(a, b, c);
      swp(b, c);
    }
    mul(a, a, c);
    swp(a, c);
  }
  swp(a, b);
}
int main() {
  cin >> n >> b >> k >> x;
  for (long long i = 0; i < n; i++) {
    long long a;
    cin >> a;
    a %= x;
    mark[a]++;
  }
  if (b == 1) return cout << mark[k], 0;
  for (long long i = 0, u = x - 1; i < x; i++, u--) {
    for (long long j = 0, l = x - 1; j < x; j++, l--) {
      for (long long k = 0; k < x; k++) {
        if ((10 * l + k) % x == u) base[i][j] = (base[i][j] + mark[k]) % mod;
      }
    }
  }
  for (long long i = 0, k = x - 1; i < x; i++, k--) a1[i][0] = mark[k];
  power(b - 1, base);
  mul(base, a1, ans);
  cout << ans[x - (k + 1)][0];
}
