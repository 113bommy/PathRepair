#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double PI = acos(-1.0);
const double e = 2.718281828459;
inline int sgn(double a);
inline long long gcd(long long a, long long b);
inline long long mod_pow(long long x, long long n, long long mod);
inline void Fill(int *a, int *b, int c);
inline int b_s1(int *a, int l, int r, int k);
vector<int> vv;
int main() {
  double n;
  double k;
  cin >> n >> k;
  int sum = 0;
  for (int i = 0; i < (int)n; i++) {
    int t1;
    cin >> t1;
    sum += t1;
  }
  double t = 0;
  for (int i = 0; i < 1000000; i++) {
    t = (double)i;
    if (sgn((((double)sum + k * t)) - (k - 0.5) * (t + n)) >= 0) {
      break;
    }
  }
  cout << t << endl;
  return 0;
}
inline int sgn(double a) { return a < -eps ? -1 : a < eps ? 0 : 1; }
inline long long gcd(long long a, long long b) {
  return a == 0 ? b : gcd(b % a, a);
}
long long mod_pow(long long x, long long n, long long mod) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * x % mod;
    x = x * x % mod;
    n = n >> 1;
  }
  return res;
}
int b_s1(int *a, int l, int r, int k) {
  int m;
  while (l < r) {
    m = l + (r - l) / 2;
    if (a[m] == k)
      return m;
    else if (a[m] < k)
      l = m + 1;
    else
      r = m;
  }
  return -1;
}
void Fill(int *a, int *b, int c) {
  for (int i = a - a; i < b - a; i++) {
    a[i] = c;
  }
}
