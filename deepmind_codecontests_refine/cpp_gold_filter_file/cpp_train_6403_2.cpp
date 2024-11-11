#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<int, int>;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vlli = vector<long long int>;
using vpii = vector<pair<int, int>>;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, x, y;
  long double m = 10, curr;
  vector<pair<long double, int>> angle;
  pii ans;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    angle.push_back(make_pair(atan2(1.0 * y, 1.0 * x), i + 1));
  }
  sort((angle).begin(), (angle).end());
  for (int i = 1; i < n; i++) {
    curr = angle[i].first - angle[i - 1].first;
    if (curr < m) m = curr, ans = {angle[i].second, angle[i - 1].second};
  }
  curr = 2 * acos(-1.0) - (-angle[0].first + angle[n - 1].first);
  if (curr < m) m = curr, ans = {angle[n - 1].second, angle[0].second};
  cout << ans.first << " " << ans.second;
}
