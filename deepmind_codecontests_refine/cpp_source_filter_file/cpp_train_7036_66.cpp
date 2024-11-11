#include <bits/stdc++.h>
using namespace std;
int a[300];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n = 250;
    double m = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      m += a[i];
    }
    m /= n;
    double pom = 0;
    for (int i = 1; i <= n; i++) pom += abs((double)a[i] - m);
    pom /= n;
    if (pom > 0.4 * m)
      printf("uniform\n");
    else
      printf("poisson\n");
  }
  return 0;
}
