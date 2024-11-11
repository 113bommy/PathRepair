#include <bits/stdc++.h>
using namespace std;
int n, m;
int f[16010], fi[16010], b[16010];
int lgput(int nr, int e) {
  if (e == 0) return 1;
  int aux = lgput(nr, e / 2);
  aux = (1LL * aux * aux) % 1000000009;
  if (e % 2) aux = (1LL * aux * nr) % 1000000009;
  return aux;
}
long long getComb(int nn, int k) {
  return (((1LL * f[nn] * fi[k]) % 1000000009) * fi[nn - k]) % 1000000009;
}
int main() {
  scanf("%d", &n);
  f[0] = fi[0] = 1;
  for (int i = 1; i <= 4 * n; ++i) {
    f[i] = (1LL * f[i - 1] * i) % 1000000009;
    fi[i] = (1LL * fi[i - 1] * lgput(i, 1000000009 - 2)) % 1000000009;
  }
  int sol = 1;
  b[0] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < i; ++j)
      b[i] = (b[i] + 1LL * b[j] * getComb(i - 1, j)) % 1000000009;
  for (int i = 1; i < n; ++i)
    sol = (sol + 1LL * b[i] * getComb(n, n - i)) % 1000000009;
  printf("%d\n", (int)sol);
  return 0;
}
