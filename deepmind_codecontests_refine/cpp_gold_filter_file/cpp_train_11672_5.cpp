#include <bits/stdc++.h>
using namespace std;
inline unsigned long long gcd(unsigned long long a, unsigned long long b) {
  return b ? gcd(b, a % b) : a;
}
inline unsigned long long lcm(unsigned long long a, unsigned long long b) {
  return a / gcd(a, b) * b;
}
int month[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int dir[8][2] = {{-1, 0},  {1, 0}, {0, -1}, {0, 1},
                 {-1, -1}, {1, 1}, {1, -1}, {-1, 1}};
const int MAXN = 2e3 + 5;
const int INF = 1 << 30;
const unsigned long long mod = 1e9 + 7;
const double eps = 1e-8;
const unsigned long long inff = 0x3f3f3f3f3f3f3f3f;
int main() {
  unsigned long long num, fri, tol, ne, k;
  cin >> tol >> fri >> num >> ne;
  num += ne;
  k = num / fri + (num % fri == 0 ? 0 : 1);
  if (k * fri > tol)
    cout << -1 << endl;
  else {
    cout << k << endl;
  }
}
