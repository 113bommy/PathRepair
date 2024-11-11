#include <bits/stdc++.h>
using namespace std;
namespace std {
template <class S, class T>
struct hash<pair<S, T>> {
  size_t operator()(const pair<S, T> &p) const {
    return ((size_t)1e9 + 7) * hash<S>()(p.first) + hash<T>()(p.second);
  }
};
template <class T>
struct hash<vector<T>> {
  size_t operator()(const vector<T> &v) const {
    size_t h = 0;
    for (auto i : v) h = h * ((size_t)1e9 + 7) + hash<T>()(i) + 1;
    return h;
  }
};
}  // namespace std
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[ ";
  for (int i = 0; i < (int)v.size(); i++)
    os << v[i] << (i == v.size() - 1 ? " ]" : ", ");
  return os;
}
template <class T>
ostream &operator<<(ostream &os, const set<T> &v) {
  os << "{ ";
  for (const auto &i : v) os << i << ", ";
  return os << "}";
}
template <class T, class U>
ostream &operator<<(ostream &os, const map<T, U> &v) {
  os << "{";
  for (const auto &i : v) os << " " << i.first << ": " << i.second << ",";
  return os << "}";
}
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
void dbgprint(const string &fmt) { cerr << endl; }
template <class H, class... T>
void dbgprint(const string &fmt, const H &h, const T &...r) {
  cerr << fmt.substr(0, fmt.find(",")) << "= " << h << " ";
  dbgprint(fmt.substr(fmt.find(",") + 1), r...);
}
const int inf = (int)1e9;
const double INF = 1e12, EPS = 1e-9;
int dp[1 << 16][16], way[1 << 16][16];
vector<int> tsp(vector<vector<int>> d) {
  int n = d.size();
  for (int i = 0; i < (int)1 << n; i++)
    for (int j = 0; j < (int)n; j++) dp[i][j] = inf;
  for (int i = 0; i < (int)n; i++) dp[0][i] = 0;
  for (int i = 0; i < (int)1 << n; i++)
    for (int j = 0; j < (int)n; j++)
      if (dp[i][j] < inf)
        for (int k = 0; k < (int)n; k++)
          if (j != k && !(i & 1 << k)) {
            if (dp[i | 1 << k][k] <= dp[i][j] + d[j][k]) continue;
            dp[i | 1 << k][k] = dp[i][j] + d[j][k];
            way[i | 1 << k][k] = j;
          }
  int ans = inf, ansi, mask = (1 << n) - 1;
  for (int i = 0; i < (int)n; i++)
    if (ans > dp[mask][i]) ans = dp[mask][ansi = i];
  vector<int> res;
  for (int i = 0; i < (int)n; i++) {
    res.push_back(ansi);
    if (i == n - 1) break;
    int p = way[mask][ansi];
    mask ^= 1 << ansi;
    ansi = p;
  }
  reverse((res).begin(), (res).end());
  return res;
}
int dist(const vector<vector<int>> &v, int x, int y) {
  double res = 0;
  for (int j = 0; j < (int)5; j++) {
    double fac = pow(3.0, -j);
    for (int i = 0; i < (int)v[0].size(); i++)
      res += (v[x - j][i] - v[y][i]) * (v[x - j][i] - v[y][i]) * fac;
    for (int i = 0; i < (int)v[0].size(); i++)
      res += (v[x][i] - v[y + j][i]) * (v[x][i] - v[y + j][i]) * fac;
  }
  return (int)(res / 1000);
}
void filter(vector<vector<int>> &v, int y, int Y) {
  const int X = 3;
  int w = v[0].size();
  vector<vector<int>> u(Y - y, vector<int>(w));
  for (int i = y; i < Y; i++)
    for (int j = 0; j < (int)w; j++) {
      int s = 0, c = 0;
      for (int k = i - X; k <= i + X; k++)
        if (y <= k && k < Y)
          for (int l = j - X; l <= j + X; l++)
            if (0 <= l && l < w) {
              s += v[k][l], c++;
            }
      u[i - y][j] = s / c;
    }
  for (int i = 0; i < (int)Y - y; i++)
    for (int j = 0; j < (int)w; j++) v[i + y][j] = u[i][j];
}
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int q;
  cin >> q;
  vector<int> res;
  for (int it = 0; it < (int)q; it++) {
    int h, w, n;
    cin >> h >> w >> n;
    vector<vector<int>> v(h, vector<int>(w));
    for (int i = 0; i < (int)h; i++)
      for (int j = 0; j < (int)w; j++) cin >> v[i][j];
    for (int i = 0; i < (int)n; i++) filter(v, h / n * i, h / n * (i + 1));
    vector<vector<int>> ds(n, vector<int>(n));
    for (int i = 0; i < (int)n; i++)
      for (int j = 0; j < (int)n; j++)
        if (i != j) {
          int x = (h / n) * (i + 1) - 1;
          int y = (h / n) * j;
          ds[i][j] = dist(v, x, y);
        }
    vector<int> res = tsp(ds);
    vector<int> inv(n);
    for (int i = 0; i < (int)n; i++) inv[res[i]] = i + 1;
    for (int i = 0; i < (int)n; i++)
      printf("%d%c", inv[i], i == n - 1 ? '\n' : ' ');
  }
  return 0;
}
