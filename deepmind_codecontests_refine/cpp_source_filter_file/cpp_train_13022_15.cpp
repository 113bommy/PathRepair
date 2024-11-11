#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  pair<int, int> a[n];
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  for (int i = 1; i <= m; i++) {
    bool in = false;
    for (auto p : a) {
      if (i <= p.second || i >= p.first) {
        in = true;
        break;
      }
    }
    if (!in) ans.push_back(i);
  }
  cout << ans.size() << endl;
  for (auto n : ans) {
    cout << n << " ";
  }
}
