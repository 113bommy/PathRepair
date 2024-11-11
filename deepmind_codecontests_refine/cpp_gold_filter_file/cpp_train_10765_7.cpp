#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9;
long long gcd(long long a, long long b) { return (a ? gcd(b % a, a) : b); }
long long power(long long a, long long n) {
  long long p = 1;
  while (n > 0) {
    if (n % 2) {
      p = p * a;
    }
    n >>= 1;
    a *= a;
  }
  return p;
}
int main() {
  ios_base::sync_with_stdio(false);
  long long n;
  cin >> n;
  int d, x;
  if (!n) {
    return cout << "O-|-OOOO", 0;
  }
  while (n) {
    d = n % 10;
    if (d < 5) {
      cout << "O-|";
    } else {
      cout << "-O|";
      d -= 5;
    }
    x = 4 - d;
    while (d--) {
      cout << "O";
    }
    cout << "-";
    while (x--) {
      cout << "O";
    }
    cout << "\n";
    n /= 10;
  }
  return 0;
}
