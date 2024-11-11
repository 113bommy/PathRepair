#include <bits/stdc++.h>
using namespace std;
const int INF_MAX = 0x7FFFFFFF;
const int INF_MIN = -(1 << 30);
const double eps = 1e-10;
const double pi = acos(-1.0);
int toInt(string s) {
  istringstream sin(s);
  int t;
  sin >> t;
  return t;
}
template <class T>
string toString(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}
template <class T>
inline T gcd(T a, T b) {
  if (a < 0) return gcd(-a, b);
  if (b < 0) return gcd(a, -b);
  return (b == 0) ? a : gcd(b, a % b);
}
template <class T>
inline T lcm(T a, T b) {
  if (a < 0) return lcm(-a, b);
  if (b < 0) return lcm(a, -b);
  return a * (b / gcd(a, b));
}
template <class T>
inline void CLR(priority_queue<T, vector<T>, greater<T> > &Q) {
  while (!Q.empty()) Q.pop();
}
inline int random(int l, int r) { return rand() % (r - l + 1) + l; }
int dir_4[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
int dir_8[8][2] = {{0, 1},  {-1, 1}, {-1, 0}, {-1, -1},
                   {0, -1}, {1, -1}, {1, 0},  {1, 1}};
char mat[55][55];
int n, m;
bool solve() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char ch1 = mat[i][j];
      if (ch1 != 'B') continue;
      for (int ii = 0; ii < n; ii++) {
        for (int jj = 0; jj < m; jj++) {
          bool flag1 = true, flag2 = true;
          bool flag3 = true, flag4 = true;
          char ch2 = mat[ii][jj];
          if (ch2 != 'B') continue;
          int minx = min(i, ii);
          int maxx = max(i, ii);
          int miny = min(j, jj);
          int maxy = max(j, jj);
          for (int k = miny; k < maxy; k++) {
            if (mat[i][k] != 'B') flag1 = false;
            if (mat[ii][k] != 'B') flag3 = false;
          }
          for (int k = minx; k < maxx; k++) {
            if (mat[k][jj] != 'B') flag2 = false;
            if (mat[k][j] != 'B') flag4 = false;
          }
          if (flag1 && flag2 || flag3 && flag4)
            continue;
          else
            return false;
        }
      }
    }
  }
  return true;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> mat[i];
  if (solve())
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
