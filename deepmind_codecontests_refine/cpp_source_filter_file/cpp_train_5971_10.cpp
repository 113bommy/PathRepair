#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= 1000000007;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
  }
  return res;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n, m;
    scanf("%lld%lld", &n, &m);
    int l = 0, r = n, mid, ans = 0;
    while (l <= r) {
      mid = (l + r) >> 1;
      long long C = 1, B = n, S = m * mid;
      for (int i = 0; i <= mid && S >= 0 && B; i++) {
        long long num = min(B, C);
        B -= num;
        S -= 1LL * i * num;
        C *= 1LL * (mid - i) / (i + 1);
      }
      if (S >= 0 && B == 0)
        ans = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    cout << ans << '\n';
  }
  return 0;
}
