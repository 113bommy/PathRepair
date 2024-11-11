#include <bits/stdc++.h>
using namespace std;
long long N, H;
long long sumto(long long x) { return x * (x + 1) / 2; }
long long sumrange(long long x, long long y) { return sumto(y) - sumto(x - 1); }
long long moo(long long p) {
  if (p <= H) {
    return sumto(p);
  }
  p -= H;
  if (p % 2 == 1) {
    return sumrange(H, H + p / 2) + sumto(H + p / 2);
  } else {
    return sumrange(H, H + p / 2) + sumto(H + p / 2 - 1);
  }
}
int main() {
  scanf("%lld %lld", &N, &H);
  long long lo = 0, hi = 3e9;
  while (hi - lo > 1) {
    long long mid = (lo + hi) / 2;
    if (moo(mid) >= N) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  printf("%lld\n", hi);
}
