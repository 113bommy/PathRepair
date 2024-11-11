#include <bits/stdc++.h>
using namespace std;
const long long M = 1000000007;
long long fastpow(long long x, long long n) {
  if (n == 1) return x;
  long long tp = fastpow(x, n / 2) % M;
  if (n % 2)
    return ((tp * tp) % M * x) % M;
  else
    return (tp * tp) % M;
}
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  if (k == -1 && n % 2 != m % 2) {
    printf("0\n");
  } else if (n == 1 || m == 1) {
    printf("1\n");
  } else
    printf("%lld\n",
           fastpow(2, (((n - 1) % (M - 1)) * ((m - 1) % (M - 1))) % (M - 1)));
}
