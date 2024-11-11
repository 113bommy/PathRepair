#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
class Fraction {
 public:
  int a, b;
  Fraction() : a(0), b(1) {}
  Fraction(int a, int b) : a(a), b(b) {}
  Fraction operator*(const Fraction &f) const {
    return Fraction(1LL * a * f.a % 998244353, 1LL * b * f.b % 998244353);
  }
  Fraction operator+(const Fraction &f) const {
    long long d = 1LL * b / gcd(b, f.b) * f.b;
    long long newa = 1LL * a * d / b + 1LL * f.a * d / f.b;
    return Fraction(newa % 998244353, d % 998244353);
  }
  Fraction operator-() const { return Fraction(998244353 - a, b); }
  Fraction operator-(const Fraction &f) const { return *this + (-f); }
  Fraction inv() { return Fraction(b, a); }
  friend ostream &operator<<(ostream &out, const Fraction &f);
};
ostream &operator<<(ostream &out, const Fraction &f) {
  out << f.a << "/" << f.b;
  return out;
}
int n;
Fraction p, pwp[2005], pw1p[2005];
Fraction cp[2005][2005], pctc[2005];
Fraction sol[2005];
int pwlog(int a, int pw) {
  if (!pw) return 1;
  return 1LL * pwlog(1LL * a * a % 998244353, pw >> 1) * ((pw & 1) ? a : 1) %
         998244353;
}
void precalc() {
  pwp[0] = pw1p[0] = Fraction(1, 1);
  Fraction p1 = Fraction(1, 1) - p;
  for (int i = 1; i <= n; ++i) {
    pwp[i] = pwp[i - 1] * p;
    pw1p[i] = pw1p[i - 1] * p1;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> p.a >> p.b;
  precalc();
  cp[1][0] = cp[1][1] = Fraction(1, 1);
  for (int i = 2; i <= n; ++i) {
    cp[i][0] = Fraction(1, 1);
    for (int j = 1; j <= i; ++j)
      cp[i][j] = cp[i - 1][j - 1] * pw1p[i - j] + cp[i - 1][j] * pwp[j];
  }
  pctc[1] = Fraction(1, 1);
  pctc[2] = Fraction(0, 1);
  for (int i = 3; i <= n; ++i) {
    Fraction f;
    for (int j = 1; j < i; ++j) f = f + pctc[j] * cp[i][j];
    pctc[i] = Fraction(1, 1) - f;
  }
  for (int i = 2; i <= n; ++i) {
    sol[i] = Fraction(1LL * i * (i - 1) / 2 % 998244353, 1);
    for (int j = 1; j < i; ++j)
      sol[i] = sol[i] +
               pctc[j] * cp[i][j] *
                   (sol[j] + sol[i - j] -
                    Fraction(1LL * (i - j) * (i - j - 1) / 2 % 998244353, 1));
    sol[i] = sol[i] * (Fraction(1, 1) - pctc[i]).inv();
  }
  cout << 1LL * sol[n].a * pwlog(sol[n].b, 998244353 - 2) % 998244353 << "\n";
  return 0;
}
