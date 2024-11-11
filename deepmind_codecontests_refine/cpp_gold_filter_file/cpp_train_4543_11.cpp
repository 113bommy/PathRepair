#include <bits/stdc++.h>
using namespace std;
long long pow_(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = (ret * a) % 1000000007;
    a = (a * a) % 1000000007;
    b >>= 1;
  }
  return ret;
}
long long n, m, k;
int main() {
  scanf("%lld %lld %lld", &n, &m, &k);
  if ((((n % 2) + (m % 2)) == 1) && k == -1) {
    printf("0");
  } else {
    printf("%lld", pow_(pow_(2LL, n - 1), m - 1));
  }
  return 0;
}
