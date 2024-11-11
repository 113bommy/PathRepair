#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  double m;
  while (~scanf("%d%lf", &n, &m)) {
    int a[25], b[25];
    double c[25];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) c[i] = (double)b[i] / a[i];
    double mi = c[0];
    for (int i = 1; i < n; i++) mi = min(mi, c[i]);
    double sum = 0;
    for (int i = 0; i < n; i++) {
      sum += mi * a[i];
    }
    if (sum > m)
      printf("%.4f\n", m);
    else
      printf("%.4f\n", sum);
  }
  return 0;
}
