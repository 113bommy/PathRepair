#include <bits/stdc++.h>
using namespace std;
const int N = 52;
int m, n;
vector<int> A[N], B[N];
struct zb {
  int x, y;
} s[N], t[N];
struct option {
  int x0, y0, x1, y1;
};
vector<option> opt;
inline void move_left(int k) {
  opt.emplace_back((option){s[k].x, s[k].y, s[k].x, s[k].y - 1});
  --s[k].y;
}
inline void move_right(int k) {
  opt.emplace_back((option){s[k].x, s[k].y, s[k].x, s[k].y + 1});
  ++s[k].y;
}
inline void move_up(int k) {
  opt.emplace_back((option){s[k].x, s[k].y, s[k].x - 1, s[k].y});
  --s[k].x;
}
inline void move_down(int k) {
  opt.emplace_back((option){s[k].x, s[k].y, s[k].x + 1, s[k].y});
  ++s[k].x;
}
void LEFT() {
  for (int i = 1; i <= n; ++i) {
    sort(A[i].begin(), A[i].end(),
         [&](const int& x, const int& y) { return s[x].y < s[y].y; });
    for (int j = 1; j <= (int)A[i].size(); ++j) {
      int id = A[i][j - 1];
      while (s[id].y > j) move_left(id);
    }
  }
  static bool vis[N];
  for (int i = 1; i <= m; ++i)
    if (s[i].y == 1) vis[s[i].x] = 1;
  for (int i = 1; i <= n; ++i)
    if (!vis[i]) {
      int id = 0;
      for (int j = 1; j <= m; ++j)
        if (id == 0 && s[j].y > 1)
          id = j;
        else if (s[j].y > s[id].y ||
                 (s[j].y == s[id].y && abs(s[j].x - i) < abs(s[id].x - i)))
          id = j;
      while (s[id].x > i) move_up(id);
      while (s[id].x < i) move_down(id);
      while (s[id].y > 1) move_left(id);
    }
}
void RIGHT() {
  static bool vis[N][N];
  for (int i = 1; i <= n; ++i) {
    sort(B[i].begin(), B[i].end(),
         [&](const int& x, const int& y) { return t[x].y > t[y].y; });
    for (int j = 0; j < (int)B[i].size(); ++j) {
      int id = B[i][j], _y = n - j;
      if (!vis[i][2]) move_right(id);
      while (i < s[id].x) move_up(id);
      while (i > s[id].x) move_down(id);
      while (_y > s[id].y) move_right(id);
      vis[i][_y] = 1;
    }
  }
  for (int i = 1; i <= n; ++i) {
    reverse(B[i].begin(), B[i].end());
    for (int id : B[i])
      while (s[id].y > t[id].y) move_left(id);
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> s[i].x >> s[i].y;
    A[s[i].x].emplace_back(i);
  }
  for (int i = 1; i <= m; ++i) {
    cin >> t[i].x >> t[i].y;
    B[t[i].x].emplace_back(i);
  }
  LEFT();
  RIGHT();
  cout << opt.size() << '\n';
  for (auto i : opt)
    cout << i.x0 << ' ' << i.y0 << ' ' << i.x1 << ' ' << i.y1 << '\n';
  return 0;
}
