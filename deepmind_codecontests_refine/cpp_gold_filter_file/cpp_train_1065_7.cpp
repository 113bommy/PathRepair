#include <bits/stdc++.h>
using namespace std;
vector<string> split(const string& s, char c) {
  vector<string> v;
  stringstream second(s);
  string x;
  while (getline(second, x, c)) v.emplace_back(x);
  return move(v);
}
template <typename T, typename... Args>
inline string arrStr(T arr, int n) {
  stringstream s;
  s << "[";
  for (int i = 0; i < n - 1; i++) s << arr[i] << ",";
  s << arr[n - 1] << "]";
  return s.str();
}
inline void __evars_begin(int line) { cerr << "#" << line << ": "; }
template <typename T>
inline void __evars_out_var(vector<T> val) {
  cerr << arrStr(val, val.size());
}
template <typename T>
inline void __evars_out_var(T* val) {
  cerr << arrStr(val, 10);
}
template <typename T>
inline void __evars_out_var(T val) {
  cerr << val;
}
inline void __evars(vector<string>::iterator it) { cerr << '\n'; }
template <typename T, typename... Args>
inline void __evars(vector<string>::iterator it, T a, Args... args) {
  cerr << it->substr((*it)[0] == ' ', it->length()) << "=";
  __evars_out_var(a);
  cerr << "; ";
  __evars(++it, args...);
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int dx[8] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
vector<long long> vis(500010, 0), val(500010, 0), dis(500010), fin(500010, 0),
    arr(500010, 0);
vector<int> adj[500010];
int myrandom(int i) { return std::rand() % i; }
const int MAX = 100010;
bool check(vector<vector<char>>& mat) {
  int n = (int)mat.size();
  int m = (int)mat[0].size();
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == 'S') cnt++;
    }
    if (cnt == 0) return false;
  }
  for (int i = 0; i < m; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (mat[j][i] == 'S') {
        cnt++;
      }
    }
    if (cnt == 0) {
      return false;
    }
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<string> v(n);
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n))) {
    cin >> v[i];
  }
  vector<vector<char>> mat(n, vector<char>(m));
  vector<int> rowCnt(n), colCnt(m);
  for (int i = 0; i < n; i++) {
    int j = 0;
    int cnt = 0;
    while (j < m) {
      if (v[i][j] == '#') cnt++;
      while (j < m && v[i][j] == '#') j++;
      while (j < m && v[i][j] == '.') j++;
    }
    rowCnt[i] = cnt;
  }
  for (int i = 0; i < m; i++) {
    int j = 0;
    int cnt = 0;
    while (j < n) {
      if (v[j][i] == '#') cnt++;
      while (j < n && v[j][i] == '#') j++;
      while (j < n && v[j][i] == '.') j++;
    }
    colCnt[i] = cnt;
  }
  for (int i = 0; i < n; i++) {
    if (rowCnt[i] == 0) {
      for (int j = 0; j < m; j++) {
        if (colCnt[j] == 0) {
          mat[i][j] = 'S';
        }
      }
    } else if (rowCnt[i] == 1) {
      for (int j = 0; j < m; j++) {
        if (v[i][j] == '#') {
          if (colCnt[j] <= 1) {
            mat[i][j] = 'S';
          }
        }
      }
    }
  }
  bool ok = check(mat);
  if (!ok) {
    cout << -1 << '\n';
    return 0;
  }
  int tot = 0;
  vector<vector<int>> vis(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vis[i][j] == 0 && v[i][j] == '#') {
        tot++;
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;
        while (!q.empty()) {
          auto vs = q.front();
          q.pop();
          int r = vs.first;
          int c = vs.second;
          for (int i = 0; i < 4; i++) {
            int x = r + dx[i];
            int y = c + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == 0 &&
                v[x][y] == '#') {
              q.push({x, y});
              vis[x][y] = 1;
            }
          }
        }
      }
    }
  }
  cout << tot << '\n';
}
