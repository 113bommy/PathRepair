#include <bits/stdc++.h>
const int MAX = 1e3 + 11;
using namespace std;
const double eps = 0.000001;
const int N = 8;
vector<int64_t> A[N];
static inline int64_t dot(const vector<int64_t> &a, const vector<int64_t> &b) {
  int64_t res = 0;
  for (int i = 0; i < (int((a).size())); ++i) {
    res += a[i] * b[i];
  }
  return res;
}
static inline int64_t sqr(const int64_t x) { return x * x; }
static inline int64_t dis(const vector<int64_t> &a, const vector<int64_t> &b) {
  int64_t res = 0;
  for (int i = 0; i < (int((a).size())); ++i) {
    res += sqr(a[i] - b[i]);
  }
  return res;
}
static inline vector<int64_t> dif(const vector<int64_t> &a,
                                  const vector<int64_t> &b) {
  vector<int64_t> res;
  for (int i = 0; i < (int((a).size())); ++i) res.push_back(a[i] - b[i]);
  return res;
}
static int can(const vector<vector<int64_t>> &cub) {
  int64_t d = 1e17;
  for (int i = 0; i < (N); ++i) {
    for (int j = 0; j < (N); ++j) {
      if (i != j) {
        d = min(d, dis(cub[i], cub[j]));
      }
    }
  }
  if (d == 0) {
    return 0;
  }
  vector<int64_t> t[N];
  for (int i = 0; i < (N); ++i) {
    int cnt = 0;
    for (int j = 0; j < (N); ++j) {
      if (i != j) {
        if (dis(cub[i], cub[j]) == d) {
          cnt++;
          t[i].push_back(j);
        }
      }
    }
    if (cnt != 3) {
      return 0;
    }
  }
  for (int i = 0; i < (N); ++i) {
    auto x = dif(cub[i], cub[t[i][0]]);
    auto y = dif(cub[i], cub[t[i][1]]);
    auto z = dif(cub[i], cub[t[i][2]]);
    if (dot(x, y) || dot(x, z) || dot(y, z)) {
      return 0;
    }
  }
  return 1;
}
int main() {
  for (int i = 0; i < (N); ++i) {
    for (int j = 0; j < (3); ++j) {
      int(x);
      scanf("%d", &x);
      A[i].push_back(x);
    }
    sort(A[i].begin(), A[i].end());
  }
  int64_t all = pow(6, 7);
  for (int i = 0; i < (all); ++i) {
    int64_t x = i;
    vector<vector<int64_t>> res(A, A + N);
    for (int j = 0; j < (7); ++j) {
      for (int p = 0; p < (x % 6); ++p) {
        next_permutation(res[j].begin(), res[j].end());
      }
      x /= 6;
    }
    if (!can(res)) continue;
    cout << "YES\n";
    for (int x = 0; x < (int((res).size())); ++x) {
      for (int y = 0; y < (int((res[x]).size())); ++y) {
        cout << res[x][y] << " ";
      }
      cout << "\n";
    }
    return 0;
  }
  cout << "NO";
  return 0;
}
