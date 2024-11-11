#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1000000000000;
const long long int mod = 1000000007;
long long int MOD(long long int a, long long int b) {
  if (a > b)
    return a - b;
  else
    return b - a;
}
long long int max3(long long int a, long long int b, long long int c) {
  return max(c, max(a, b));
}
long long int min3(long long int a, long long int b, long long int c) {
  return min(a, min(b, c));
}
long long int power(long long int x, long long int y) {
  long long int res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
long long int power1(long long int x, long long int y) {
  long long int res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res % mod;
}
long long int logg(long long int a) {
  long long int x = 0;
  while (a > 1) {
    x++;
    a /= 2;
  }
  return x;
}
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long int abso(long long int x) {
  if (x < 0) {
    return -x;
  }
  return x;
}
long long int ceiling(long long int a, long long int b) {
  if (a % b == 0) {
    return a / b;
  } else {
    return a / b + 1;
  }
}
long long int modinv(long long int x) { return power1(x, mod - 2); }
int main() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    if ((n / 2) % 2 == 0) {
      cout << 0;
    } else {
      cout << 1;
    }
  } else {
    if (((n - 1) / 2) % 2 == 0) {
      cout << 1;
    } else {
      cout << 0;
    }
  }
}
