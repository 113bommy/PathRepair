#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int mxn = 101010;
int d[mxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pii> v(n);
  for (int i = 0; i < n; i++) {
    cin >> d[i];
    v[i] = {d[i], i};
  }
  sort(v.begin(), v.end(), greater<pii>());
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    ans[i] = 2 * v[i].second + 1;
    if (i > 0) cout << ans[i - 1] << ' ' << ans[i] << '\n';
  }
  for (int i = 0; i < n; i++) {
    if (i + v[i].first - 1 < ans.size()) {
      cout << ans[i + v[i].first - 1] << ' ' << v[i].second * 2 + 2 << '\n';
    } else {
      cout << ans.back() << ' ' << v[i].second * 2 + 2 << '\n';
      ans.push_back(v[i].second * 2 + 2);
    }
  }
}
