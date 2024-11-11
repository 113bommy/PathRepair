#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
  int sum = 0;
  int l, r, x, y;
  cin >> l >> r >> x >> y;
  if (y % x) {
    cout << 0 << endl;
    return 0;
  }
  long long k = y / x;
  for (int i = 1; i <= sqrt(k + 0.5); i++) {
    if (k % i) continue;
    if (i * x >= 1 && k / i * x <= r && gcd(k / i, i) == 1) {
      sum += 2;
      if (k / i == i) sum--;
    }
  }
  cout << sum << endl;
  return 0;
}
