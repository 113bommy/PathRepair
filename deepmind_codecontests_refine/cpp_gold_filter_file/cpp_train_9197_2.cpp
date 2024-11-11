#include <bits/stdc++.h>
using namespace std;
const int maxN = 53;
const int maxG = 45;
const int mod = (1e9) + 7;
struct tl {
  int a[maxN][maxN];
} a;
int cs[300], m, k;
long long n;
void init() {
  scanf("%I64d%i%i\n", &n, &m, &k);
  for (int i = 0; i < 26; i++) {
    cs['a' + i] = i;
    cs['A' + i] = 26 + i;
  }
  for (int i = 0; i < m; i++)
    for (int j = 0; j < m; j++) a.a[i][j] = 1;
  for (int i = 0; i < k; i++) {
    char c1, c2;
    scanf("%c%c\n", &c1, &c2);
    a.a[cs[c1]][cs[c2]] = 0;
  }
}
tl operator*(tl x, tl y) {
  tl z;
  memset(z.a, 0, sizeof(z.a));
  for (int i = 0; i < m; i++)
    for (int j = 0; j < m; j++)
      for (int k = 0; k < m; k++)
        z.a[i][j] = (1ll * x.a[i][k] * y.a[k][j] + z.a[i][j]) % mod;
  return z;
}
tl mu(tl x, long long y) {
  tl z, tam;
  tam = x;
  bool ok = true;
  while (y > 0) {
    if (y % 2 == 1)
      if (ok) {
        z = tam;
        ok = false;
      } else
        z = z * tam;
    tam = tam * tam;
    y /= 2;
  }
  return z;
}
void xuly() {
  if (n == 1)
    cout << m;
  else {
    a = mu(a, n - 1);
    long long ans = 0;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < m; j++) ans = (ans + a.a[i][j]) % mod;
    printf("%i\n", (ans + mod) % mod);
  }
}
int main() {
  init();
  xuly();
  fclose(stdin);
  fclose(stdout);
  return 0;
}
