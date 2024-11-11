#include <bits/stdc++.h>
using namespace std;
long long t, w, b, gd;
inline long long gcd(long long x, long long y) {
  while (x > 0 && y > 0) {
    if (x > y) {
      x %= y;
    } else {
      y %= x;
    }
  }
  return x + y;
}
bool isBig(long long x, long long y) {
  long double tmp = x / gd;
  long double tmp2 = t * 1.0 / y;
  return tmp > tmp2;
  return ((x / gd) * y > (long double)t);
}
int main(int argc, char const *argv[]) {
  cin >> t >> w >> b;
  long long byW, byB, by2;
  if (w == b) {
    cout << "1/1" << endl;
    return 0;
  }
  gd = gcd(w, b);
  byW = t / w;
  byB = t / b;
  long long tot = 0;
  long long mn = min(w, b) - 1;
  if (isBig(w, b)) {
    by2 = 0;
    tot = min(mn, t);
  } else {
    long long lm = (w / gd) * b;
    by2 = t / (lm);
    tot = (t / lm) * (mn) + min(t % lm, mn);
  }
  tot += by2;
  long long den = t;
  long long gd2 = gcd(tot, den);
  cout << tot / gd2 << "/" << den / gd2 << endl;
  return 0;
}
