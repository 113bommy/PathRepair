#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<pair<int, int>> v;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v.push_back({x, y});
  }
  int s = 0, g = 0;
  for (int i = 0; i < n; i++) {
    g = g + v[i].second - v[i].first;
    s = max(s, g);
  }
  cout << s << endl;
  return 0;
}
