#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
long long x, y, r;
int main() {
  scanf("%lld", &r);
  for (x = 1; x <= 1e6; ++x)
    if ((r - x * x - 1 - x) % (x * 2) == 0) {
      y = (r - x * x - 1 - x) / (x * 2);
      if (y <= 0) continue;
      printf("%lld %lld", x, y);
      return 0;
    }
  printf("NO");
  return 0;
}
