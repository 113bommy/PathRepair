#include <bits/stdc++.h>
using namespace std;
const double pi = 2 * acos(0);
const int N = 100;
long long i, t, j, x;
long long digit(long long n) {
  long long s = 1;
  while (n / 10) {
    n /= 10;
    s++;
  }
  return s;
}
int main() {
  long long r = 0, y = 0;
  cin >> x;
  long long d = x;
  long long p = digit(d) - 1;
  if (x % 10 == 4) {
    y += 1;
    x /= 10;
  }
  i = 1;
  while (x) {
    if (x % 10 == 4) {
      y += pow(2, i);
    }
    i++;
    if (x / 10 == 0) {
      break;
    }
    x /= 10;
  }
  y = pow(2, p + 1) - y;
  while (p) {
    r += pow(2, p);
    p--;
  }
  cout << y + r;
}
