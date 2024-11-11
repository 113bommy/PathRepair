#include <bits/stdc++.h>
using namespace std;
unsigned long long min(unsigned long long x, unsigned long long y) {
  if (x < y) return x;
  return y;
}
unsigned long long max(unsigned long long x, unsigned long long y) {
  if (x < y) return y;
  return x;
}
long long min(long long x, long long y) {
  if (x < y) return x;
  return y;
}
long long max(long long x, long long y) {
  if (x < y) return y;
  return x;
}
double min(double x, double y) {
  if (x < y) return x;
  return y;
}
double max(double x, double y) {
  if (x < y) return y;
  return x;
}
unsigned long long gcd(unsigned long long x, unsigned long long y) {
  if (!x) return y;
  if (!y) return x;
  if (x > y) swap(x, y);
  return gcd(x, y % x);
}
unsigned long long inv(unsigned long long a, unsigned long long c) {
  if (a == 1) {
    return 1;
  }
  return ((c - (c / a)) * inv(c % a, c)) % c;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long u, v;
  cin >> u >> v;
  if ((u > v) || ((u & 1) != (v & 1))) {
    cout << "-1\n";
    return 0;
  }
  if (u == v) {
    cout << 1 << "\n";
    cout << u << "\n";
    return 0;
  }
  long long x = (v - u) / 2;
  if ((u ^ x) == u + x) {
    cout << "2\n";
    cout << u + x << " " << x << "\n";
  } else {
    cout << 3 << "\n";
    cout << u << " " << x << " " << x << "\n";
  }
  return 0;
}
