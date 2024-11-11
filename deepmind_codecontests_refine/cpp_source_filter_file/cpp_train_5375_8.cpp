#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) {
  long long c = x % y;
  while (c != 0) {
    x = y;
    y = c;
    c = x % y;
  }
  return y;
}
int main() {
  long long a, b;
  cin >> a >> b;
  long long lcm = a * b / gcd(a, b);
  long long ca = lcm / a - 1, cb = lcm / b - 1;
  if (ca > cb) {
    cb += 1;
  } else {
    ca += 1;
  }
  if (ca < cb) {
    cout << "Masya\n";
  } else if (ca == cb) {
    cout << "Equal\n";
  } else {
    cout << "Dasha\n";
  }
}
