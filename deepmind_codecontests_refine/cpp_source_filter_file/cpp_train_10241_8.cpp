#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int toi(string s) {
  int r = 0;
  istringstream sin(s);
  sin >> r;
  return r;
}
string tos(int n) {
  ostringstream ost;
  ost << n;
  ost.flush();
  return ost.str();
}
bool isnumber(string s) {
  for (int i = 0; i < s.length(); ++i)
    if (!isdigit(s[i])) return false;
  return true;
}
int i, n, fp, ln, t;
long x[500001], v[500001];
int f(long double mid) {
  double ma = -(int)1e9;
  for (i = fp; i < ln + 1; i++) {
    double pos = x[i] + mid * v[i];
    if (v[i] < 0) {
      if (pos <= ma) return 1;
    } else
      ma = max(ma, pos);
  }
  return 0;
}
int main() {
  n = ({
    int t;
    scanf("%d", &t);
    t;
  });
  for (int i = 0; i < n; i++) cin >> x[i] >> v[i];
  fp = ln = -1;
  for (int i = n - 1; i >= 0; i--)
    if (v[i] > 0) fp = i;
  for (int i = 0; i < n; i++)
    if (v[i] < 0) ln = i;
  if (fp == -1 || ln == 1 || fp > ln) {
    cout << -1 << endl;
    return 0;
  }
  double lo = 0.0, hi = 2e9, mid = (lo + hi) / 2.0;
  for (int t = 0; t < 100; t++) {
    if (f(mid))
      hi = mid;
    else
      lo = mid;
    mid = (lo + hi) / 2;
  }
  printf("%.15lf", mid);
  return 0;
}
