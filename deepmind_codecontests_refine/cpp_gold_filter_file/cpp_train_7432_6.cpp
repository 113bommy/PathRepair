#include <bits/stdc++.h>
using namespace std;
const int dr[] = {0, -1, 0, 1, -1, 1, 1, -1};
const int dc[] = {1, 0, -1, 0, 1, 1, -1, -1};
const double eps = 1e-9;
template <class T>
void print(T const &x) {
  ostringstream os;
  os << x;
  cout << os.str() << endl;
}
template <class T>
void print(vector<T> const &v) {
  ostringstream os;
  for (int i = 0; i < v.size(); ++i) {
    if (i) os << ' ';
    os << v[i];
  }
  cout << os.str() << endl;
}
template <class T>
void print(vector<vector<T> > const &v) {
  ostringstream os;
  for (int i = 0; i < v.size(); ++i) {
    for (int j = 0; j < v[i].size(); ++j) {
      if (j) os << ' ';
      os << v[i][j];
    }
    os << endl;
  }
  cout << os.str() << endl;
}
template <class T>
void print(valarray<T> const &v) {
  ostringstream os;
  for (int i = 0; i < v.size(); ++i) {
    if (i) os << ' ';
    os << v[i];
  }
  cout << os.str() << endl;
}
template <class T>
int sz(const T &c) {
  return (int)c.size();
}
template <class T>
void srt(T &c) {
  std::sort(c.begin(), c.end());
}
template <class T>
void checkmin(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
void checkmax(T &a, T b) {
  if (b > a) a = b;
}
template <class T>
T sqr(T x) {
  return x * x;
}
template <class T, class U>
T cast(U x) {
  ostringstream os;
  os << x;
  T res;
  istringstream is(os.str());
  is >> res;
  return res;
}
template <class T>
vector<T> split(string s, string x = " ") {
  vector<T> res;
  for (int i = 0; i < s.size(); i++) {
    string a;
    while (i < (int)s.size() && x.find(s[i]) == string::npos) a += s[i++];
    if (!a.empty()) res.push_back(cast<T>(a));
  }
  return res;
}
template <class T>
bool inside(T r, T c, T R, T C) {
  return r >= 0 && r < R && c >= 0 && c < C;
}
int a[128][128];
int b[128][128];
int vis[128][128];
int w, h;
int dfs(int x, int y) {
  if (!inside(x, y, w, h)) return 0;
  if (vis[x][y]) return 0;
  vis[x][y] = 1;
  int res = 1;
  if (x < w - 1 && !a[x + 1][y]) res += dfs(x + 1, y);
  if (x > 0 && !a[x][y]) res += dfs(x - 1, y);
  if (y < h - 1 && !b[x][y + 1]) res += dfs(x, y + 1);
  if (y > 0 && !b[x][y]) res += dfs(x, y - 1);
  return res;
}
int main(int argc, char *argv[]) {
  int n;
  cin >> w >> h >> n;
  for (int i(0), _n(n); i < _n; ++i) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2) {
      for (int y(y1), _b(y2 - 1); y <= _b; ++y) {
        a[x1][y] = 1;
      }
    }
    if (y1 == y2) {
      for (int x(x1), _b(x2 - 1); x <= _b; ++x) {
        b[x][y1] = 1;
      }
    }
  }
  vector<int> res;
  for (int i(0), _n(w); i < _n; ++i) {
    for (int j(0), _n(h); j < _n; ++j) {
      if (!vis[i][j]) {
        int x = dfs(i, j);
        res.push_back(x);
      }
    }
  }
  srt(res);
  print(res);
  return 0;
}
