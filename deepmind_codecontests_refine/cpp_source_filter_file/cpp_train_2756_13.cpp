#include <bits/stdc++.h>
using namespace std;
const double error = 1e-9;
const int MAXN = 100005;
int a[MAXN];
int c[3][2], cn;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  if (n == 1)
    printf("0\n");
  else if (n == 2) {
    if (a[0] == 0 && a[1] != 0)
      printf("1\n");
    else
      printf("0\n");
  } else {
    int ans = 2;
    cn = 3;
    c[0][0] = a[0], c[0][1] = a[1];
    c[1][0] = a[0], c[1][1] = a[2];
    c[2][0] = a[1], c[2][1] = a[2];
    for (int k = 0; k < cn; k++) {
      int cnt = 0;
      double x = a[0], y;
      if (c[k][0] == 0)
        y = 0;
      else
        y = (double)c[k][1] / c[k][0];
      for (int i = 0; i < n; i++)
        if (fabs(x - a[i]) > error)
          cnt++;
        else
          x *= y;
      ans = min(ans, cnt);
    }
    printf("%d\n", ans);
  }
  return 0;
}
