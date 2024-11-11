#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n, x, y;
  cin >> n;
  vector<pair<int, int> > a, b;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    if (x < 0)
      a.push_back(make_pair(-x, y));
    else
      b.push_back(make_pair(x, y));
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int ans = 0;
  if (a.size() == b.size()) {
    for (int i = 0; i < a.size(); i++) ans += a[i].second + b[i].second;
  } else if (a.size() > b.size()) {
    for (int i = 0; i < b.size(); i++) ans += a[i].second + b[i].second;
    ans += a[b.size()].second;
  } else {
    for (int i = 0; i < a.size(); i++) ans += a[i].second + b[i].second;
    ans += b[a.size()].second;
  }
  cout << ans << endl;
}
