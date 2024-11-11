#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
int main() {
  scanf("%lld%lld%lld", &n, &m, &k);
  if (k < n) {
    printf("%lld %lld\n", k + 1, 1LL);
  } else {
    k -= n;
    long long tmp = k / (2 * (m - 1));
    long long px = n;
    long long py = 2;
    px -= tmp * 2;
    k = k % (2 * (m - 1));
    if (k < (m - 1)) {
      printf("%lld %lld\n", px, k + 2LL);
    } else {
      printf("%lld %lld\n", px - 1LL, m - (k - (m - 1LL)));
    }
  }
  return 0;
}
