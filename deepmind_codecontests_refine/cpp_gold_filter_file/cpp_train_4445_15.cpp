#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
long long n, H;
bool check(long long x) {
  if (x <= H) {
    if (x >= INF) return true;
    return x * (x + 1) >= 2LL * n;
  } else if ((x - H) & 1) {
    long long A = (x - H) / 2;
    return A * (2 * H + A - 1) / 2 + H + A + (1 + H + A) * (H + A) / 2 >= n;
  } else {
    long long A = (x - H) / 2;
    return A * (2 * H + A - 1) / 2 + (1 + H + A) * (H + A) / 2 >= n;
  }
}
int main() {
  while (~scanf("%I64d%I64d", &n, &H)) {
    long long l = 0, r = 2e9 + 10;
    while (l < r - 1) {
      long long mid = (l + r) >> 1;
      if (check(mid))
        r = mid;
      else
        l = mid;
    }
    printf("%I64d\n", r);
  }
  return 0;
}
