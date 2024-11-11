#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int total = n * 2, c = 0;
  double hap = 0;
  double low = 0;
  for (int i = 0; i < 2 * n; i++) {
    double temp;
    scanf("%lf", &temp);
    hap += temp;
    low += (int)temp;
    double check = temp - (int)temp;
    if (check == 0.0) c++;
  }
  int mn, mx;
  if (c < n) {
    mn = 0;
    mx = c;
  } else {
    mn = n - c;
    mx = n;
  }
  double dap = fabs(mn - hap + low);
  for (int i = mn; i <= mx; i++) {
    dap = min(dap, fabs(i - hap + low));
  }
  printf("%.3f", dap);
}
