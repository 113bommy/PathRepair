#include <bits/stdc++.h>
using namespace std;
int n, m, o, re = 0;
double res = 0;
double val = 10000;
int a[1000010], b[1000010];
bool chk[1000010];
double calc(double d) {
  double ss = 0, sm = 0, ss2 = 0;
  for (int j = 0; j < n; j++) {
    if (ss < 0) ss = 0;
    if (ss2 > 0) ss2 = 0;
    ss += (double)a[j] - d;
    ss2 += (double)a[j] - d;
    sm = max(sm, max(((ss) < 0 ? -(ss) : (ss)), ((ss2) < 0 ? -(ss2) : (ss2))));
  }
  return sm;
}
int main() {
  int i, j, k, l;
  double ll = 0, rr = 20000, mid;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (i = 0; i < 100; i++) {
    mid = (ll + rr) / 2;
    res = calc(mid - val);
    double res2 = calc(mid - val + 1e-12);
    if (res < res2)
      rr = mid;
    else
      ll = mid;
  }
  printf("%.7lf", calc(ll - val));
  return 0;
}
