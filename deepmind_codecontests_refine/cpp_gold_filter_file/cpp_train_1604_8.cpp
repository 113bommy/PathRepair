#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
ostream& operator<<(ostream& o, pair<A, B>& p) {
  return o << "(" << p.first << ", " << p.second << ")";
}
template <class T>
ostream& operator<<(ostream& o, const vector<T>& v) {
  o << "{";
  for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
    o << *it << ", ";
  return o << "}";
}
struct debugger {
  ostream& out;
  bool first;
  void start() { first = true; }
  debugger(ostream& out) : out(out) { start(); }
  void nl() {
    out << endl;
    start();
  }
  template <class T>
  debugger& operator,(T& v) {
    if (first)
      first = false;
    else
      out << ", ";
    out << v;
    return *this;
  }
  template <class T>
  debugger& operator,(pair<T*, int> arr) {
    out << "{";
    for (typeof((arr.second) - 1) i = (0); i <= ((arr.second) - 1); i++) {
      out << arr.first[i] << ", ";
    }
    out << "}";
    return *this;
  }
} dbg(cerr);
int vis[33][33][3][3], dr[33][33], dc[33][33];
int main() {
  int b, n;
  cin >> n >> b;
  for (typeof((n)-1) i = (0); i <= ((n)-1); i++) {
    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    if (x0 == x1) {
      if (y0 < y1)
        for (typeof(y1) j = (y0); j <= (y1); j++) {
          dr[x0][j] = 0;
          dc[x0][j] = 1;
        }
      else
        for (typeof(y0) j = (y1); j <= (y0); j++) {
          dr[x0][j] = 0;
          dc[x0][j] = -1;
        }
    }
    if (y0 == y1) {
      if (x0 < x1)
        for (typeof(x1) j = (x0); j <= (x1); j++) {
          dr[j][y0] = 1;
          dc[j][y0] = 0;
        }
      else
        for (typeof(x0) j = (x1); j <= (x0); j++) {
          dr[j][y0] = -1;
          dc[j][y0] = 0;
        }
    }
  }
  int q;
  cin >> q;
  for (typeof((q)-1) i = (0); i <= ((q)-1); i++) {
    long long x, y, t;
    string str;
    cin >> x >> y >> str >> t;
    memset((vis), (-1), sizeof(vis));
    int drr = 0;
    int dcc = 0;
    if (str == "L") drr = -1;
    if (str == "R") drr = 1;
    if (str == "U") dcc = 1;
    if (str == "D") dcc = -1;
    long long tm = 0, lastx = x, lasty = y;
    while (1) {
      if (x > b || y > b || x < 0 || y < 0) {
        cout << lastx << " " << lasty << endl;
        break;
      } else if (vis[x][y][drr + 1][dcc + 1] != -1) {
        t = tm + (t - vis[x][y][drr + 1][dcc + 1]) %
                     (tm - vis[x][y][drr + 1][dcc + 1]);
        while (tm < t) {
          if (dr[x][y] != 0 || dc[x][y] != 0) {
            drr = dr[x][y];
            dcc = dc[x][y];
          }
          lastx = x;
          lasty = y;
          x += drr;
          y += dcc;
          tm++;
        }
        cout << x << " " << y << endl;
        break;
      } else if (tm == t) {
        cout << x << " " << y << endl;
        break;
      }
      vis[x][y][drr + 1][dcc + 1] = tm;
      if (dr[x][y] != 0 || dc[x][y] != 0) {
        drr = dr[x][y];
        dcc = dc[x][y];
      }
      lastx = x;
      lasty = y;
      x += drr;
      y += dcc;
      tm++;
    }
  }
  return 0;
}
