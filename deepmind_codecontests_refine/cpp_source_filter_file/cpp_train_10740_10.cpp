#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  int q;
  cin >> q;
  while (q--) {
    vector<pair<int, int>> ans;
    int b, w;
    cin >> b >> w;
    int sx = 2, sy = 2;
    if (w > b) sx = 2, sy = 3, swap(b, w);
    if (w > 3 * b + 1) {
      cout << "NO" << '\n';
      continue;
    }
    for (int i = 0; i < w; ++i) ans.push_back({sx + i * 2, sy});
    for (int j = 0; j <= w; ++j) {
      if (!b) break;
      b--;
      ans.push_back({sx + 2 * j - 1, sy});
    }
    for (int i = 0; i < w; ++i) {
      if (!b) break;
      b--;
      ans.push_back({sx + i * 2, sy - 1});
    }
    for (int i = 0; i < w; ++i) {
      if (!b) break;
      b--;
      ans.push_back({sx + i * 2, sy + 1});
    }
    cout << "YES" << '\n';
    for (auto p : ans) cout << p.first << " " << p.second << '\n';
  }
}
