#include <bits/stdc++.h>
using namespace std;
int a[300], d, m;
double dd, mm;
int main() {
  int i, k, n;
  for (scanf("%d", &n); n--;) {
    k = 250;
    m = 0;
    d = 0;
    while (k--) {
      scanf("%d", &i);
      m += i;
      d += i * i;
    }
    mm = 250.0 * d / m / m;
    if (mm < 1.2)
      puts("poisson");
    else
      puts("uniform");
  }
}
