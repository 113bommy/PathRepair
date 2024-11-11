#include <bits/stdc++.h>
using namespace std;
long long arrb[101];
long long arrg[101];
long long arrgcd[101];
long long gcd(long long n, long long m) {
  if (m <= n && n % m == 0) return m;
  if (n < m)
    return gcd(m, n);
  else
    return gcd(m, n % m);
}
int main() {
  long long m, n, b, g, i, G_C_D, inp;
  bool flag = true;
  cin >> n >> m >> b;
  for (i = 0; i < b; i++) {
    cin >> inp;
    arrb[i] = 1;
  }
  scanf("%lld", &g);
  for (i = 0; i < g; i++) {
    cin >> inp;
    arrg[inp] = 1;
  }
  G_C_D = gcd(m, n);
  if (G_C_D == 1 && ((b != 0) || (g != 0))) {
    printf("%s", "Yes");
  } else {
    if (m > n) {
      for (i = 0; i < n; i++) {
        arrgcd[i % G_C_D] |= arrb[i];
        arrgcd[i % G_C_D] |= arrg[i];
      }
      for (i = n; i < m; i++) {
        arrgcd[i % G_C_D] |= arrg[i];
      }
    } else if (n > m) {
      for (i = 0; i < m; i++) {
        arrgcd[i % G_C_D] |= arrb[i];
        arrgcd[i % G_C_D] |= arrg[i];
      }
      for (i = m; i < n; i++) {
        arrgcd[i % G_C_D] |= arrb[i];
      }
    } else {
      for (i = 0; i < m; i++) {
        arrgcd[i % G_C_D] |= arrb[i];
        arrgcd[i % G_C_D] |= arrg[i];
      }
    }
    for (i = 0; i < G_C_D; i++) {
      if (arrgcd[i] == 0) {
        flag = false;
        break;
      }
    }
    if (flag)
      printf("%s", "Yes");
    else
      printf("%s", "No");
  }
  return 0;
}
