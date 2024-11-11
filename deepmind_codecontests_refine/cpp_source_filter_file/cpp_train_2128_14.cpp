#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) { return y == 0 ? x : gcd(y, x % y); }
inline int string_to_int(string s) {
  stringstream ss;
  ss << s;
  int x;
  ss >> x;
  return x;
}
inline string int_to_string(int x) {
  stringstream ss;
  ss << x;
  string s;
  ss >> s;
  return s;
}
int modulo(int a, int b, int c) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x * y) % c;
    }
    y = (y * y) % c;
    b /= 2;
  }
  return x % c;
}
long long mulmod(long long a, long long b, long long c) {
  long long x = 0, y = a % c;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x + y) % c;
    }
    y = (y * 2) % c;
    b /= 2;
  }
  return x % c;
}
int main() {
  int n, k;
  cin >> n >> k;
  int z = n;
  if (n == 1 && k == 0)
    cout << 1 << endl;
  else if ((n / 2) > k || k == 0)
    cout << -1 << endl;
  else if ((n > 1 && k == 0))
    cout << -1 << endl;
  else if (n == 1)
    cout << -1 << endl;
  else {
    int p = n / 2;
    p--;
    int k1 = 1000000000 - 1;
    for (int i = 0; i < p; i++) {
      cout << k1 << " " << k1 + 1 << " ";
      k1 -= 2;
    }
    int rem = k - p;
    if (rem == 1) {
      cout << 1 << " " << 2 << " ";
    } else {
      cout << rem << " " << 2 * rem << " ";
    }
    if ((z % 2) != 0) {
      cout << 1000000000 << " ";
    }
    cout << endl;
  }
  return 0;
}
