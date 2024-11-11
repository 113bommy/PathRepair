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
int a[1000][1000];
pair<int, int> q[1000];
int moves[1000];
int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  int x = 500, y = 500;
  a[x][y] = 1;
  for (int i(0), _b(sz(s) - 1); i <= _b; ++i) {
    switch (s[i]) {
      case 'L':
        --x;
        break;
      case 'R':
        ++x;
        break;
      case 'U':
        --y;
        break;
      case 'D':
        ++y;
        break;
    }
    a[x][y] = 1;
  }
  int qh = 0;
  int qt = 0;
  q[qt++] = pair<int, int>(500, 500);
  while (qh < qt) {
    pair<int, int> cur = q[qh];
    if (cur.first == x && cur.second == y) break;
    for (int d(0), _n(4); d < _n; ++d) {
      int nx = cur.first + dr[d];
      int ny = cur.second + dc[d];
      if (a[nx][ny]) {
        a[nx][ny] = 0;
        q[qt] = pair<int, int>(nx, ny);
        moves[qt] = moves[qh] + 1;
        ++qt;
      }
    }
    ++qh;
  }
  cout << (moves[qh] == sz(s) ? "OK" : "BUG") << endl;
  return 0;
}
