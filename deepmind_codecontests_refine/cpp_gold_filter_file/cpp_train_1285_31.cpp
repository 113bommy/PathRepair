#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  unsigned long long k, b, t, p, q, r, a;
  cin >> k >> b >> n >> t;
  if (k == 1) {
    a = (t - 1) / b;
    if (a > n)
      cout << 0 << endl;
    else
      cout << n - a << endl;
    return 0;
  }
  p = (k - 1) * t + b;
  q = k - 1 + b;
  r = p / q;
  a = 1;
  while (a <= r) {
    a *= k;
    n--;
  }
  n++;
  if (n < 0)
    cout << 0 << endl;
  else
    cout << n << endl;
  return 0;
}
