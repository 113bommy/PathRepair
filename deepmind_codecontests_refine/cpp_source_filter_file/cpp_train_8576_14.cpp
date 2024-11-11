#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("-O2")
const int N = 1e5 + 5, MOD = 1e9 + 7;
long long n;
int main() {
  scanf("%d", &n);
  if (n < 0) {
    n = -n;
    n = 10 * (n / 100) +
        ((n % 10) < ((n / 10) % 10) ? (n % 10) : ((n / 10) % 10));
    n = -n;
  }
  printf("%d", n);
  return 0;
}
