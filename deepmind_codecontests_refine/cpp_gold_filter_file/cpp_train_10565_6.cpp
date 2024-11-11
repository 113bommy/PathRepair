#include <bits/stdc++.h>
using namespace std;
const double INF = 1e30;
int main() {
  do {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  } while (false);
  int n, m;
  cin >> n >> m;
  auto input = [&](int len) {
    vector<pair<int, int> > vec(len);
    for (int i = 0; i < len; i++) {
      cin >> vec[i].first >> vec[i].second;
    }
    return vec;
  };
  auto sub = [&](pair<int, int> a, pair<int, int> b) {
    return pair<int, int>(a.first - b.first, a.second - b.second);
  };
  auto dot = [&](pair<int, int> a, pair<int, int> b) {
    return a.first * b.first + a.second * b.second;
  };
  auto crs = [&](pair<int, int> a, pair<int, int> b) {
    return a.first * b.second - a.second * b.first;
  };
  auto convex_hull = [&](vector<pair<int, int> > &vec) {
    sort(vec.begin(), vec.end(), [&](pair<int, int> a, pair<int, int> b) {
      return a.first == b.first ? a.second > b.second : a.first < b.first;
    });
    vector<pair<int, int> > res;
    for (auto p : vec) {
      while (res.size() >= 2 &&
             crs(sub(res.back(), p), sub(res[res.size() - 2], p)) >= 0) {
        res.pop_back();
      }
      res.push_back(p);
    }
    int limit = res.size();
    res.pop_back();
    reverse(vec.begin(), vec.end());
    for (auto p : vec) {
      while (res.size() > limit &&
             crs(sub(res.back(), p), sub(res[res.size() - 2], p)) >= 0) {
        res.pop_back();
      }
      res.push_back(p);
    }
    res.pop_back();
    return res;
  };
  auto solve = [&](vector<pair<int, int> > A, vector<pair<int, int> > B) {
    A = convex_hull(A);
    vector<pair<int, int> > edge;
    function<void(int, int)> init = [&](int l, int r) {
      edge.emplace_back(l, r);
      if (r - l + 1 <= 2) {
        return;
      }
      double mx = -INF;
      int pos = -1;
      for (int i = l + 1; i < r; i++) {
        double d = (double)dot(sub(A[i], A[l]), sub(A[i], A[r])) /
                   crs(sub(A[l], A[i]), sub(A[l], A[r]));
        if (d > mx) {
          tie(mx, pos) = make_tuple(d, i);
        }
      }
      init(l, pos);
      init(pos, r);
    };
    init(0, A.size() - 1);
    for (auto &it : edge) {
      int l = it.first, r = it.second;
      double mn = -INF, mx = INF;
      for (int i = 0; i < A.size() && mn < mx; i++) {
        if (i != l && i != r) {
          int a = dot(sub(A[i], A[l]), sub(A[i], A[r])),
              b = crs(sub(A[l], A[i]), sub(A[l], A[r]));
          if (b < 0) {
            mx = min(mx, (double)a / b);
          } else if (b > 0) {
            mn = max(mn, (double)a / b);
          }
        }
      }
      for (int i = 0; i < B.size() && mn < mx; i++) {
        int a = dot(sub(B[i], A[l]), sub(B[i], A[r])),
            b = crs(sub(A[l], B[i]), sub(A[l], A[r]));
        if (b > 0) {
          mx = min(mx, (double)a / b);
        } else if (b < 0) {
          mn = max(mn, (double)a / b);
        } else if (a <= 0) {
          mn = INF;
        }
      }
      if (mn < mx) {
        return true;
      }
    }
    return false;
  };
  auto A = input(n), B = input(m);
  if (n == 1 || m == 1 || solve(A, B) || solve(B, A)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
