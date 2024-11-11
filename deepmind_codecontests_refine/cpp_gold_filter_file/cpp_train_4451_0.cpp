#include <bits/stdc++.h>
using namespace std;
long long n, h;
long long sum(long long a, long long b) { return ((a + b) * (b - a + 1)) / 2; }
bool judge(long long x) {
  long long ans;
  if (x < h) {
    ans = sum(1, x);
  } else {
    ans = sum(1, h - 1);
    x -= (h - 1);
    if (x % 2) {
      ans += (sum(h, h + x / 2) + sum(h, h + x / 2 - 1));
    } else {
      ans += (sum(h, h + x / 2 - 1) * 2);
    }
  }
  return ans >= n;
}
int main() {
  scanf("%lld%lld", &n, &h);
  long long l = 1, r = sqrt(n) * 2 + 1, p;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (judge(mid)) {
      p = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  printf("%lld\n", p);
  return 0;
}
