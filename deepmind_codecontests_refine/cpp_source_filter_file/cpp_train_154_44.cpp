#include <bits/stdc++.h>
using namespace std;
const double inf = 100000000000000000;
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 10;
const int maxv = 1e3 + 10;
const double eps = 1e-9;
int ju = 0;
double f22(double a, double b) {
  if (ju) a = 1.0 / a;
  if (a > 1.0 - eps) return log(log(a)) + log(b);
  return -inf;
}
double f33(double a, double b, double c) {
  if (ju) a = 1.0 / a;
  if (a > 1.0 - eps) return log(log(a)) + c * log(b);
  return -inf;
}
double f1(double a, double b, double c) { return f33(a, b, c); }
double f2(double a, double b, double c) { return f33(a, c, b); }
double f3(double a, double b, double c) { return f22(a, b * c); }
double f4(double a, double b, double c) { return f22(a, b * c); }
double f5(double a, double b, double c) { return f33(b, a, c); }
double f6(double a, double b, double c) { return f33(b, c, a); }
double f7(double a, double b, double c) { return f22(b, a * c); }
double f8(double a, double b, double c) { return f22(b, a * c); }
double f9(double a, double b, double c) { return f33(c, a, b); }
double f10(double a, double b, double c) { return f33(c, b, a); }
double f11(double a, double b, double c) { return f22(c, a * b); }
double f12(double a, double b, double c) { return f22(c, a * b); }
bool judge(double l, double r, int ju) {
  if (ju) return l < r + eps;
  return l > r + eps;
}
int main() {
  double x, y, c;
  while (scanf("%lf%lf%lf", &x, &y, &c) != EOF) {
    ju = 0;
    if (x < 1.0 - eps && y < 1.0 - eps && c < 1.0 - eps) {
      ju = 1;
    }
    double res = 0;
    int id = 0;
    res = f1(x, y, c);
    id = 1;
    if (judge(res, f2(x, y, c), ju)) {
      res = f2(x, y, c);
      id = 2;
    }
    if (judge(res, f3(x, y, c), ju)) {
      res = f3(x, y, c);
      id = 3;
    }
    if (judge(res, f4(x, y, c), ju)) {
      res = f4(x, y, c);
      id = 4;
    }
    if (judge(res, f5(x, y, c), ju)) {
      res = f5(x, y, c);
      id = 5;
    }
    if (judge(res, f6(x, y, c), ju)) {
      res = f6(x, y, c);
      id = 6;
    }
    if (judge(res, f7(x, y, c), ju)) {
      res = f7(x, y, c);
      id = 7;
    }
    if (judge(res, f8(x, y, c), ju)) {
      res = f8(x, y, c);
      id = 8;
    }
    if (judge(res, f9(x, y, c), ju)) {
      res = f9(x, y, c);
      id = 9;
    }
    if (judge(res, f10(x, y, c), ju)) {
      res = f10(x, y, c);
      id = 10;
    }
    if (judge(res, f11(x, y, c), ju)) {
      res = f11(x, y, c);
      id = 11;
    }
    if (judge(res, f12(x, y, c), ju)) {
      res = f12(x, y, c);
      id = 12;
    }
    if (id == 1)
      puts("x^y^z");
    else if (id == 2)
      puts("x^z^y");
    else if (id == 3)
      puts("(x^y)^z");
    else if (id == 4)
      puts("(x^z)^y");
    else if (id == 5)
      puts("y^x^z");
    else if (id == 6)
      puts("y^z^x");
    else if (id == 7)
      puts("(y^x)^z");
    else if (id == 8)
      puts("(y^z)^x");
    else if (id == 9)
      puts("z^x^y");
    else if (id == 10)
      puts("z^y^x");
    else if (id == 11)
      puts("(z^x)^y");
    else
      puts("(z^y)^x");
  }
  return 0;
}
