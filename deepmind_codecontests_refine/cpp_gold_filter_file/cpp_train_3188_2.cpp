#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long a, long long b) {
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}
int ksm(unsigned long long a) {
  int b = 10, s = 1;
  while (a != 0) {
    if (a % 2 == 1) s *= b;
    b = b * b;
    a /= 2;
  }
  return s;
}
int main() {
  unsigned long long int n, k, w;
  cin >> n >> k;
  int s;
  s = ksm(k);
  w = n * s;
  printf("%lld", w / gcd(n, s));
  return 0;
}
