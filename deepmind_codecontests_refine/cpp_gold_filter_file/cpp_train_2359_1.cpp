#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long llinf = 0x3f3f3f3f3f3f3f3f;
const long double pi = acos(-1.0L);
int main() {
  long long n, i, j, ans = 0;
  scanf("%I64d", &n);
  for (i = 1; i <= 60; i++) {
    ans += ((n + (1ll << (i - 1ll)) - 1ll) / (1ll << i)) * (1ll << (i - 1ll));
  }
  printf("%I64d\n", ans);
  return 0;
}
