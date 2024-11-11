#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t1, t2, k;
  cin >> n >> t1 >> t2 >> k;
  vector<pair<double, int> > ans(n);
  for (int(i) = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    double val1 = 1.0 * a * t1 * (1 - 0.01 * k) + 1.0 * b * t2;
    double val2 = 1.0 * b * t1 * (1 - 0.01 * k) + 1.0 * a * t2;
    ans[i] = make_pair(max(val1, val2), i);
  }
  for (int(i) = 0; i < n; i++) {
    for (int(j) = 0; j < n - 1; j++) {
      if (ans[j].first < ans[j + 1].first ||
          (ans[j].first == ans[j + 1].first &&
           ans[j].second > ans[j + 1].second)) {
        pair<double, int> tem;
        tem = ans[j];
        ans[j] = ans[j + 1];
        ans[j + 1] = tem;
      }
    }
  }
  for (int(i) = 0; i < n; i++) {
    printf("%d %0.4f\n", ans[i].second + 1, ans[i].first);
  }
  return 0;
}
