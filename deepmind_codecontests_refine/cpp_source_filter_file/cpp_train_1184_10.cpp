#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const double PI = 3.14159265359;
vector<long long> primes;
void GeneratingPrimes(int top) {
  vector<bool> p(top + 1, 1);
  p[0] = p[1] = 0;
  for (int i = 2; i <= sqrt(top); i++) {
    if (p[i]) {
      for (int j = i * i; j <= top; j += i) {
        p[j] = 0;
      }
    }
  }
  for (int i = 0; i < top + 1; i++)
    if (p[i]) primes.push_back(i);
}
long long gcd(long long a, long long b) { return (b == 0) ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
void EXTgcd(long long a, long long b, int& x0, int& y0) {
  if (b == 0) {
    x0 = 1, y0 = 0;
    return;
  }
  EXTgcd(b, a % b, x0, y0);
  long long x1 = y0;
  long long y1 = x0 - (a / b) * y0;
  x0 = x1;
  y0 = y1;
}
long long power(long long x, long long p, long long m) {
  if (!p) return 1;
  if (p % 2) return ((x % m) * (power(x, p - 1, m) % m)) % m;
  x %= m;
  x *= x;
  x %= m;
  p /= 2;
  return (x * (power(x, p, m)) % m) % m;
}
double dist(double a, double b, double x, double y) {
  return sqrt(pow(a - x, 2) + pow(b - y, 2));
}
double dist3(double a, double b, double c, double x, double y, double z) {
  return sqrt(pow(a - x, 2) + pow(b - y, 2) + pow(c - z, 2));
}
int xadd[9] = {1, -1, 0, 1, -1, 0, 1, -1, 0};
int yadd[9] = {1, -1, 0, -1, 0, 1, 0, 1, -1};
long long const N = 3e5 + 10;
long long mod = 1e9;
long long n, k;
int main() {
  cin >> n >> k;
  long long lo = 1, hi = k - 1, mid, ans = -1;
  while (lo <= hi) {
    mid = (lo + hi) / 2;
    long long s = mid * (k + k - mid) / 2 - mid + 1;
    if (s >= n) {
      if (ans == -1) ans = mid;
      ans = min(ans, mid);
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  cout << ans;
  return 0;
}
