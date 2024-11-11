#include <bits/stdc++.h>
using namespace std;
void priv(vector<double> &v) {
  for (auto x : v) cout << x << " ";
}
unsigned long long power(unsigned long long n, unsigned long long y,
                         unsigned long long p) {
  if (y == 0) return 1;
  unsigned long long x = power(n, y / 2, p);
  x = (x * x) % p;
  if (y % 2 == 0)
    return x;
  else
    return (n * x) % p;
}
unsigned long long modInv(unsigned long long n, unsigned long long p) {
  return power(n, p - 2, p);
}
unsigned long long ncr(unsigned long long n, unsigned long long r,
                       unsigned long long p, unsigned long long *fac) {
  if (n < r) return 0;
  if (r == 0) return 1;
  return (fac[n] * modInv(fac[r], p) % p * modInv(fac[n - r], p) % p) % p;
}
int numd(long long n) {
  int c = 0;
  while (n > 0) {
    c++;
    n /= 10;
  }
  return c;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  int s = 0;
  cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s += a[i];
  }
  sort(a, a + n);
  double l = a[0], r = a[n - 1], mid;
  cout.precision(8);
  while (l + 1e-8 <= r) {
    mid = (l + r) / 2;
    int x = 0, y = 0;
    double s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] > mid) {
        s1 += a[i];
        x++;
      } else if (a[i] < mid) {
        s2 += a[i];
        y++;
      }
    }
    double lh = (s1 - mid * x) * (1 - k * 1.0 / 100);
    double rh = y * mid - s2;
    if (lh < rh)
      r = mid;
    else if (lh > rh)
      l = mid;
    else {
      cout << fixed << mid;
      break;
    }
  }
  cout << fixed << mid;
  return 0;
}
