#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}
int main(void) {
  long long n, a, b, p, q;
  while (cin >> n >> a >> b >> p >> q) {
    long long sum = 0;
    sum += n / a * p;
    sum += n / b * q;
    long long t = a / gcd(a, b) * b;
    if (p > q)
      sum -= n / t * q;
    else
      sum -= n / t * p;
    printf("%I64d\n", sum);
  }
  return 0;
}
