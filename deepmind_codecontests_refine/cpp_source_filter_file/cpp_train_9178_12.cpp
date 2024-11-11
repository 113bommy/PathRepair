#include <bits/stdc++.h>
using namespace std;
int Day12[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int prime100[] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37,  41, 43,
                  47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};
template <typename T>
inline bool isLeap(T y) {
  return (y % 400 == 0) || (y % 100 ? y % 4 == 0 : false);
}
template <typename T>
inline T GCD(T a, T b) {
  a = abs(a);
  b = abs(b);
  if (a < b) swap(a, b);
  while (b) {
    a = a % b;
    swap(a, b);
  }
  return a;
}
template <typename T>
inline T LCM(T x, T y) {
  T tp = GCD(x, y);
  if ((x / tp) * 1. * y > 9e18) return 9e18;
  return (x / tp) * y;
}
template <typename T>
inline T BIGMOD(T A, T B, T M = 1000000007) {
  T ret = 1;
  while (B) {
    if (B & 1) ret = (ret * A) % M;
    A = (A * A) % M;
    B = B >> 1;
  }
  return ret;
}
template <typename T>
inline T BigMod(T A, T B, T M) {
  T ret = 1;
  while (B) {
    if (B & 1) ret = (ret * A) % M;
    A = (A * A) % M;
    B = B >> 1;
  }
  return ret;
}
long long int MySqrt(long long int n) {
  long long int p = sqrt(n);
  if ((p + 1) * (p + 1) <= n)
    return p + 1;
  else if (p * p <= n)
    return p;
  else
    return p - 1;
}
long long int MyPow(long long int x, long long int n) {
  if (n == 0)
    return 1;
  else if (n % 2 == 0)
    return MyPow(x * x, n / 2);
  else
    return x * MyPow(x * x, ((n - 1) / 2));
}
long long int modInverse(long long int n) {
  return BIGMOD(n, (long long int)1000000007 - 2) % 1000000007;
}
int main() {
  double H, L;
  cin >> H >> L;
  double Low = 0, High = 10000000;
  while (Low < High) {
    double mid = (Low + High) / 2.0;
    double a = H * H + 2.0 * H * mid;
    double b = L * L;
    if (abs(a - b) < 0.0000001) {
      printf("%0.8f\n", mid);
      return 0;
    }
    if (a > b)
      High = mid;
    else
      Low = mid;
  }
}
