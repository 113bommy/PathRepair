#include <bits/stdc++.h>
using namespace std;
long long invmask(long long x) {
  long long m = 0;
  long long d = 0;
  while (x > 0) {
    d = x % 10;
    if (d == 4 || d == 7) {
      m *= 10;
      m += d;
    }
    x /= 10;
  }
  return m;
}
int main() {
  long long a, b, c;
  cin >> a >> b;
  c = a + 1;
  int invb = 0;
  while (b > 0) {
    long long d = b % 10;
    b /= 10;
    invb *= 10;
    invb += d;
  }
  bool found = false;
  while (!found) {
    if (invmask(c) == invb) {
      found = true;
    } else {
      c++;
    }
  }
  cout << c << endl;
  return 0;
}
