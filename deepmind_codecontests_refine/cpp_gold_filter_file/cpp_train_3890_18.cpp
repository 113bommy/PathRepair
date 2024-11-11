#include <bits/stdc++.h>
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
using namespace std;
long long m;
long long quick_pow(long long a, long long n) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans = ans * a % m;
    n >>= 1;
    a = a * a % m;
  }
  return ans - 1;
}
int main() {
  long long n;
  scanf("%I64d%I64d", &n, &m);
  printf("%I64d\n", (quick_pow(3, n) + m) % m);
  return 0;
}
