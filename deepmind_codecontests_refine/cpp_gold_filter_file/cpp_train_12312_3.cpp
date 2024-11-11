#include <bits/stdc++.h>
using namespace std;
constexpr int inf = 1e9 + 5;
void umin(int& a, int b) { a = min(a, b); }
void umax(int& a, int b) { a = max(a, b); }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<array<int, 2>> a(n);
  for (auto& ai : a) {
    string s;
    cin >> s;
    for (char c : s) ai[c == 'N']++;
  }
  int min_x = inf, min_y = inf, min_xy = inf;
  int max_x = -inf, max_y = -inf, max_xy = -inf;
  for (const auto& ai : a) {
    umin(min_x, ai[0]);
    umin(min_y, ai[1]);
    umin(min_xy, ai[0] - ai[1]);
    umax(max_x, ai[0]);
    umax(max_y, ai[1]);
    umax(max_xy, ai[0] - ai[1]);
  }
  auto checkAns = [&](int m) -> pair<int, int> {
    int min_x2 = min_x + m;
    int min_y2 = min_y + m;
    int min_xy2 = min_xy + m;
    int max_x2 = max(0, max_x - m);
    int max_y2 = max(0, max_y - m);
    int max_xy2 = max_xy - m;
    if (min_x2 >= max_x2 && min_y2 >= max_y2 && min_xy2 >= max_xy2) {
      for (int x : {min_x2, max_x2}) {
        for (int xy : {min_xy2, max_xy2}) {
          int y = x - xy;
          if (max_y2 <= y && y <= min_y2 && y >= 0 && x + y > 0) return {x, y};
        }
      }
      for (int y : {min_y2, max_y2}) {
        for (int xy : {min_xy2, max_xy2}) {
          int x = y + xy;
          if (max_x2 <= x && x <= min_x2 && x >= 0 && x + y > 0) return {x, y};
        }
      }
    }
    return {-1, -1};
  };
  int l = 0, r = 1e6, dist = -1;
  pair<int, int> ans = {-1, -1};
  while (l < r) {
    int m = (l + r) / 2;
    pair<int, int> ret = checkAns(m);
    if (ret.first != -1) {
      r = m;
      dist = m;
      ans = ret;
    } else {
      l = m + 1;
    }
  }
  cout << dist << '\n';
  cout << string(ans.first, 'B') << string(ans.second, 'N') << '\n';
  return 0;
}
