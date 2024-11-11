#include <bits/stdc++.h>
using namespace std;
int q, n;
bool ok(long long edg) {
  long long b = (edg + 1) >> 1, o = (n - b) * (n - b - 1) >> 1;
  return (b + min(edg >> 1, o)) == edg && b < n;
}
long long bs() {
  long long beg = 0, end = 2LL * n, mid;
  while (beg < end) {
    mid = (beg + end + 1) >> 1;
    if (ok(mid))
      beg = mid;
    else
      end = mid - 1;
  }
  return beg;
}
int main() {
  for (scanf("%d", &q); q--;) {
    scanf("%d", &n);
    long long ans = bs();
    printf("%lld\n", ans);
  }
}
