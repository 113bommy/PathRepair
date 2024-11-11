#include <bits/stdc++.h>
using namespace std;
long long d, x, y;
void extendedEuclid(long long A, long long B) {
  if (B == 0) {
    d = A;
    x = 1;
    y = 0;
  } else {
    extendedEuclid(B, A % B);
    int temp = x;
    x = y;
    y = temp - (A / B) * y;
  }
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long IsPrime(long long n) {
  if (n == 0 || n == 1) return n;
  if (n % 2 == 0) return (long long)2;
  if (n % 3 == 0)
    return (long long)3;
  else {
    for (long long i = 5; i * i <= n; i += 6) {
      if (n % i == 0) return i;
      if (n % (i + 2) == 0) return (i + 2);
    }
    return n;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, i, j, k, m;
  cin >> n;
  k = 0;
  long long c = 1;
  while (k < n) {
    long long x = c * 9 * pow(10, c - 1);
    if (k + x >= n) {
      break;
    }
    k += x;
    c++;
  }
  k++;
  long long x = (n - k) / c;
  long long y = (n - k) % c;
  long long z = pow(10, c - 1);
  if (c == 1) z = 0;
  z += x;
  string s = to_string(z);
  reverse(s.begin(), s.end());
  z = stoll(s);
  while (y > 0) {
    z /= 10;
    y--;
  }
  cout << z % 10;
}
