#include <bits/stdc++.h>
using namespace std;
unsigned long long x, y, a, b, t;
int main() {
  scanf("%lld%lld", &a, &b);
  t = a - b;
  if (a < b || t & 1) {
    printf("-1");
    return 0;
  }
  x = t >> 1;
  y = a - x;
  printf("%lld %lld", x, y);
  return 0;
}
