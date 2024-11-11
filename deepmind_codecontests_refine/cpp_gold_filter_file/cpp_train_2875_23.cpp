#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  scanf("%lld%lld", &n, &k);
  if (n - k && k) {
    printf("%lld ", 1ll);
  } else {
    printf("%lld ", 0ll);
  }
  if (k >= (n + 2) / 3) {
    printf("%lld\n", n - k);
  } else {
    printf("%lld\n", k * 2ll);
  }
  return 0;
}
