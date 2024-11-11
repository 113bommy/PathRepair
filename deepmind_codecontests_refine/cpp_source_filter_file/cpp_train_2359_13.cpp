#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N, ans = 0, t = 4, now;
  scanf("%lld", &N);
  ans += N / 2;
  ans += N / 4 * 2;
  if (N % 4 == 3) ans += 2;
  while (t <= N) {
    ans += N / t / 2 * t;
    if (N % (2 * t) >= t) ans += t;
    t *= 2;
  }
  printf("%lld\n", ans);
  return 0;
}
