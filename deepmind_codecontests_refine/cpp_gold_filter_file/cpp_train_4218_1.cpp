#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  while (b != 0) {
    long long r = a % b;
    a = b;
    b = r;
  }
  return a;
}
int main() {
  long long a, b;
  cin >> a >> b;
  if (gcd(a, b) != 1) {
    cout << "Impossible";
    return 0;
  }
  while (a != 1 || b != 1) {
    if (a > b) {
      long long k = (a - 1) / b;
      cout << k << "A";
      a -= b * k;
    } else {
      long long k = (b - 1) / a;
      cout << k << "B";
      b -= a * k;
    }
  }
  return 0;
}
