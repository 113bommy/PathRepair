#include <bits/stdc++.h>
using namespace std;
long long arr[100010];
int pwr(int base, long long exp) {
  if (exp == 0) return 1;
  if (exp == 1) return base;
  int res = (1LL * base * base) % 1000000007;
  return (1LL * pwr(res, exp >> 1) * pwr(base, exp & 1)) % 1000000007;
}
int main() {
  int k, res = 2;
  bool even = false;
  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    long long val;
    scanf("%I64d", &val);
    res = pwr(res, val);
    even |= (val % 2 == 0);
  }
  res = (1LL * res * pwr(2, 1000000007 - 2)) % 1000000007;
  int p, q;
  if (even) {
    p = (1LL * (res + 1) * pwr(3, 1000000007 - 2)) % 1000000007;
    q = res;
  } else {
    p = (1LL * (res - 1) * pwr(3, 1000000007 - 2)) % 1000000007;
    q = res;
  }
  printf("%d/%d\n", p, q);
  return 0;
}
