#include <bits/stdc++.h>
#pragma GCC optimize "-O3"
using namespace std;
void setIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
int main() {
  setIO();
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (auto &i : a) {
    cin >> i.first >> i.second;
  }
  int res1 = 0, res2 = 0;
  for (int i = 0; i < n; i++) {
    if (a[i].first > res1) {
      res1 = (a[i].first + a[i].second);
      res2 = max(res2, a[i].second);
    } else {
      res2 = max(res2, res1 - a[i].first + a[i].second);
      res1 += a[i].second;
    }
  }
  cout << res1 << ' ' << res2 << '\n';
}
