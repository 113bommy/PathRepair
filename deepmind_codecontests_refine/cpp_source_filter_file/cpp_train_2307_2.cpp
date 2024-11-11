#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  ;
  vector<int> po, ne;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    if (t >= 0)
      po.push_back(t);
    else
      ne.push_back(-t);
  }
  sort(po.begin(), po.end());
  sort(ne.begin(), ne.end());
  long long ans = 0;
  for (int i = 0; i < po.size(); i++) {
    ans += upper_bound(po.begin(), po.end(), 2 * po[i]) -
           upper_bound(po.begin(), po.end(), po[i]);
  }
  for (int i = 0; i < ne.size(); i++) {
    ans += upper_bound(ne.begin(), ne.end(), 2 * ne[i]) -
           upper_bound(ne.begin(), ne.end(), ne[i]);
  }
  for (int i = 0; i < ne.size(); i++) {
    ans += upper_bound(po.begin(), po.end(), 2 * ne[i]) -
           lower_bound(po.begin(), po.end(), ne[i]);
  }
  for (int i = 0; i < po.size(); i++) {
    ans += upper_bound(ne.begin(), ne.end(), 2 * po[i]) -
           lower_bound(ne.begin(), ne.end(), po[i]);
  }
  cout << ans << endl;
}
