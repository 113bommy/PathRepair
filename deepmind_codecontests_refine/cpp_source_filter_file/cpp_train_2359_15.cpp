#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, ans = 0, now = 1;
  scanf("%lld", &n);
  while (n) {
    ans += now * ((n + 1) >> 1);
    now = now << 1;
    n >>= 1;
  }
  printf("%lld\n", ans);
}
