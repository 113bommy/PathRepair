#include <bits/stdc++.h>
using namespace std;
long long a, b, w, x, c;
bool judge(long long n) {
  if (c <= a) return 1;
  long long aa = a - (n * x - b + w - 1) / w;
  if (n * x < b) aa = a;
  long long cc = c - n;
  if (cc <= aa) return 1;
  return 0;
}
int main() {
  scanf("%lld%lld%lld%lld%lld", &a, &b, &w, &x, &c);
  long long l = 0, r = 1000000000000000LL;
  while (r - l > 1) {
    long long mid = (l + r) / 2;
    if (judge(mid))
      r = mid;
    else
      l = mid + 1;
  }
  if (judge(l) == 0) l = r;
  printf("%lld\n", l);
}
