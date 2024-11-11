#include <bits/stdc++.h>
using namespace std;
template <typename T>
using V = vector<T>;
int gcdex(int a, int b, int &x, int &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  int x1, y1;
  int g = gcdex(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return g;
}
inline int ADD_MOD(int a, int b) { return (a + b) % 1000000007; }
inline int MUL_MOD(int a, int b) { return (int64_t(a) * b) % 1000000007; }
inline int SUB_MOD(int a, int b) { return a >= b ? a - b : a + 1000000007 - b; }
int DIV_MOD(int a, int b) {
  int x, y;
  gcdex(b, 1000000007, x, y);
  int b1 = (x % 1000000007 + 1000000007) % 1000000007;
  return MUL_MOD(a, b1);
}
const long double EPS = 1. / 1e9;
inline bool EPS_EQUAL(long double a, long double b) {
  return abs(a - b) <= EPS;
}
inline bool EPS_LESS(long double a, long double b) { return b - a > EPS; }
inline bool EPS_GREATER(long double a, long double b) { return a - b > EPS; }
const int INF = 1e9;
const int64_t INF64 = 2e18;
struct Dp {
  int first;
  int parentFirst;
  int last;
  int parentLast;
};
int cw(int n, int a, int b) {
  if (b >= a) return b - a;
  return b - a + n;
}
int ccw(int n, int a, int b) {
  if (a >= b) return a - b;
  return a - b + n;
}
int dist(int n, int a, int b) { return min(cw(n, a, b), ccw(n, a, b)); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(15);
  int n, s;
  cin >> n >> s;
  --s;
  V<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  V<V<int>> groups;
  groups.push_back({});
  groups.back().push_back(a[0].second);
  int cur = a[0].first;
  for (int i = 1; i < n; ++i) {
    if (a[i].first != cur) {
      groups.push_back({});
      cur = a[i].first;
    }
    groups.back().push_back(a[i].second);
  }
  V<Dp> dp(n);
  for (int i = 0; i < groups.size(); ++i) {
    auto &g = groups[i];
    int gSize = g.size();
    if (i > 0) {
      for (auto &j : g) {
        int minD = INF;
        int minPrev = -1;
        for (auto &prev : groups[i - 1]) {
          int d = dist(n, j, prev) + dp[prev].last;
          if (d < minD) {
            minD = d;
            minPrev = prev;
          }
        }
        dp[j].first = minD;
        dp[j].parentFirst = minPrev;
      }
    } else {
      for (auto &j : g) {
        dp[j].first = dist(n, j, s);
        dp[j].parentFirst = -1;
      }
    }
    if (gSize > 1) {
      for (int j = 0; j < gSize; ++j) {
        int minD = INF;
        int minPrev = -1;
        int cur = g[j];
        int cwJ = g[(j + 1) % gSize];
        int ccwJ = g[j > 0 ? j - 1 : gSize - 1];
        for (auto &first : g) {
          if (first != cur) {
            int d = min(ccw(n, first, cwJ) + cw(n, cwJ, cur),
                        cw(n, first, ccwJ) + ccw(n, ccwJ, cur)) +
                    dp[first].first;
            if (d < minD) {
              minD = d;
              minPrev = first;
            }
          }
        }
        dp[cur].last = minD;
        dp[cur].parentLast = minPrev;
      }
    } else {
      dp[g[0]].last = dp[g[0]].first;
      dp[g[0]].parentLast = g[0];
    }
  }
  int minRes = INF;
  int last = -1;
  for (auto &i : groups.back()) {
    if (dp[i].last < minRes) {
      minRes = dp[i].last;
      last = i;
    }
  }
  cout << minRes << endl;
  V<int> path;
  for (int i = groups.size() - 1; i >= 0; --i) {
    auto &g = groups[i];
    int gSize = g.size();
    int first = dp[last].parentLast;
    if (first != last) {
      int iLast = lower_bound(g.begin(), g.end(), last) - g.begin();
      int cwLast = g[(iLast + 1) % gSize];
      int ccwLast = g[iLast > 0 ? iLast - 1 : gSize - 1];
      int cwD = ccw(n, first, cwLast) + cw(n, cwLast, last);
      int ccwD = cw(n, first, ccwLast) + ccw(n, ccwLast, last);
      if (cwD < ccwD) {
        int prev = last;
        for (int j = 1; j < gSize; ++j) {
          int cur = iLast - j;
          if (cur < 0) cur += gSize;
          if (g[cur] != first || j == gSize - 1) {
            path.push_back(ccw(n, prev, g[cur]));
            prev = g[cur];
          }
        }
        if (prev != first) {
          path.push_back(-cw(n, prev, last));
        }
      } else {
        int prev = last;
        for (int j = 1; j < gSize; ++j) {
          int cur = (iLast + j) % gSize;
          if (g[cur] != first || j == gSize - 1) {
            path.push_back(-cw(n, prev, g[cur]));
            prev = g[cur];
          }
        }
        if (prev != first) {
          path.push_back(ccw(n, prev, last));
        }
      }
    }
    last = dp[first].parentFirst;
    int lastPos = last < 0 ? s : last;
    int cwD = cw(n, first, lastPos);
    int ccwD = ccw(n, first, lastPos);
    if (cwD < ccwD) {
      path.push_back(-cwD);
    } else {
      path.push_back(ccwD);
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    cout << (path[i] >= 0 ? "+" : "") << path[i] << endl;
  }
  return 0;
}
