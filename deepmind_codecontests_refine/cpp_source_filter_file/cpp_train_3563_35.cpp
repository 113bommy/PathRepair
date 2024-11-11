#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int size1 = 4e5;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  static int g[81][81], g1[81][81];
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> g[i][j];
      g1[j][i] = g[i][j];
    }
  }
  const int c = 81;
  vector<vector<vector<pair<int, int>>>> v(c);
  for (int i = 0; i < 81; ++i) {
    v[i].resize(c);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = 1; k <= n; ++k) {
        if (k != i && k != j) {
          v[i][j].push_back({g[i][k] + g[k][j], k});
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      sort(v[i][j].begin(), v[i][j].end());
    }
  }
  if (k == 2) {
    cout << v[1][1][0].first;
    return 0;
  }
  const int INF = 2e9;
  if (k == 4) {
    int ans = INF;
    int cur = 0;
    for (int i1 = 1; i1 <= n; ++i1) {
      cur = 0;
      bool res = true;
      if (v[1][i1].empty()) {
        res = false;
      }
      if (v[i1][1].empty()) {
        res = false;
      }
      for (int i = 0; i < v[1][i1].size(); ++i) {
        if (v[1][i1][i].second != 1 && v[1][i1][i].second != i1) {
          cur += v[1][i1][i].first;
          break;
        }
        if (1 + i == v[1][i1].size()) {
          res = false;
        }
      }
      for (int i = 0; i < v[i1][1].size(); ++i) {
        if (v[i1][1][i].second != 1 && v[i1][1][i].second != i1) {
          cur += v[i1][1][i].first;
          break;
        }
        if (1 + i == v[i1][1].size()) {
          res = false;
        }
      }
      if (res) ans = min(ans, cur);
    }
    cout << ans;
    return 0;
  }
  if (k == 6) {
    int ans = INF;
    int cur = 0;
    for (int i1 = 1; i1 <= n; ++i1) {
      for (int i2 = 1; i2 <= n; ++i2) {
        cur = 0;
        bool res = true;
        if (v[1][i1].empty()) {
          res = false;
        }
        if (v[i1][i2].empty()) {
          res = false;
        }
        if (v[i2][1].empty()) {
          res = false;
        }
        for (int i = 0; i < v[1][i1].size(); ++i) {
          if (v[1][i1][i].second != 1 && v[1][i1][i].second != i1 &&
              v[1][i1][i].second != i2) {
            cur += v[1][i1][i].first;
            break;
          }
          if (1 + i == v[1][i1].size()) {
            res = false;
          }
        }
        for (int i = 0; i < v[i1][i2].size(); ++i) {
          if (v[i1][i2][i].second != 1 && v[i1][i2][i].second != i1 &&
              v[i1][i2][i].second != i2) {
            cur += v[i1][i2][i].first;
            break;
          }
          if (1 + i == v[i1][i2].size()) {
            res = false;
          }
        }
        for (int i = 0; i < v[i2][1].size(); ++i) {
          if (v[i2][1][i].second != 1 && v[i2][1][i].second != i1 &&
              v[i2][1][i].second != i2) {
            cur += v[i2][1][i].first;
            break;
          }
          if (1 + i == v[i2][1].size()) {
            res = false;
          }
        }
        if (res) ans = min(ans, cur);
      }
    }
    cout << ans;
    return 0;
  }
  if (k == 8) {
    int ans = INF;
    int cur = 0;
    for (int i1 = 1; i1 <= n; ++i1) {
      for (int i2 = 1; i2 <= n; ++i2) {
        for (int i3 = 1; i3 <= n; ++i3) {
          cur = 0;
          bool res = true;
          if (v[1][i1].empty()) {
            res = false;
          }
          if (v[i1][i2].empty()) {
            res = false;
          }
          if (v[i2][i3].empty()) {
            res = false;
          }
          if (v[i3][1].empty()) {
            res = false;
          }
          for (int i = 0; i < v[1][i1].size(); ++i) {
            if (v[1][i1][i].second != 1 && v[1][i1][i].second != i1 &&
                v[1][i1][i].second != i2 && v[1][i1][i].second != i3) {
              cur += v[1][i1][i].first;
              break;
            }
            if (1 + i == v[1][i1].size()) {
              res = false;
            }
          }
          for (int i = 0; i < v[i1][i2].size(); ++i) {
            if (v[i1][i2][i].second != 1 && v[i1][i2][i].second != i1 &&
                v[i1][i2][i].second != i2 && v[i1][i2][i].second != i3) {
              cur += v[i1][i2][i].first;
              break;
            }
            if (1 + i == v[i1][i2].size()) {
              res = false;
            }
          }
          for (int i = 0; i < v[i2][i3].size(); ++i) {
            if (v[i2][i3][i].second != 1 && v[i2][i3][i].second != i1 &&
                v[i2][i3][i].second != i2 && v[i2][i3][i].second != i3) {
              cur += v[i2][i3][i].first;
              break;
            }
            if (1 + i == v[i2][i3].size()) {
              res = false;
            }
          }
          for (int i = 0; i < v[i3][1].size(); ++i) {
            if (v[i3][1][i].second != 1 && v[i3][1][i].second != i1 &&
                v[i3][1][i].second != i2 && v[i3][1][i].second != i3) {
              cur += v[i3][1][i].first;
              break;
            }
            if (1 + i == v[i3][1].size()) {
              res = false;
            }
          }
          if (res) ans = min(ans, cur);
        }
      }
    }
    cout << ans;
    return 0;
  }
  if (k == 10) {
    int ans = INF;
    int cur = 0;
    for (int i1 = 1; i1 <= n; ++i1) {
      for (int i2 = 1; i2 <= n; ++i2) {
        for (int i3 = 1; i3 <= n; ++i3) {
          for (int i4 = 1; i4 <= n; ++i4) {
            cur = 0;
            bool res = true;
            if (v[1][i1].empty()) {
              res = false;
            }
            if (v[i1][i2].empty()) {
              res = false;
            }
            if (v[i2][i3].empty()) {
              res = false;
            }
            if (v[i3][i4].empty()) {
              res = false;
            }
            if (v[i4][1].empty()) {
              res = false;
            }
            for (int i = 0; i < v[1][i1].size(); ++i) {
              if (v[1][i1][i].second != 1 && v[1][i1][i].second != i1 &&
                  v[1][i1][i].second != i2 && v[1][i1][i].second != i3 &&
                  v[1][i1][i].second != i4) {
                cur += v[1][i1][i].first;
                break;
              }
              if (1 + i == v[1][i1].size()) {
                res = false;
              }
            }
            for (int i = 0; i < v[i1][i2].size(); ++i) {
              if (v[i1][i2][i].second != 1 && v[i1][i2][i].second != i1 &&
                  v[i1][i2][i].second != i2 && v[i1][i2][i].second != i3 &&
                  v[i1][i2][i].second != i4) {
                cur += v[i1][i2][i].first;
                break;
              }
              if (1 + i == v[i1][i2].size()) {
                res = false;
              }
            }
            for (int i = 0; i < v[i2][i3].size(); ++i) {
              if (v[i2][i3][i].second != 1 && v[i2][i3][i].second != i1 &&
                  v[i2][i3][i].second != i2 && v[i2][i3][i].second != i3 &&
                  v[i2][i3][i].second != i3) {
                cur += v[i2][i3][i].first;
                break;
              }
              if (1 + i == v[i2][i3].size()) {
                res = false;
              }
            }
            for (int i = 0; i < v[i3][i4].size(); ++i) {
              if (v[i3][i4][i].second != 1 && v[i3][i4][i].second != i1 &&
                  v[i3][i4][i].second != i2 && v[i3][i4][i].second != i3 &&
                  v[i3][i4][i].second != i4) {
                cur += v[i3][i4][i].first;
                break;
              }
              if (1 + i == v[i3][i4].size()) {
                res = false;
              }
            }
            for (int i = 0; i < v[i4][1].size(); ++i) {
              if (v[i4][1][i].second != 1 && v[i4][1][i].second != i1 &&
                  v[i4][1][i].second != i2 && v[i4][1][i].second != i3 &&
                  v[i4][1][i].second != i4) {
                cur += v[i4][1][i].first;
                break;
              }
              if (1 + i == v[i4][1].size()) {
                res = false;
              }
            }
            if (res) ans = min(ans, cur);
          }
        }
      }
    }
    cout << ans;
    return 0;
  }
}
