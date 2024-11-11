#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[9], minn = 1 << 30;
  for (int i = 0; i < 9; i++) cin >> a[i];
  int of = a[1] - a[5], df = a[4] - a[2], cof, cdf;
  for (int i = 0; i <= 200; i++)
    for (int j = 0; j <= 100; j++) {
      int sum = i * a[7] + j * a[8];
      cof = max(0, of + i), cdf = max(0, df - j);
      if (cof == 0) continue;
      sum += (max(0, (a[3] + cof - 1) / cof * cdf + 1 - a[0])) * a[6];
      minn = min(minn, sum);
    }
  printf("%d\n", minn);
  return 0;
}
