#include <bits/stdc++.h>
using namespace std;
int toNumber(string s) {
  int Number;
  if (!(istringstream(s) >> Number)) Number = 0;
  return Number;
}
string toString(int number) {
  ostringstream ostr;
  ostr << number;
  return ostr.str();
}
long long ele(long long a, long long b) {
  if (b == 0) return 1;
  if (b % 2 == 0) {
    return ele((a * a), b / 2);
  } else {
    return a * ele((a * a), b / 2);
  }
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
struct fraccion {
  long long a, b;
};
fraccion frac(long long a, long long b) {
  fraccion f;
  long long g = gcd(a, b);
  f.a = a / g;
  f.b = b / g;
  return f;
}
fraccion getMax(fraccion F1, fraccion F2) {
  if (F1.a * F2.b <= F2.a * F1.b) return F2;
  return F1;
}
fraccion getMin(fraccion F1, fraccion F2) {
  fraccion fm = getMax(F1, F2);
  if (fm.a == F1.a && fm.b == F1.b) return F2;
  return F1;
}
bool isGreater(fraccion F1, fraccion F2) { return F1.a * F2.b >= F2.a * F1.b; }
fraccion ceroIfNeg(fraccion f) {
  if ((f.a > 0 && f.b < 0) || (f.a < 0 && f.b > 0)) return frac(0, 1);
  return f;
}
fraccion muchoIfNeg(fraccion f) {
  if ((f.a > 0 && f.b < 0) || (f.a < 0 && f.b > 0)) return frac(99999999, 1);
  return f;
}
bool isFracNeg(fraccion f) {
  return (f.a > 0 && f.b < 0) || (f.a < 0 && f.b > 0);
}
void solve(int caso) {
  int n;
  scanf("%d", &n);
  long long x1, x2, y1, y2;
  scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
  vector<pair<double, double> > tiempos;
  fraccion entraMax, saleMin;
  for (int i = 0; i < (int)(n); i++) {
    long long rx, ry, vx, vy;
    scanf("%lld %lld %lld %lld", &rx, &ry, &vx, &vy);
    if (vx == 0 && (rx <= x1 || rx >= x2)) {
      cout << "-1\n";
      return;
    }
    if (vy == 0 && (ry <= y1 || ry >= y2)) {
      cout << "-1\n";
      return;
    }
    fraccion t_entraX, t_saleX, t_entraY, t_saleY;
    if (vx > 0) {
      t_entraX = frac(x1 - rx, vx);
    } else if (vx < 0) {
      t_entraX = frac(x2 - rx, vx);
    } else {
      t_entraX = frac(0, 1);
    }
    t_entraX = ceroIfNeg(t_entraX);
    if (vx > 0) {
      t_saleX = frac(x2 - rx, vx);
    } else if (vx < 0) {
      t_saleX = frac(x1 - rx, vx);
    } else {
      t_saleX = frac(99999999, 1);
    }
    if (vy > 0) {
      t_entraY = frac(y1 - ry, vy);
    } else if (vy < 0) {
      t_entraY = frac(y2 - ry, vy);
    } else {
      t_entraY = frac(0, 1);
    }
    t_entraY = ceroIfNeg(t_entraY);
    if (vy > 0) {
      t_saleY = frac(y2 - ry, vy);
    } else if (vy < 0) {
      t_saleY = frac(y1 - ry, vy);
    } else {
      t_saleY = frac(99999999, 1);
    }
    if (isFracNeg(t_saleX) || isFracNeg(t_saleY)) {
      cout << "-1\n";
      return;
    }
    fraccion postaEntra = getMax(t_entraX, t_entraY);
    fraccion postaSale = getMin(t_saleX, t_saleY);
    if (i == 0) {
      entraMax = postaEntra;
    } else {
      entraMax = getMax(entraMax, postaEntra);
    }
    if (i == 0) {
      saleMin = postaSale;
    } else {
      saleMin = getMin(saleMin, postaSale);
    }
  }
  entraMax = ceroIfNeg(entraMax);
  if (isGreater(entraMax, saleMin)) {
    cout << "-1\n";
    return;
  }
  printf("%.9f\n", double(entraMax.a) / entraMax.b);
}
int main() {
  int T;
  T = 1;
  for (int caso = 0; caso < (int)(T); caso++) {
    solve(caso);
  }
}
