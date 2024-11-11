#include <bits/stdc++.h>
using namespace std;
long long int a[35];
long long int n;
long long int a1;
int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a1);
    long long int cnt = 0;
    while (a1) {
      if (a1 & 1) {
        cnt++;
      }
      a1 >>= 1;
    }
    a[cnt]++;
  }
  long long int ans = 0;
  for (int i = 0; i <= 35; i++) {
    ans += ((a[i] * (a[i - 1]) / 2));
  }
  printf("%lld\n", ans);
  return 0;
}
