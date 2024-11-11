#include <bits/stdc++.h>
using namespace std;
unsigned long long ggd;
unsigned long long gcd(unsigned long long a, unsigned long long b) {
  for (;;) {
    if (a == 0) return b;
    b %= a;
    if (b == 0) return a;
    a %= b;
  }
}
unsigned long long lcm(unsigned long long a, unsigned long long b,
                       unsigned long long t) {
  ggd = gcd(a, b);
  long double l1 = log(a) - log(ggd) + log(b);
  long double l2 = log(t);
  if (l1 > l2 + 1) return t + 1;
  return ggd ? (a / ggd * b) : 0;
}
int main(int argc, char const *argv[]) {
  unsigned long long t, w, b, tmp, tmp2, lastadd, lfin;
  cin >> t >> w >> b;
  lfin = lcm(w, b, t);
  tmp = t / lfin;
  tmp2 = tmp * lfin;
  if (tmp2 + min(w, b) - 1 > t)
    lastadd = t - tmp2;
  else
    lastadd = min(w, b) - 1;
  unsigned long long numer = tmp + tmp * (min(w, b) - 1);
  numer += lastadd;
  ggd = gcd(numer, t);
  numer /= ggd;
  t /= ggd;
  cout << numer << '/' << t;
  return 0;
}
