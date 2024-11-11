#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<pair<int, int>> dec;
  vector<pair<int, int>> inc;
  dec.push_back({1e7, 0});
  inc.push_back({-1e7, 0});
  for (int i = 0; i < n; i++) {
    if (a[i] >= dec[dec.size() - 1].first and
        a[i] <= inc[inc.size() - 1].first) {
      cout << "NO";
      return 0;
    } else if (a[i] < dec[dec.size() - 1].first and
               a[i] <= inc[inc.size() - 1].first) {
      dec.push_back({a[i], i});
    } else if (a[i] >= dec[dec.size() - 1].first and
               a[i] > inc[inc.size() - 1].first) {
      inc.push_back({a[i], i});
    } else {
      if (i < n - 1) {
        if (a[i] > a[i + 1]) {
          dec.push_back({a[i], i});
        } else {
          inc.push_back({a[i], i});
        }
      } else {
        inc.push_back({a[i], i});
      }
    }
  }
  cout << "YES\n";
  vector<int> ans(n, 1);
  for (int i = 1; i < inc.size(); i++) {
    ans[inc[i].second] = 0;
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
