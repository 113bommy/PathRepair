#include <bits/stdc++.h>
using namespace std;
inline long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int main() {
  long long int l, r, x, y, lb, ub, n, i, c = 0, ii;
  cin >> l >> r >> x >> y;
  if (y % x != 0) {
    cout << "0\n";
    return 0;
  }
  n = y / x;
  for (i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      ii = n / i;
      if (n / i == i) {
        if (i * x >= l && i * x <= r && gcd(i, i) == 1) c++;
      } else if (i * x >= l && i * x <= r && ii * x >= l && ii * x <= r &&
                 gcd(i, ii) == 1)
        c += 2;
    }
  }
  cout << c;
  return 0;
}
