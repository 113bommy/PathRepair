#include <bits/stdc++.h>
using namespace std;
long long fun(long long a, long long b, long long c) {
  long long ans = 1;
  while (b != 0) {
    if (b % 2 == 1) ans = (ans * a) % c;
    a = (a * a) % c;
    b /= 2;
  }
  return ans;
}
int main() {
  long long n, a, b, x, ans, c = 1000000007, an;
  scanf("%lld %lld %lld %lld", &a, &b, &n, &x);
  long long k = (fun(a, n, c) * x) % c;
  if (a > 1) {
    long long f = ((fun(a, n, c) * b) % c - b + c) % c;
    long long h = fun(a - 1, c - 2, c);
    an = (f * h) % c;
  } else if (a == 1)
    an = (n % c * b) % c;
  ans = (k + an) % c;
  printf("%lld\n", ans);
  return 0;
}
