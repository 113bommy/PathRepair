#include <bits/stdc++.h>
using namespace std;
struct Func {
  int a, b;
  double w;
  Func(int _a, int _b, double _w) : a(_a), b(_b), w(_w) {}
  double operator()(const double &th) {
    return a / cos(th) + b / sin(th) - w / tan(th) - w * tan(th);
  }
};
const double pi = acos(-1), phi = (sqrt(5) - 1) / 2;
const double minr = 1e-9;
double getMinV(int a, int b, double w) {
  Func fun(a, b, w);
  double lb = 0, rb = pi / 2, r = lb + (rb - lb) * phi,
         l = rb + (lb - rb) * phi;
  double lv = fun(l), rv = fun(r);
  while (rb - lb > minr) {
    if (lv < rv) {
      rb = r;
      r = l, rv = lv;
      l = rb + (lb - rb) * phi, lv = fun(l);
    } else {
      lb = l;
      l = r, lv = rv;
      r = lb + (rb - lb) * phi, rv = fun(r);
    }
  }
  return fun(lb);
}
int main() {
  int a, b, l;
  scanf("%d%d%d", &a, &b, &l);
  double left = 0, right = min(l, a), mid;
  while (right - left > minr) {
    mid = (left + right) / 2;
    if (getMinV(a, b, mid) >= l)
      left = mid;
    else
      right = mid;
  }
  left = max(left, l <= max(a, b) ? min(l, min(a, b)) : 0.0);
  if (left > 0)
    printf("%.8f\n", left);
  else
    puts("My poor head =(");
  return 0;
}
