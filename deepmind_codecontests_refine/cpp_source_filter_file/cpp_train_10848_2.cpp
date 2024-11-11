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
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res % p;
}
double dist(double a, double b, double x, double y) {
  return sqrt(pow(a - x, 2) + pow(b - y, 2));
}
double dist3(double a, double b, double c, double x, double y, double z) {
  return sqrt(pow(a - x, 2) + pow(b - y, 2) + pow(c - z, 2));
}
int xadd[9] = {1, -1, 0, 1, -1, 0, 1, -1, 0};
int yadd[9] = {1, -1, 0, -1, 0, 1, 0, 1, -1};
long long const N = 100000 + 10;
long long mod = 998244353;
vector<int> ans;
bool chkCD(vector<int> v, int c, int d) {
  if (v.size()) {
    if (v.back() != 2) {
      if (d) return 0;
    }
    if (d < c) return 0;
    while (c--) {
      v.push_back(3), v.push_back(2);
      d--;
    }
    if (d) v.push_back(3), d--;
    if (!d) {
      ans = v;
      return 1;
    } else
      return 0;
  } else {
    if (c > d) {
      if (c - 1 > d) return 0;
      for (int i = 0; i < d; i++) ans.push_back(2), ans.push_back(3);
      ans.push_back(c);
      return 1;
    }
    while (c--) {
      ans.push_back(3), ans.push_back(2);
      d--;
    }
    if (d) ans.push_back(3), d--;
    return (!d);
  }
}
bool chkBC(int b, vector<int> v, int c, int d) {
  if (v.size()) {
    if (v.back() == 0) {
      if (c) return 0;
      return chkCD(v, 0, d);
    }
    if (b > c) return 0;
    for (int i = 0; i < b; i++) v.push_back(2), v.push_back(1);
    if (c > b) v.push_back(2);
    return chkCD(v, (c > b) ? c - b - 1 : 0, d);
  } else {
    if (b > c) {
      if (b - 1 > c) return 0;
      for (int i = 0; i < c; i++) v.push_back(1), v.push_back(2);
      v.push_back(1);
      return chkCD(v, 0, d);
    }
    for (int i = 0; i < b; i++) v.push_back(1), v.push_back(2);
    if (chkCD(v, c - b, d)) return 1;
    v.clear();
    for (int i = 0; i < b; i++) v.push_back(2), v.push_back(1);
    if (c > b) v.push_back(2);
    return chkCD(v, (c == b) ? 0 : c - b - 1, d);
  }
}
bool chkAB(int a, int b, int c, int d) {
  if (a - 1 > b) return 0;
  if (a - 1 == b) {
    vector<int> v;
    for (int i = 0; i < b; i++) {
      v.push_back(0);
      v.push_back(1);
    }
    v.push_back(0);
    if (chkBC(0, v, c, d)) return 1;
    return 0;
  }
  vector<int> v;
  for (int i = 0; i < a; i++) v.push_back(0), v.push_back(1);
  if (chkBC(b - a, v, c, d)) return 1;
  v.clear();
  for (int i = 0; i < a; i++) v.push_back(1), v.push_back(0);
  if (b > a) v.push_back(1);
  return (chkBC((b > a) ? b - a - 1 : b - a, v, c, d));
}
int a, b, c, d;
int main() {
  cin >> a >> b >> c >> d;
  if (!chkAB(a, b, c, d)) {
    cout << "NO";
  } else {
    cout << "YES\n";
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  }
  return 0;
}
