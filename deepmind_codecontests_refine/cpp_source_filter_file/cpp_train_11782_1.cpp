#include <bits/stdc++.h>
using namespace std;
const int maxi = 1100;
const int inf = 0x3f3f3f3f;
int a[maxi];
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long k, n, a, b;
    scanf("%lld%lld%lld%lld", &k, &n, &a, &b);
    if (k / b <= n) {
      printf("-1\n");
      continue;
    }
    long long t = a - b;
    long long lo = k - (n * b) - 1;
    printf("%lld\n", min(lo / t, n));
  }
  return 0;
}
