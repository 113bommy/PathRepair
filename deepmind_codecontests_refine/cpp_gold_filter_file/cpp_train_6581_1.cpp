#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  vector<pair<int, int>> s(t, {0, INT_MAX});
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    string a;
    cin >> a;
    map<pair<int, int>, int> l;
    l.insert({{0, 0}, 0});
    int x = 0, y = 0, j1 = 0, j2 = 0;
    for (int j = 0; j < a.size(); j++) {
      if (a[j] == 'D') {
        y--;
      }
      if (a[j] == 'U') {
        y++;
      }
      if (a[j] == 'R') {
        x++;
      }
      if (a[j] == 'L') {
        x--;
      }
      if (l.find({x, y}) != l.end()) {
        if (s[i].second - s[i].first > j - l[{x, y}]) {
          s[i] = {l[{x, y}] + 1, j + 1};
        }
        l[{x, y}] = j + 1;
      }
      l.insert({{x, y}, j + 1});
    }
  }
  for (int i = 0; i < t; i++) {
    if (s[i].second == INT_MAX) {
      cout << -1 << '\n';
    } else {
      cout << s[i].first << " " << s[i].second << '\n';
    }
  }
}
