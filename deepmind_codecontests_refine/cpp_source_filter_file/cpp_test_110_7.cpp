#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:512000000")
using namespace std;
using li = long long;
using ld = long double;
void solve(bool);
void precalc();
clock_t start;
int main() {
  start = clock();
  int t = 1;
  cout.sync_with_stdio(0);
  cin.tie(0);
  cout.precision(20);
  cout << fixed;
  precalc();
  int test_num = 1;
  while (t--) {
    solve(true);
  }
  cout.flush();
  return 0;
}
template <typename T>
T binpow(T q, T w, T mod) {
  if (!w) return 1 % mod;
  if (w & 1) return q * 1LL * binpow(q, w - 1, mod) % mod;
  return binpow(q * 1LL * q % mod, w / 2, mod);
}
template <typename T>
T gcd(T q, T w) {
  while (w) {
    q %= w;
    swap(q, w);
  }
  return q;
}
template <typename T>
T lcm(T q, T w) {
  return q / gcd(q, w) * w;
}
template <typename T>
void make_unique(vector<T>& vec) {
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
}
template <typename T>
void relax_min(T& cur, T val) {
  cur = min(cur, val);
}
template <typename T>
void relax_max(T& cur, T val) {
  cur = max(cur, val);
}
mt19937 rng(
    (unsigned long long)chrono::steady_clock::now().time_since_epoch().count());
void precalc() {}
struct Point {
  int x, y;
  Point(int x = 0, int y = 0) : x(x), y(y) {}
  Point rotate() const { return Point(y, -x); }
  Point reflect() const { return Point(-x, y); }
  void scan() { cin >> x >> y; }
  bool operator<(const Point& ot) const {
    return make_pair(x, y) < make_pair(ot.x, ot.y);
  }
};
void solve(__attribute__((unused)) bool read) {
  int n;
  cin >> n;
  vector<vector<Point>> points(3);
  for (int i = 0; i < n; ++i) {
    Point cur;
    cur.scan();
    int type;
    cin >> type;
    points[type - 1].push_back(cur);
  }
  const int INF = (int)1e9 + 100;
  int ans = 0;
  for (int reflect = 0; reflect < 2; ++reflect) {
    for (int rotate = 0; rotate < 4; ++rotate) {
      auto points_by_y = points;
      for (int i = 0; i < 3; ++i) {
        sort(points[i].begin(), points[i].end());
        sort(points_by_y[i].begin(), points_by_y[i].end(),
             [&](const Point& q, const Point& w) { return q.y < w.y; });
      }
      vector<int> perm(3);
      iota(perm.begin(), perm.end(), 0);
      do {
        int last = perm[2], first = perm[0], mid = perm[1];
        auto border_by_x = [&](int cnt, int border) {
          int pos = -1;
          for (int i = n / 3 - 1; i >= 0; --i) {
            if (points[mid][i].x < border) {
              pos = i - cnt + 1;
              break;
            }
          }
          if (pos < 0) {
            return false;
          }
          border = points[mid][pos].x;
          return points[first][cnt - 1].x < border;
        };
        auto is_good = [&](int cnt) {
          int border = points[last][n / 3 - cnt].x;
          if (border_by_x(cnt, border)) {
            return true;
          }
          int cnt_found = 0;
          int first_y = -INF;
          for (auto pt : points_by_y[first]) {
            if (pt.x >= border) {
              continue;
            }
            ++cnt_found;
            first_y = pt.y;
            if (cnt_found == cnt) {
              break;
            }
          }
          if (cnt_found < cnt) {
            return false;
          }
          cnt_found = 0;
          int mid_y = INF;
          for (int i = n / 3 - 1; i >= 0; --i) {
            auto pt = points[mid][i];
            if (pt.x >= border) {
              continue;
            }
            ++cnt_found;
            mid_y = pt.y;
            if (cnt_found == cnt) {
              break;
            }
          }
          if (cnt_found < cnt) {
            return false;
          }
          return first_y < mid_y;
        };
        int L = 0, R = n / 3 + 1;
        while (L + 1 < R) {
          int M = (L + R) / 2;
          if (is_good(M)) {
            L = M;
          } else {
            R = M;
          }
        }
        relax_max(ans, L);
      } while (next_permutation(perm.begin(), perm.end()));
      for (auto& vec : points) {
        for (auto& pt : vec) {
          pt = pt.rotate();
        }
      }
    }
    for (auto& vec : points) {
      for (auto& pt : vec) {
        pt = pt.reflect();
      }
    }
  }
  cout << ans * 3 << "\n";
}
