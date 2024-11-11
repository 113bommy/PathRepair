#include <bits/stdc++.h>
using namespace std;
long long n, h;
bool ok(long long x) {
  if (x <= h) return x * (x + 1) / 2 >= n;
  if (x ^ h & 1) {
    long long tp = (x + h - 1) / 2;
    return (tp + h) * (tp - h + 1) / 2 + tp * (tp + 1) / 2 >= n;
  }
  long long tp = (x + h) / 2;
  return (tp - 1 + h) * (tp - h) / 2 + tp * (tp + 1) / 2 >= n;
}
int main() {
  scanf("%I64d%I64d", &n, &h);
  long long l = 0, r = 2e9 + 1;
  while (l < r - 1) {
    long long mid = (l + r) >> 1;
    if (ok(mid))
      r = mid;
    else
      l = mid;
  }
  return 0 * printf("%I64d\n", r);
}
