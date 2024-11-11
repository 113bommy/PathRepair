#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
const int N = 5e5 + 5, M = 1000000007, INF = 0x3f3f3f3f;
const ll LNF = 0x3f3f3f3f3f3f3f3f;
void Main();
void debug() { cerr << endl; }
template <typename T, typename... Ts>
void debug(T x, Ts... y) {
  cerr << "\033[31m" << x << "\033[0m";
  if (sizeof...(y) > 0) cerr << ' ';
  debug(y...);
}
template <typename T>
void debug(const T& a, int l, int r, char c) {
  for (int i = l; i <= r; ++i)
    cerr << "\033[31m" << a[i] << "\033[0m" << (i == r ? '\n' : c);
}
template <typename T>
void debug(vector<T> a) {
  for (int i = 0; i < (int)a.size(); ++i)
    cout << "\033[31m" << a[i] << "\033[0m"
         << " \n"[i == (int)a.size() - 1];
}
void print() { cout << '\n'; }
template <typename T, typename... Ts>
void print(T x, Ts... y) {
  cout << x;
  if (sizeof...(y) > 0) cout << ' ';
  print(y...);
}
template <typename T>
void print(const T& a, int l, int r, char c) {
  for (int i = l; i <= r; ++i) cout << a[i] << (i == r ? '\n' : c);
}
template <typename T>
void print(vector<T> a) {
  for (int i = 0; i < (int)a.size(); ++i)
    cout << a[i] << " \n"[i == (int)a.size() - 1];
}
void input() {}
template <typename T, typename... Ts>
void input(T& x, Ts&... y) {
  cin >> x;
  input(y...);
}
template <typename T>
void input(T* a, int l, int r) {
  for (int i = l; i <= r; ++i) cin >> a[i];
}
template <typename T>
void input(vector<T>& a, int l, int r) {
  for (int i = l; i <= r; ++i) cin >> a[i];
}
template <typename T>
void input(vector<T>& a) {
  for (auto&& x : a) input(x);
}
template <typename T>
void Max(T& a, T b) {
  if (a < b) a = b;
}
template <typename T>
void Min(T& a, T b) {
  if (a > b) a = b;
}
template <typename T>
void Add(T& a, T b) {
  a += b;
  if (a > M) a -= M;
  if (a < 0) a += M;
}
template <typename T>
void Mul(T& a, T b) {
  a = a * b % M;
}
template <typename T>
T Mod(T a) {
  return (a % M + M) % M;
}
ll qpow(ll a, ll b) {
  ll ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % M;
    a = a * a % M, b >>= 1;
  }
  return ret;
}
ll pinv(ll x, ll mod = M) { return qpow(x, mod - 2); }
template <typename... Args>
string sformat(const string& format, Args... args) {
  size_t size = snprintf(nullptr, 0, format.c_str(), args...) + 1;
  unique_ptr<char[]> buf(new char[size]);
  snprintf(buf.get(), size, format.c_str(), args...);
  return string(buf.get(), buf.get() + size - 1);
}
int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  Main();
}
char a[105][105];
int calc(int x, int y) {
  int ret = 0;
  ret += a[x][y] - '0' + a[x + 1][y] - '0' + a[x][y + 1] - '0' +
         a[x + 1][y + 1] - '0';
  return ret;
}
int d[4][2] = {0, 0, 0, 1, 1, 0, 1, 1};
int d2[4][2] = {0, 0, 0, -1, -1, 0, -1, -1};
void Main() {
  int T;
  input(T);
  while (T--) {
    int n, m;
    input(n, m);
    for (int i = 1; i <= n; ++i) cin >> (a[i] + 1);
    vector<vector<pii>> ans;
    for (int i = 1; i <= n - 1; ++i)
      for (int j = 1; j <= m - 1; ++j) {
        int cnt = calc(i, j);
        if (cnt == 0) {
          continue;
        }
        if (cnt == 1) {
          int x = i, y = j;
          vector<pii> z;
          for (int k = 0; k < 4; ++k) {
            int xx = i + d[k][0];
            int yy = j + d[k][1];
            if (a[xx][yy] == '1') {
              x = xx;
              y = yy;
            } else {
              z.push_back({xx, yy});
            }
            a[xx][yy] = '0';
          }
          ans.push_back({});
          ans.back().push_back({x, y});
          ans.back().push_back({z[0].first, z[0].second});
          ans.back().push_back({z[1].first, z[1].second});
          ans.push_back({});
          ans.back().push_back({x, y});
          ans.back().push_back({z[0].first, z[0].second});
          ans.back().push_back({z[2].first, z[2].second});
          ans.push_back({});
          ans.back().push_back({x, y});
          ans.back().push_back({z[1].first, z[1].second});
          ans.back().push_back({z[2].first, z[2].second});
        } else if (cnt == 2) {
          vector<pii> z, o;
          for (int k = 0; k < 4; ++k) {
            int xx = i + d[k][0];
            int yy = j + d[k][1];
            if (a[xx][yy] == '1') {
              o.push_back({xx, yy});
            } else {
              z.push_back({xx, yy});
            }
            a[xx][yy] = '0';
          }
          ans.push_back({});
          ans.back().push_back({o[0].first, o[0].second});
          ans.back().push_back({z[0].first, z[0].second});
          ans.back().push_back({z[1].first, z[1].second});
          ans.push_back({});
          ans.back().push_back({o[1].first, o[1].second});
          ans.back().push_back({z[0].first, z[0].second});
          ans.back().push_back({z[1].first, z[1].second});
        } else if (cnt == 3) {
          ans.push_back({});
          for (int k = 0; k < 4; ++k) {
            int x = i + d[k][0];
            int y = j + d[k][1];
            if (a[x][y] == '1') {
              ans.back().push_back({x, y});
            }
            a[x][y] = '0';
          }
        } else {
          ans.push_back({});
          ans.back().push_back({i, j});
          ans.back().push_back({i + 1, j});
          ans.back().push_back({i, j + 1});
          a[i][j] = a[i + 1][j] = a[i][j + 1] = '0';
        }
      }
    for (int i = 1; i <= n - 1; ++i)
      for (int j = 1; j <= m - 1; ++j) {
        int cnt = calc(i, j);
        if (cnt == 0) {
          continue;
        }
        if (cnt == 1) {
          int x = i, y = j;
          vector<pii> z;
          for (int k = 0; k < 4; ++k) {
            int xx = i + d[k][0];
            int yy = j + d[k][1];
            if (a[xx][yy] == '1') {
              x = xx;
              y = yy;
            } else {
              z.push_back({xx, yy});
            }
            a[xx][yy] = '0';
          }
          ans.push_back({});
          ans.back().push_back({x, y});
          ans.back().push_back({z[0].first, z[0].second});
          ans.back().push_back({z[1].first, z[1].second});
          ans.push_back({});
          ans.back().push_back({x, y});
          ans.back().push_back({z[0].first, z[0].second});
          ans.back().push_back({z[2].first, z[2].second});
          ans.push_back({});
          ans.back().push_back({x, y});
          ans.back().push_back({z[1].first, z[1].second});
          ans.back().push_back({z[2].first, z[2].second});
        } else if (cnt == 2) {
          vector<pii> z, o;
          for (int k = 0; k < 4; ++k) {
            int xx = i + d[k][0];
            int yy = j + d[k][1];
            if (a[xx][yy] == '1') {
              o.push_back({xx, yy});
            } else {
              z.push_back({xx, yy});
            }
            a[xx][yy] = '0';
          }
          ans.push_back({});
          ans.back().push_back({o[0].first, o[0].second});
          ans.back().push_back({z[0].first, z[0].second});
          ans.back().push_back({z[1].first, z[1].second});
          ans.push_back({});
          ans.back().push_back({o[1].first, o[1].second});
          ans.back().push_back({z[0].first, z[0].second});
          ans.back().push_back({z[1].first, z[1].second});
        } else if (cnt == 3) {
          ans.push_back({});
          for (int k = 0; k < 4; ++k) {
            int x = i + d[k][0];
            int y = j + d[k][1];
            if (a[x][y] == '1') {
              ans.back().push_back({x, y});
            }
            a[x][y] = '0';
          }
        } else {
          ans.push_back({});
          ans.back().push_back({i, j});
          ans.back().push_back({i + 1, j});
          ans.back().push_back({i, j + 1});
        }
      }
    print(ans.size());
    for (auto&& v : ans) {
      for (pii x : v) cout << x.first << ' ' << x.second << ' ';
      cout << '\n';
    }
  }
}
