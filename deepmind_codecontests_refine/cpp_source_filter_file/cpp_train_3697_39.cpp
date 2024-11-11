#include <bits/stdc++.h>
using namespace std;
bool eq(double x, double y) {
  if (fabs(x - y) < 1e-10)
    return true;
  else
    return false;
}
int main() {
  int n;
  int a[2005], b[2005], c[2005];
  pair<double, double> x[2005];
  scanf("%d", &n);
  for (int i = int(0); i <= int(n - 1); i++) {
    scanf("%d %d %d", &a[i], &b[i], &c[i]);
    x[i].first = a[i] * c[i] / (double)(a[i] * a[i] + b[i] * b[i]);
    x[i].second = b[i] * c[i] / (double)(a[i] * a[i] + b[i] * b[i]);
  }
  int tot = 0;
  double pi = atan2(0, -1);
  for (int zero = int(0); zero <= int(n - 1); zero++) {
    vector<double> all;
    int coincide = 0;
    for (int i = int(0); i <= int(n - 1); i++) {
      if (i != zero) {
        double u = x[i].first - x[zero].first;
        double v = x[i].second - x[zero].second;
        if (eq(u, 0) && eq(v, 0))
          coincide++;
        else {
          double z = atan2(v, u);
          if (z < 0) z += pi;
          all.push_back(z);
        }
      }
    }
    if (coincide > 0) {
      int notcoincide = n - 1 - coincide;
      tot += (coincide * (coincide - 1)) / 2;
      tot += coincide * notcoincide;
    }
    if (all.size() > 0) {
      sort(all.begin(), all.end());
      int encours = 1;
      for (int k = 0; k < all.size(); k++) {
        if (k != 0 && eq(all[k], all[k - 1]))
          encours++;
        else if (k != 0) {
          if (encours > 1) {
            tot += (encours * (encours - 1)) / 2;
          }
          encours = 1;
        }
      }
      if (encours > 1) {
        tot += (encours * (encours - 1)) / 2;
      }
      int m = all.size();
      if (all[0] <= 1e-10 && all[m - 1] >= pi - 1e-10) {
        int s = 1;
        int t = m - 2;
        while (eq(all[s], all[0])) s++;
        while (eq(all[t], all[m - 1])) t--;
        tot += s * (m - 1 - t);
      }
    }
  }
  cout << (tot + 2) / 3 << endl;
  return 0;
}
