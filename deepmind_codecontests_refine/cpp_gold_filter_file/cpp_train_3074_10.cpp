#include <bits/stdc++.h>
using namespace std;
const int D = 60;
long long sum, xsum;
int main() {
  scanf("%I64d%I64d", &sum, &xsum);
  long long ans = 1, res = 0;
  for (int i = 0; i < D; ++i) {
    if (xsum >> i & 1)
      ans <<= 1, sum -= 1ll << i;
    else
      res |= 1ll << i;
  }
  res <<= 1;
  if ((res | sum) != res) return puts("0"), 0;
  if (!sum) ans -= 2;
  printf("%I64d\n", ans);
  return 0;
}
