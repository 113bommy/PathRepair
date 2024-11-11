#include <bits/stdc++.h>
using namespace std;
double a[1005], b[1005];
double p;
int n;
bool ch(double m) {
  for (int i = 0; i < n; i++) {
    double used = (m + p) / a[i];
    m -= used;
    if (m < 0) return false;
    if (i != n - 1)
      used = (m + p) / b[i + 1];
    else
      used = (m + p) / b[0];
    m -= used;
    if (m < 0) return false;
  }
  return true;
}
int main() {
  cin >> n;
  cin >> p;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  double l = 0, r = 1e9 + 5;
  double m;
  if (!ch(1e9 + 1)) cout << "-1" << endl, exit(0);
  while (abs(r - l) >= 1e-6) {
    m = (r + l) / 2;
    if (ch(m))
      r = m;
    else
      l = m;
  }
  cout << fixed << setprecision(10) << m << endl;
}
