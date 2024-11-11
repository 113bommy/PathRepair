#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-12;
int b[1111], n;
bool check(void) {
  bool le, mo;
  int j;
  double left;
  double l = 0, r = 1111111, m;
  while (r - l > eps) {
    le = false;
    mo = false;
    m = (l + r) / 2;
    left = m;
    for (j = 0; j <= n; j++) {
      if (left < b[j]) le = true;
      if (left > b[j] + 1 - eps) mo = true;
      left += m;
    }
    if (le && mo) return false;
    if (!le && !mo) {
      return true;
    }
    if (le)
      l = m;
    else
      r = m;
  }
  m = (l + r) / 2;
  left = m;
  for (j = 0; j <= n; j++) {
    if (left < b[j]) le = true;
    if (left > b[j] + 1 - eps) mo = true;
    left += m;
  }
  if (le || mo) return false;
  return true;
}
int main(void) {
  int i;
  bool f1, f2;
  while (scanf(" %d", &n) != EOF) {
    for (i = 0; i < n; i++) scanf(" %d", &b[i]);
    if (n <= 2)
      printf("not unique\n");
    else {
      b[n] = b[n - 1] + b[0];
      f1 = check();
      b[n]++;
      f2 = check();
      if (f1 && f2)
        printf("not unique\n");
      else
        printf("unique\n%d\n", f2 ? b[n] : (b[n] - 1));
    }
  }
  return 0;
}
