#include <bits/stdc++.h>
using namespace std;
double f[100005], e[100005], p[100005];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lf", &p[i]);
  for (int i = 1; i <= n; i++) {
    e[i] = (e[i - 1] + 1.00) * p[i];
    f[i] = f[i - 1] + (2.00 * e[i - 1] + 1) * p[i];
  }
  printf("%.15lf", f[n]);
  return 0;
}
