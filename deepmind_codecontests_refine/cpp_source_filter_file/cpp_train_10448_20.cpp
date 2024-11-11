#include <bits/stdc++.h>
using namespace std;
const long long mx = 1e6 + 3;
#pragma GCC optimize("O3")
vector<long long> divs(mx, 0);
void make() {
  for (long long n = 1; n < mx; n++) {
    for (long long k = n; k < mx; k += n) divs[k]++;
  }
}
int main() {
  make();
  long long x, y, z;
  scanf("%lld", &x);
  scanf("%lld", &y), scanf("%lld", &z);
  long long res = 0;
  long long mod = (1 << 30);
  for (long long n = 1; n <= x; n++) {
    for (long long k = 1; k <= y; k++) {
      for (long long p = 1; p <= y; p++) {
        long long cur = n * k * p;
        res += divs[cur];
        res %= mod;
      }
    }
  }
  printf("%lld", res);
}
