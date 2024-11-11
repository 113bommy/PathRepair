#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long n, k;
    scanf("%I64d%I64d", &n, &k);
    long long ans = 0;
    while (true) {
      long long r = n % k;
      if (r == n) {
        ans += r;
        break;
      }
      ans += r + 1;
      n /= k;
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
