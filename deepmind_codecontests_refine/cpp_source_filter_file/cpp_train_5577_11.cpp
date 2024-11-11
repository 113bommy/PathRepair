#include <bits/stdc++.h>
using namespace std;
long long n, a, b, c;
int main() {
  scanf("%lld%lld%lld%lld", &n, &a, &b, &c);
  n = n % 4;
  long long ans = 3000000010;
  if (n == 0) {
    ans = 0;
  } else if (n == 1) {
    ans = min(ans, a * 3);
    ans = min(ans, a + b);
    ans = min(ans, c);
  } else if (n == 2) {
    ans = min(ans, a * 2);
    ans = min(ans, b);
    ans = min(ans, c * 3);
  } else {
    ans = min(ans, a);
    ans = min(ans, b + c);
    ans = min(ans, c * 3);
  }
  printf("%lld\n", ans);
}
