#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    long long x, y, z, w;
    scanf("%I64d%I64d", &x, &y);
    z = x * y;
    w = pow(z, 1.0 / 3) + 0.5;
    if (w * w * w == z && x % w == 0 && y % w == 0)
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}
