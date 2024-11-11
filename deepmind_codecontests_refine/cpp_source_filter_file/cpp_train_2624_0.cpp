#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long c, sum;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &c, &sum);
    if (c < sum) {
      long long k = sum / c;
      long long s = sum % c;
      printf("%lld\n", s * (k + 1) * (k + 1) + (c - s) * k * k);
    } else {
      printf("%lld\n", sum);
    }
  }
  return 0;
}
