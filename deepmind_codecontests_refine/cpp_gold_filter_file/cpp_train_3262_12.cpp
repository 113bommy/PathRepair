#include <bits/stdc++.h>
using namespace std;
int a[101];
int main() {
  int n, f, total = 0;
  scanf("%d%d", &n, &f);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    total += a[i];
  }
  bool ans = true;
  double m = (total + f) * 1.0 / n;
  for (int i = 0; i < n && f; i++)
    if ((double)a[i] > m) f = false;
  if (f) {
    for (int i = 0; i < n && f; i++) printf("%.6lf\n", m - a[i]);
  } else
    printf("-1\n");
  return 0;
}
