#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9 + 1;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> v[3][2];
  vector<vector<int>> perms = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2},
                               {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
  for (int i = 0; i < n; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    c--;
    v[c][0].emplace_back(make_pair(x, y));
    v[c][1].emplace_back(make_pair(x, y));
  }
  for (auto& i : v) {
    sort(i[0].begin(), i[0].end());
    sort(i[1].begin(), i[1].end(), [&](pair<int, int>& a, pair<int, int>& b) {
      return make_pair(a.second, a.first) < make_pair(b.second, b.first);
    });
  }
  auto check = [&](int k) -> bool {
    bool ret = false;
    bool flg;
    int x_lim, y_lim;
    for (const auto& p : perms) {
      x_lim = -inf;
      flg = true;
      for (auto x : p) {
        int ths = 0;
        int n_x = x_lim;
        for (auto ele : v[x][0]) {
          if (ths == k) {
            break;
          }
          if (ele.first > x_lim) {
            n_x = max(n_x, ele.first);
            ++ths;
          }
        }
        if (ths < k) {
          flg = false;
        }
        x_lim = n_x;
      }
      ret |= flg;
    }
    for (const auto& p : perms) {
      y_lim = -inf;
      flg = true;
      for (auto x : p) {
        int ths = 0;
        int n_y = y_lim;
        for (auto ele : v[x][1]) {
          if (ths == k) {
            break;
          }
          if (ele.second > y_lim) {
            n_y = max(n_y, ele.second);
            ++ths;
          }
        }
        if (ths < k) {
          flg = false;
        }
        y_lim = n_y;
      }
      ret |= flg;
    }
    for (const auto& p : perms) {
      flg = true;
      x_lim = v[p[0]][0][k - 1].first;
      int ths = 0;
      for (auto ele : v[p[1]][1]) {
        if (ths == k) {
          break;
        }
        if (ele.first > x_lim) {
          y_lim = ele.second;
          ++ths;
        }
      }
      if (ths < k) {
        flg = false;
      }
      ths = 0;
      for (auto ele : v[p[2]][0]) {
        ths += (ele.first > x_lim && ele.second > y_lim);
      }
      if (ths < k) {
        flg = false;
      }
      ret |= flg;
    }
    for (const auto& p : perms) {
      flg = true;
      y_lim = v[p[0]][1][k - 1].second;
      int ths = 0;
      for (auto ele : v[p[1]][0]) {
        if (ths == k) {
          break;
        }
        if (ele.second > y_lim) {
          x_lim = ele.first;
          ++ths;
        }
      }
      if (ths < k) {
        flg = false;
      }
      ths = 0;
      for (auto ele : v[p[2]][0]) {
        ths += (ele.first > x_lim && ele.second > y_lim);
      }
      if (ths < k) {
        flg = false;
      }
      ret |= flg;
    }
    for (const auto& p : perms) {
      flg = true;
      x_lim = v[p[0]][0][n / 3 - k].first;
      int ths = 0;
      for (auto ele : v[p[1]][1]) {
        if (ths == k) {
          break;
        }
        if (ele.first < x_lim) {
          y_lim = ele.second;
          ++ths;
        }
      }
      if (ths < k) {
        flg = false;
      }
      ths = 0;
      for (auto ele : v[p[2]][0]) {
        ths += (ele.first < x_lim && ele.second > y_lim);
      }
      if (ths < k) {
        flg = false;
      }
      ret |= flg;
    }
    for (const auto& p : perms) {
      flg = true;
      y_lim = v[p[0]][1][n / 3 - k].second;
      int ths = 0;
      for (auto ele : v[p[1]][0]) {
        if (ths == k) {
          break;
        }
        if (ele.second < y_lim) {
          x_lim = ele.first;
          ++ths;
        }
      }
      if (ths < k) {
        flg = false;
      }
      ths = 0;
      for (auto ele : v[p[2]][0]) {
        ths += (ele.first > x_lim && ele.second < y_lim);
      }
      if (ths < k) {
        flg = false;
      }
      ret |= flg;
    }
    return ret;
  };
  int l = 1, r = n / 3;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (check(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << 3 * l << '\n';
  return 0;
}
