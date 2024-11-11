#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
int n, m;
vector<int> v;
int main() {
  cin >> n >> m;
  v = vector<int>(n + 1);
  v[0] = 0;
  for (int i = 1; i <= n; ++i) cin >> v[i];
  v.push_back(1e9 + 1);
  vector<int> ans;
  bool money = true;
  sort(v.begin(), v.end());
  for (int i = 0; m >= 0 && i <= n; ++i) {
    int nxt = v[i] + 1;
    while (nxt != v[i + 1]) {
      m -= nxt;
      if (m < 0) {
        break;
      }
      ans.push_back(nxt);
      nxt += 1;
    }
  }
  cout << ans.size() << '\n';
  bool first = true;
  for (int i = 0; i < ans.size(); ++i) {
    if (first)
      first = false;
    else
      cout << " ";
    cout << ans[i];
  }
  cout << '\n';
}
