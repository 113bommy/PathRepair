#include <bits/stdc++.h>
using namespace std;
vector<double> p, ans;
int main() {
  double v, u;
  int n;
  cin >> n >> v >> u;
  p.resize(n);
  ans.resize(n);
  for (int i = 0; i < n; i++) cin >> p[i];
  double x, y;
  cin >> x >> y;
  for (int i = 1; i < n; i++) {
    ans[i] = p[i] / (double)v;
    double d = sqrt((x - p[i]) * (x - p[i]) + y * y);
    ans[i] += d / (double)u;
  }
  double pep = ans[1];
  for (int i = 2; i < n; i++) pep = min(pep, ans[i]);
  for (int i = 1; i < n; i++)
    if (fabs(pep - ans[i]) <= 1e-5) {
      cout << i + 1;
      return 0;
    }
  return 0;
}
