#include <bits/stdc++.h>
using namespace std;
const int OO = 1e9;
const double EPS = 1e-9;
int n, h;
vector<pair<int, int> > a;
int main() {
  ios::sync_with_stdio(false);
  cout.precision(10);
  cin >> n >> h;
  a.assign(n, make_pair(0, 0));
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  int mx1 = a[n - 1].first, mx2 = a[n - 2].first;
  int mn1 = a[0].first, mn2 = a[1].first, mn3 = (n > 2 ? a[2].first : OO);
  int noChange = mx1 + mx2 - mn1 - mn2;
  int fMax = max(mx1 + mx2, mx1 + mn1 + h);
  int fMin = min(mn2 + mn3, mn1 + mn2 + h);
  vector<int> ans(n, 1);
  if (fMax - fMin < noChange) ans[a[0].second] = 2;
  cout << min(fMax - fMin, noChange) << '\n';
  for (auto& elem : ans) cout << elem << ' ';
  return 0;
}
