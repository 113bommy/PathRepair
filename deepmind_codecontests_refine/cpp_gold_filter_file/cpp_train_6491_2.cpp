#include <bits/stdc++.h>
using namespace std;
long long p, d;
int main() {
  scanf("%lld%lld", &p, &d);
  if (d == 0) {
    printf("%lld\n", p);
    return 0;
  }
  long long weig = 10, ans = p + 1;
  p++;
  while (p % weig <= d) {
    ans = p - p % weig;
    weig *= 10;
  }
  printf("%lld\n", ans - 1);
  return 0;
}
