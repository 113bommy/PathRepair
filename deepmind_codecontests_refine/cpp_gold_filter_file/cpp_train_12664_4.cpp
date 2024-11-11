#include <bits/stdc++.h>
using namespace std;
vector<double> sum;
double ans(double maxx) {
  int n = sum.size();
  int l = 0, r = max(0, (int)sum.size() - 2);
  while (r - l > 3) {
    int m1 = (r - l) / 3 + l;
    int m2 = r - (r - l) / 3;
    if (maxx - (sum[m1] + maxx) / (double)(m1 + 2) <
        maxx - (sum[m2] + maxx) / (double)(m2 + 2)) {
      l = m1;
    } else {
      r = m2;
    }
  }
  vector<double> vals;
  for (int i = l; i <= r; i++) {
    double val = maxx - (sum[i] + maxx) / (double)(i + 2);
    vals.push_back(val);
  }
  return *max_element(vals.begin(), vals.end());
}
int main() {
  int n;
  cin >> n;
  double x = 0;
  while (n--) {
    int type;
    cin >> type;
    if (type == 1) {
      cin >> x;
      sum.push_back(x + (sum.size() ? sum.back() : 0));
    } else {
      cout << fixed << setprecision(10) << ans(x) << "\n";
    }
  }
}
