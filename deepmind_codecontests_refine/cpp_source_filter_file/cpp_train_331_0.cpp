#include <bits/stdc++.h>
using namespace std;
long long x;
long long a, b;
long long mn = 1e12;
int solve(long long d, long long f, long long s) {
  long long d1 = d, f1 = f;
  long long e = d % f;
  d = f;
  f = e;
  while (e) {
    e = d % f;
    d = f;
    f = e;
  }
  if (f1 * d1 / d == s) {
    return 1;
  } else {
    return 0;
  }
}
int main() {
  cin >> x;
  for (long long i = 1; i < sqrt(x); i++) {
    if (x % i == 0) {
      if (max(i, x / i) < mn && solve(x / i, i, x) == 1) {
        a = i;
        b = x / i;
        mn = max(i, x / i);
      }
    }
  }
  cout << a << ' ' << b;
  return 0;
}
