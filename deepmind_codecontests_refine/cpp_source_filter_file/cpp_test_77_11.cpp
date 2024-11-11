#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
template <typename T>
class Reader {
 public:
  T readPrimitive() {
    T primitive;
    cin >> primitive;
    return primitive;
  }
  vector<T> readVector(int n) {
    vector<T> vec;
    vec.resize(n);
    for (int i = 0; i < n; i++) cin >> vec[i];
    return vec;
  }
  vector<pair<T, T>> readVectorPair(int n) {
    vector<pair<T, T>> vec;
    vec.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> vec[i].first >> vec[i].second;
    }
    return vec;
  }
  vector<vector<T>> readVV(int n, int m) {
    vector<vector<T>> vec;
    vec.resize(n, vector<T>(m));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) cin >> vec[i][j];
    return vec;
  }
};
class Display {
 public:
  void trueString() { cout << "YES\n"; }
  void falseString() { cout << "NO\n"; }
  void evaluateCondition(bool ff) { ff == true ? trueString() : falseString(); }
};
class Solver {
  Reader<int> rr;
  Display dd;
  int n, m;
  vector<vector<int>> grid;
  vector<vector<bool>> visited;
  vector<vector<int>> fill;

 public:
  Solver() {
    cin >> n >> m;
    grid = rr.readVV(n, m);
    visited.resize(n, vector<bool>(m, 0));
    fill.resize(n, vector<int>(m, -1));
  }

 public:
  void solve() {
    vector<int> res(0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (visited[i][j] == 1) continue;
        res.push_back(dfs(i, j));
      }
    }
    sort(res.begin(), res.end(), greater<int>());
    for (auto rr : res) cout << rr << " ";
    cout << "\n";
  }
  int dfs(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m) return 0;
    if (visited[i][j] == 1) return 0;
    visited[i][j] = 1;
    int mask = grid[i][j];
    int res = 0;
    for (int cnt = 0; cnt < 4; cnt++) {
      if (mask % 2 == 0) {
        pii dir = getDirection(cnt);
        res += dfs(i + dir.first, j + dir.second);
      }
      mask >>= 1;
    }
    return fill[i][j] = res + 1;
  }
  pii getDirection(int maskPos) {
    if (maskPos == 0) {
      return {0, -1};
    } else if (maskPos == 1) {
      return {1, 0};
    } else if (maskPos == 2) {
      return {0, 1};
    } else if (maskPos == 3) {
      return {-1, 0};
    }
    return {0, 0};
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    Solver solver;
    solver.solve();
  }
  return 0;
}
