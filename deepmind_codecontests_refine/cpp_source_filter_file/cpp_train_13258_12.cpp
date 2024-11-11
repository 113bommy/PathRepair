#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int s, n, x, y;
  cin >> s >> n;
  vector<pair<int, int>> dragons;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    dragons.push_back({x, y});
  }
  sort(dragons.begin(), dragons.end());
  bool can = 1;
  for (auto dragon : dragons) {
    tie(x, y) = dragon;
    if (s < x) {
      can = 0;
      break;
    }
    s += y;
  }
  cout << (can ? "YES" : "NO");
}
