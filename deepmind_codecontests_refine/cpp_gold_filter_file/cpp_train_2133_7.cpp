#include <bits/stdc++.h>
using namespace std;
int A, B, n;
long long getTime(long long l, long long r, long long m) {
  long long val1 = (r - l + 1) * (A + B * (l - 1));
  val1 += B * ((r - l + 1) * (r - l)) / 2;
  long long d = m;
  long long ans = (val1 + d - 1) / d;
  if (A + (r - 1) * B > ans) ans = A + (r - 1) * B;
  return ans;
}
int main() {
  scanf("%d%d%d", &A, &B, &n);
  for (int i = (0); i < int(n); ++i) {
    int l, t, m;
    scanf("%d%d%d", &l, &t, &m);
    long long lo = l - 1, hi = l + 1000000;
    while (hi - lo > 1) {
      long long mid = (hi + lo) / 2;
      if (getTime(l, mid, m) > t)
        hi = mid;
      else
        lo = mid;
    }
    if (lo >= l)
      printf("%I64d\n", lo);
    else
      puts("-1");
  }
}
