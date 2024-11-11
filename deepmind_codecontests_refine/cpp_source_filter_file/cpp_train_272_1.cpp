#include <bits/stdc++.h>
using namespace std;
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
template <class T>
ostream &operator<<(ostream &os, vector<T> V) {
  os << "[";
  for (auto vv : V) os << vv << ",";
  return os << "]";
}
struct Matrix {
  vector<vector<int>> data;
  int r, c;
  Matrix(int row, int col, bool identity = false) : r(row), c(col) {
    data.assign(row, vector<int>(col, 0));
    if (identity) {
      for (int i = 0; i < r; ++i) {
        data[i][i] = 1;
      }
    }
  }
  Matrix operator*(Matrix &other) {
    int m = r, n = c, p = other.c;
    Matrix res(m, p);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < p; ++j) {
        for (int k = 0; k < n; ++k) {
          res.data[i][j] += data[i][k] * other.data[k][j];
        }
      }
    }
    return res;
  }
};
vector<int> extendGcd(int a, int b) {
  if (b == 0) {
    return {a, 1, 0};
  } else {
    vector<int> tmp = extendGcd(b, a % b);
    return {tmp[0], tmp[2], tmp[1] - (a / b) * tmp[2]};
  }
}
Matrix matrix_power(Matrix base, long long exp) {
  int n = base.r;
  Matrix res(n, n, true);
  while (exp) {
    if (exp & 1) {
      res = res * base;
    }
    base = base * base;
    exp >>= 1;
  }
  return res;
}
int n, m, s;
vector<vector<int>> edges(100010);
int visited[100010];
int dp[100010][2];
int pre[100010][2];
bool hasCycle(int cur) {
  if (visited[cur] == -1) return true;
  if (visited[cur] == 1) return false;
  visited[cur] = -1;
  for (int i : edges[cur]) {
    if (hasCycle(i)) return true;
  }
  visited[cur] = 1;
  return false;
}
void dfs(int cur, int i, int from) {
  if (dp[cur][i]) return;
  dp[cur][i] = 1;
  pre[cur][i] = from;
  for (int next : edges[cur]) {
    dfs(next, i ^ 1, cur);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  int c;
  for (int i = 1; i <= n; ++i) {
    cin >> c;
    int node;
    for (int j = 0; j < c; ++j) {
      cin >> node;
      edges[i].push_back(node);
    }
  }
  cin >> s;
  bool has = hasCycle(s);
  dfs(s, 0, 0);
  for (int i = 1; i <= n; ++i) {
    if (edges[i].empty() && dp[i][1]) {
      cout << "Win" << endl;
      vector<int> path;
      int cur = i, odd = 1;
      while (cur != s) {
        path.push_back(cur);
        cur = pre[cur][odd];
        odd ^= 1;
      }
      path.push_back(s);
      for (int j = path.size() - 1; j >= 0; --j) {
        cout << path[j] << " \n"[j == 0];
      }
      return 0;
    }
  }
  if (has) {
    cout << "Draw";
  } else {
    cout << "Lose";
  }
  return 0;
}
