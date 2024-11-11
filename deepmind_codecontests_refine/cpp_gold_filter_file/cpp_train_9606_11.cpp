#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
long long n;
long long a[500500];
long long b[50];
int main() {
  long long t;
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &n);
    memset(b, 0, sizeof(b));
    long long ans = 0;
    for (long long i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
      long long sum = 0;
      while (a[i]) {
        a[i] = a[i] >> 1;
        sum++;
      }
      b[sum]++;
    }
    for (long long i = 0; i <= 40; i++) {
      if (b[i] > 1) ans = ans + b[i] * (b[i] - 1) / 2;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
