#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) {
  return a.first > b.first || (a.first == b.first && a.second < b.second);
}
int main() {
  int n, t1, t2, k;
  cin >> n >> t1 >> t2 >> k;
  pair<double, int> ans[10000];
  for (int i = 0; i < n; i++) {
    double a, b;
    cin >> a >> b;
    if (a * t1 - (a * t1) / 100 * k + b * t2 <
        b * t1 - (b * t1) / 100 * k + a * t2)
      swap(a, b);
    ans[i].first = -(a * t1 - (a * t1) / 100 * k + b * t2);
    ans[i].second = i + 1;
  }
  sort(ans, ans + n);
  for (int i = 0; i < n; i++)
    cout << ans[i].second << " " << fixed << setprecision(2) << -ans[i].first
         << endl;
  return 0;
}
