#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[22], b, sum, v;
  double c, r;
  scanf("%d%d", &n, &v);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  r = double(v) / double(sum);
  for (int i = 0; i < n; i++) {
    scanf("%d", &b);
    c = double(b) / double(a[i]);
    if (c < r) r = c;
  }
  printf("%.4lf\n", r * sum);
  return 0;
}
