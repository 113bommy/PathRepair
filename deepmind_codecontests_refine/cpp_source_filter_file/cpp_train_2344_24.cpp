#include <bits/stdc++.h>
using namespace std;
int n, a[1000001];
long long x, y, p, s, f[3][3], f2[3][3], fx[3][3];
void Do(long long x) {
  if (x == 1ll) {
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) f[i][j] = 0ll;
    f[0][0] = 3ll;
    f[1][0] = f[2][0] = -1ll;
    f[1][1] = f[2][2] = 1ll;
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) fx[i][j] = f[i][j];
    return;
  }
  Do(x / 2ll);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      f2[i][j] = 0ll;
      for (int k = 0; k < 3; k++)
        f2[i][j] += (f[i][k] * f[k][j]) % p, f2[i][j] %= p;
    }
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) f[i][j] = f2[i][j];
  if (x & (1ll)) {
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) {
        f2[i][j] = 0ll;
        for (int k = 0; k < 3; k++)
          f2[i][j] += (f[i][k] * fx[k][j]) % p, f2[i][j] %= p;
      }
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) f[i][j] = f2[i][j];
  }
}
void Do2(long long x) {
  if (x == 1ll) {
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++) f[i][j] = 1ll;
    f[1][1] = 0ll;
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++) fx[i][j] = f[i][j];
    return;
  }
  Do(x / 2ll);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) {
      f2[i][j] = 0ll;
      for (int k = 0; k < 2; k++)
        f2[i][j] += (f[i][k] * f[k][j]) % p, f2[i][j] %= p;
    }
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) f[i][j] = f2[i][j];
  if (x & (1ll)) {
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++) {
        f2[i][j] = 0ll;
        for (int k = 0; k < 2; k++)
          f2[i][j] += (f[i][k] * fx[k][j]) % p, f2[i][j] %= p;
      }
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++) f[i][j] = f2[i][j];
  }
}
int main() {
  scanf("%d", &n);
  scanf("%I64d %I64d %I64d", &x, &y, &p);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]), s += 1ll * a[i], s %= p;
  if (n != 1) {
    if (x != 0ll) {
      Do(x);
      s = (s * f[0][0]) % p +
          ((1ll * a[0] * f[1][0]) % p + (1ll * a[n - 1] * f[2][0]) % p);
      s %= p;
      s += p;
      s %= p;
      Do2(x);
      a[n - 1] = (a[n - 1] * f[0][0]) % p + (a[n - 2] * f[0][1]) % p;
      a[n - 1] %= p;
    }
    if (y != 0ll) {
      Do(y);
      s = (s * f[0][0]) % p +
          ((1ll * a[0] * f[1][0]) % p + (1ll * a[n - 1] * f[2][0]) % p);
      s %= p;
      s += p;
      s %= p;
    }
  }
  printf("%I64d\n", s);
  return 0;
}
