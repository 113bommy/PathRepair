#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
void sync_stdio() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
}
struct Sync_stdio {
  Sync_stdio() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
  }
} _sync_stdio;
int less1(pair<int, int> x, pair<int, int> y) {
  int d1 = min(x.first, y.first);
  int d2 = min(x.second, y.second);
  x.first -= d1, y.first -= d1;
  x.second -= d2, y.second -= d2;
  if (y.first == 0 && y.second == 0) {
    return 0;
  }
  if (y.first > 0 && y.second > 0) {
    return 1;
  }
  if (y.first > 0) {
    return x.second < log(3.0) / log(2.0) * y.first;
  }
  if (y.second > 0) {
    return x.first < log(3.0) / log(2.0) * y.second;
  }
  return 0;
}
void print(int x, int y) {
  long long res = 1;
  for (int i = (0); i < (x); ++i) {
    res *= 2;
    res %= MOD;
  }
  for (int i = (0); i < (y); ++i) {
    res *= 3;
    res %= MOD;
  }
  cout << res << "\n";
}
pair<int, int> solve(const vector<string> &v, int n) {
  vector<vector<vector<int>>> vert(4, vector<vector<int>>(n, vector<int>(n)));
  vector<vector<vector<int>>> hor(4, vector<vector<int>>(n, vector<int>(n)));
  vector<vector<vector<int>>> a(4, vector<vector<int>>(n, vector<int>(n)));
  vector<vector<int>> vertz(n);
  vector<vector<int>> horz(n);
  for (int i = (0); i < (n); ++i) {
    vertz[i].push_back(-1);
  }
  for (int i = (0); i < (n); ++i) {
    horz[i].push_back(-1);
  }
  for (int k = (0); k < (4); ++k) {
    for (int i = (0); i < (n - 1); ++i) {
      for (int j = (0); j < (n - 1); ++j) {
        a[v[i][j] - '0'][i + 1][j + 1] = 1;
      }
    }
  }
  for (int i = (0); i < (n - 1); ++i) {
    for (int j = (0); j < (n - 1); ++j) {
      if (v[i][j] == '0') {
        vertz[j].push_back(i);
        horz[i].push_back(j);
      }
    }
  }
  for (int i = (0); i < (n); ++i) {
    vertz[i].push_back(n - 1);
  }
  for (int i = (0); i < (n); ++i) {
    horz[i].push_back(n - 1);
  }
  vert = hor = a;
  for (int k = (0); k < (4); ++k) {
    for (int i = (0); i < (n); ++i) {
      for (int j = (1); j < (n); ++j) {
        hor[k][i][j] += hor[k][i][j - 1];
      }
    }
    for (int i = (1); i < (n); ++i) {
      for (int j = (0); j < (n); ++j) {
        vert[k][i][j] += vert[k][i - 1][j];
      }
    }
  }
  pair<int, int> res = {0, 0};
  for (int i = (0); i < (n - 1); ++i) {
    for (int j = (0); j < (n - 1); ++j) {
      if (v[i][j] == '0') {
        continue;
      }
      auto x1 = upper_bound(vertz[j].begin(), vertz[j].end(), i) - 1;
      auto x2 = lower_bound(vertz[j].begin(), vertz[j].end(), i);
      auto y1 = upper_bound(horz[i].begin(), horz[i].end(), j) - 1;
      auto y2 = lower_bound(horz[i].begin(), horz[i].end(), j);
      int t = min(min(i - *x1, *x2 - i), min(j - *y1, *y2 - j)) - 1;
      t = max(t, 0);
      vector<int> ans(4);
      for (int k = (0); k < (4); ++k) {
        ans[k] += hor[k][i + 1][j + t + 1] - hor[k][i + 1][j - t];
        ans[k] += vert[k][i + t + 1][j + 1] - vert[k][i - t][j + 1];
      }
      --ans[v[i][j] - '0'];
      if (less1(res, {ans[2], ans[3]})) {
        res = {ans[2], ans[3]};
      }
    }
  }
  return res;
}
int main() {
  int n;
  cin >> n;
  vector<string> v(n);
  for (int __i = 0; __i < (n); ++__i) cin >> v[__i];
  ;
  int flag = 0;
  for (int i = (0); i < (n); ++i) {
    for (int j = (0); j < (n); ++j) {
      if (v[i][j] != '0') {
        flag = 1;
      }
    }
  }
  if (!flag) {
    cout << 0;
    exit(0);
  }
  pair<int, int> res = solve(v, n + 1);
  vector<string> v2(2 * n, string(2 * n, '0'));
  for (int i = (-2 * n); i < (2 * n); ++i) {
    for (int j = (-2 * n); j < (2 * n); ++j) {
      if (0 <= i + j && i + j < n && 0 <= i - j && i - j < n) {
        v2[i][j + n] = v[i + j][i - j];
      }
    }
  }
  pair<int, int> res2 = solve(v2, 2 * n + 1);
  if (less1(res, res2)) {
    res = res2;
  }
  v2.assign(2 * n, string(2 * n, '0'));
  for (int i = (-2 * n - 1); i < (2 * n + 1); ++i) {
    for (int j = (-2 * n - 1); j < (2 * n + 1); ++j) {
      if (0 <= i + j + 1 && i + j + 1 < n && 0 <= i - j && i - j < n) {
        v2[i][j + n] = v[i + j + 1][i - j];
      }
    }
  }
  res2 = solve(v2, 2 * n + 1);
  if (less1(res, res2)) {
    res = res2;
  }
  print(res.first, res.second);
  return 0;
}
