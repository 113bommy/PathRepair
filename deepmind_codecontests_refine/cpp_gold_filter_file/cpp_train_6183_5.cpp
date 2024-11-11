#include <bits/stdc++.h>
using namespace std;
const int inf = 1999999999;
const double pi = acos(-1.0);
const double eps = 1e-10;
char gc() {
  char c;
  while (isspace(c = getchar()))
    ;
  return c;
}
int gs(char* s) {
  gets(s);
  int l = strlen(s);
  while (l && isspace(s[l - 1])) s[--l] = 0;
  return l;
}
int main() {
  ios::sync_with_stdio(false);
  cout.precision(8);
  int l, d, v, g, r;
  cin >> l >> d >> v >> g >> r;
  int m = g + r;
  double t = (double)d / v;
  double a = t - (int)(t / m + eps) * m;
  if (a >= g - eps) t = ((int)(t / m) + 1) * m;
  cout << t + double(l - d) / v;
  return 0;
}
