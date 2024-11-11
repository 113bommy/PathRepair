#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b > a) return gcd(b, a);
  if (b == 0) return a;
  return gcd(a % b, b);
}
void fix(long long &a, long long &b) {
  long long g = gcd(a, b);
  a /= g;
  b /= g;
}
void solve(int A) {
  long long t = A - 2;
  long long c = 0;
  for (int i = 2; i < A; i++) {
    long long d = 0;
    long long x = A;
    while (x > 0) {
      d += x % i;
      x /= i;
    }
    c += d;
  }
  fix(c, t);
  cout << c << " / " << t << endl;
}
inline void init() {}
int main() {
  init();
  int A;
  while (cin >> A) {
    solve(A);
  }
  return 0;
}
