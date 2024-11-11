#include <bits/stdc++.h>
using namespace std;
const int MaxN = 100500;
const double eps = 1e-9;
vector<double> ans;
int main() {
  long long i, j, n, m, a, d, t, v;
  double tt, di;
  cin >> n >> a >> d;
  for (i = 0; i < n; i++) {
    cin >> t >> v;
    di = d;
    if (di < (v * v) / (double)(2 * a) - eps) {
      tt = sqrt((2 * di) / (double)a);
    } else {
      tt = v / (double)a;
      di -= (v * v) / (double)(2 * a);
      tt += di / (double)v;
    }
    tt += t;
    if (i == 0) {
      ans.push_back(tt);
    } else {
      tt = max(ans[ans.size() - 1], tt);
      ans.push_back(tt);
    }
  }
  for (i = 0; i < ans.size(); i++) {
    cout << setiosflags(ios::fixed) << setprecision(4) << ans[i] << endl;
  }
  cin.get();
  cin.get();
}
