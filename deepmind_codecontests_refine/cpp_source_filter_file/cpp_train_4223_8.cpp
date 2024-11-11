#include <bits/stdc++.h>
using namespace std;
long long d, k, a, b, t;
int main() {
  long long sum = 0, temp1, temp2;
  scanf("%lld%lld%lld%lld%lld", &d, &k, &a, &b, &t);
  if (d <= k) {
    sum = d * a;
  } else {
    if (k * a + t <= k * b) {
      temp1 = d % k;
      temp2 = d / k;
      sum = temp2 * k * a + (temp2 - 1) * t;
      sum += min(temp1 * b, temp1 * a + t);
    } else if (k * a <= k * b && k * a + t > k * b) {
      temp1 = d - k;
      sum = temp1 * b + k;
    }
  }
  printf("%lld\n", sum);
  return 0;
}
