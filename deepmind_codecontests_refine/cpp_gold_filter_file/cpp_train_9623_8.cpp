#include <bits/stdc++.h>
using namespace std;
const int nm = 1000002;
long long n;
long long a[nm], f[nm];
int main() {
  scanf("%I64d", &n);
  long long i;
  for (i = 1; i <= n; ++i) scanf("%I64d", &a[i]);
  for (i = 1; i <= n; ++i) f[i] = i ^ f[i - 1];
  long long kq = 0;
  for (i = 1; i <= n; ++i)
    if ((n / i) % 2)
      kq ^= a[i] ^ f[i - 1] ^ f[n % i];
    else
      kq ^= a[i] ^ f[n % i];
  printf("%I64d", kq);
}
