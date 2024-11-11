#include <bits/stdc++.h>
using namespace std;
long long n, m, x, t, q, l, k = 1, y, z, a[205], b[205];
vector<pair<pair<int, int>, int> > ans;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  ans.push_back({{0, 0}, 0});
  for (int i = 1; i <= n; ++i) {
    cin >> x >> y;
    z = 1;
    for (int j = 0; j < i; ++j)
      if (x > ans[j].first.second &&
          (j == i - 1 || x + y < ans[j + 1].first.first)) {
        ans.push_back({{x, x + y - 1}, i});
        sort(ans.begin(), ans.end());
        z = 0;
        break;
      }
    if (!z) continue;
    for (int j = 1; j < i; ++j) {
      if (ans[j].first.first - ans[j - 1].first.second >= y + 1) {
        ans.push_back(
            {{ans[j - 1].first.second + 1, ans[j - 1].first.second + y}, i});
        sort(ans.begin(), ans.end());
        z = 0;
        break;
      }
    }
    if (!z) continue;
    ans.push_back(
        {{ans[i - 1].first.second + 1, ans[i - 1].first.second + y}, i});
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (ans[j].second == i)
        cout << ans[j].first.first << " " << ans[j].first.second << endl;
    }
  }
}
