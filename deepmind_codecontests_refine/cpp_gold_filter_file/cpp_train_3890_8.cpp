#include <bits/stdc++.h>
using namespace std;
long long x;
int n, m;
long long binpow(long long a, int b) {
  long long res = 1;
  while (b) {
    a %= m;
    if (b & 1) res *= a;
    res %= m;
    b /= 2;
    a *= a;
    a %= m;
  }
  return res;
}
int main() {
  scanf("%d%d", &n, &m);
  x = binpow(3, n);
  x = ((x - 1) % m + m) % m;
  printf("%I64d", x);
  return 0;
}
