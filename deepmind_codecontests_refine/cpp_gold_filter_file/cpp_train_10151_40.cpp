#include <bits/stdc++.h>
using namespace std;
template <class T>
T Gcd(T a, T b) {
  if (a > b) a ^= b ^= a ^= b;
  return !a ? b : Gcd(b % a, a);
}
long long Lcm(long long a, long long b) { return a / Gcd(a, b) * b; }
void Solve() {
  int i, j, k, n, m;
  long long t, w, b;
  scanf("%I64d %I64d %I64d", &t, &w, &b);
  long long mn = min(w, b);
  long long gcd = Gcd(w, b);
  long long a1 = w / gcd;
  long long r;
  if (b > t / a1) {
    r = min(t, mn - 1);
  } else {
    b *= a1;
    r = (t / b) * mn - 1 + min((t % b) + 1, mn);
  }
  gcd = Gcd(r, t);
  r /= gcd;
  t /= gcd;
  printf("%I64d/%I64d", r, t);
}
int main() {
  Solve();
  return 0;
}
