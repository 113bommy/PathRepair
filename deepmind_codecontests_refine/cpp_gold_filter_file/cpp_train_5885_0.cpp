#include <bits/stdc++.h>
using namespace std;
const long double PI = 4.0 * atan(1.0);
void EnchomSolve() {
  int l;
  long double L;
  long double ans = 0.0;
  long double area;
  long double height;
  long double help, help2;
  scanf("%d", &l);
  L = (long double)l;
  help = L / sqrt(3.0);
  height = sqrt(L * L - help * help);
  help = (sqrt(3.0) / 2.0) * L;
  area = (help * L) / 2.0;
  ans += area * height / 3.0;
  scanf("%d", &l);
  L = (long double)l;
  help = (sqrt(2.0) / 2.0) * L;
  height = sqrt(L * L - help * help);
  area = L * L;
  ans += area * height / 3.0;
  scanf("%d", &l);
  L = (long double)l;
  help = L / (sqrt(2.0 - 2.0 * cos(72.0 * PI / 180.0)));
  height = sqrt(L * L - help * help);
  help2 = sqrt(help * help - (L / 2.0) * (L / 2.0));
  area = L * help2 / 2.0;
  area *= 5.0;
  ans += area * height / 3.0;
  printf("%.10f\n", (double)ans);
  return;
}
int main() {
  EnchomSolve();
  return 0;
}
