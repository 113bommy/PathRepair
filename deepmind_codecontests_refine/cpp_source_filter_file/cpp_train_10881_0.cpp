#include <bits/stdc++.h>
using namespace std;
long long po(long long n, long long r) {
  long long ans = 1;
  for (long long i = 1; i <= r; i++) {
    ans = n * ans;
  }
  return ans;
}
int gcd(long long int x, long long int y) {
  if (y == 0)
    return x;
  else
    return gcd(y, x % y);
}
long long int lcm(long long int a, long long int b) {
  int k = gcd(a, b);
  a /= k;
  return a * b;
}
double fast_pow(double a, long long int n) {
  double result = 1.000000000000000;
  long long int power = n;
  double value = a;
  while (power > 0) {
    if (power & 1) {
      result = result * value;
    }
    value = value * value;
    power /= 2;
  }
  return result;
}
long long ncr(long long n, long long p) {
  long long a = 1, b = 1;
  ;
  for (int i = n - p + 1; i <= n; i++) a *= i;
  for (int i = 1; i <= p; i++) b *= i;
  return a / b;
}
int main() {
  int n;
  cin >> n;
  long long ans = 1;
  for (int i = n; i >= n - 4; i--) {
    ans *= i;
  }
  cout << n - n / 2 - n / 3 - n / 5 - n / 7 + n / 6 + n / 10 + n / 14 + n / 15 -
              n / 30 + n / 210 + n / 21 + n / 35 - n / 105 - n / 70 - n / 42;
  return 0;
}
