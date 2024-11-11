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
  for (int i = 0; i < 70; i++) {
    double mi = (lo + hi) / 2;
    int cur = 0;
    vector<double> v;
    for (int j = 0; j < 3; j++) {
      v.push_back(x[cur] + mi),
          cur = upper_bound(x, x + n, x[cur] + mi * 2) - x;
      if (cur == n) break;
    }
    if (cur == n)
      hi = mi, a = v;
    else
      lo = mi;
  }
  cout << setprecision(11) << lo << endl;
  for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
  for (int i = 0; i < 3 - a.size(); i++) cout << 0 << " ";
}
