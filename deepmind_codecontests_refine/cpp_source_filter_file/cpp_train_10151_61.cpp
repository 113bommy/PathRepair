#include <bits/stdc++.h>
using namespace std;
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
long long ln, lk, lm;
long long gcd1(long long x, long long y) {
  long long z = y;
  while (x % y != 0) {
    z = x % y;
    x = y;
    y = z;
  }
  return z;
}
long long t, w, b;
void pp(long long x) {
  if (x == 0)
    puts("0 1");
  else {
    long long G = gcd1(x, t);
    printf("%lld/%lld\n", x / G, t / G);
  }
  exit(0);
}
void fmain() {
  cin >> t >> w >> b;
  long long G = gcd1(w, b);
  double tmp = (double)w * b / G;
  if (tmp > t) {
    pp(min(min(w, b) - 1, t));
  }
  long long B = (long long)tmp;
  long long cnt = t / B;
  long long ans = cnt * min(w, b);
  ans += min(B % t, min(w, b) - 1);
  pp(ans);
}
int main() {
  fmain();
  return 0;
}
