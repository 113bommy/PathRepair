#include <bits/stdc++.h>
using namespace std;
int n, a[255];
int cnt[1000010];
int main() {
  scanf("%d", &n);
  long long x, y, z;
  while (n--) {
    x = 0, y = 0;
    for (int i = 1; i <= 250; i++) {
      scanf("%d", &a[i]);
      x += a[i];
      y += a[i] * a[i];
    }
    x = x * x;
    y = y * 250;
    double tag = y / x;
    if (tag > 1.142857)
      puts("uniform");
    else
      puts("poisson");
  }
  return 0;
}
