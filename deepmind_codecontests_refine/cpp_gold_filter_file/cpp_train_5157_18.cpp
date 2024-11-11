#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> v(n + 1);
  for (auto &e : v) {
    cin >> e.first >> e.second;
  }
  string dir = "", prev = "";
  int ans = 0;
  for (int i = 1; i < n; i++) {
    prev = dir;
    if (v[i].second > v[i - 1].second) {
      dir = "up";
    } else if (v[i].second < v[i - 1].second) {
      dir = "down";
    } else if (v[i].first > v[i - 1].first) {
      dir = "right";
    } else if (v[i].first < v[i - 1].first) {
      dir = "left";
    }
    if ((prev == "right" && dir == "up") || (prev == "left" && dir == "down") ||
        (prev == "up" && dir == "left") || (prev == "down" && dir == "right"))
      ans++;
  }
  cout << ans;
  return 0;
}
