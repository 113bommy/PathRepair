#include <bits/stdc++.h>
using namespace std;
int n;
double x[200010];
vector<double> a;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i];
  sort(x, x + n);
  double lo = 0, hi = 1e9;
  for (int i = 0; i < 60; i++) {
    double mi = (lo + hi) / 2;
    int cur = 0;
    vector<double> v;
    for (int j = 0; j < 3; j++) {
      double to = x[cur] + mi * 2;
      v.push_back(x[cur] + mi);
      int l = -1, h = n;
      while (l + 1 < h) {
        int m = (l + h) / 2;
        if (to + 1e-9 > x[m])
          l = m;
        else
          h = m;
      }
      cur = l + 1;
      if (cur == n) break;
    }
    if (cur == n)
      hi = mi, a = v;
    else
      lo = mi;
  }
  cout << setprecision(6) << lo << endl;
  for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
  for (int i = 0; i < 3 - a.size(); i++) cout << 0 << " ";
}
