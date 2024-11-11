#include <bits/stdc++.h>
using namespace std;
template <class T>
void max_swap(T& a, const T& b) {
  a = max(a, b);
}
template <class T>
void min_swap(T& a, const T& b) {
  a = min(a, b);
}
template <class T>
void uniq(vector<T>& c) {
  sort(c.begin(), c.end());
  c.erase(unique(c.begin(), c.end()), c.end());
}
template <class T>
string to_s(const T& a) {
  ostringstream os;
  os << a;
  return os.str();
}
template <class T>
T to_T(const string& s) {
  istringstream is(s);
  T res;
  is >> res;
  return res;
}
template <class T, class U>
ostream& operator<<(ostream& os, pair<T, U>& p) {
  os << "( " << p.first << ", " << p.second << " )";
  return os;
}
template <class T>
void print(T a, int n, const string& deli = " ", int br = 1) {
  for (int i = 0; i < n; ++i) {
    cout << a[i];
    if (i + 1 != n) cout << deli;
  }
  while (br--) cout << endl;
}
template <class T>
void print(const T& c, const string& deli = " ", int br = 1) {
  for (__typeof__((c).begin()) it = (c).begin(); it != (c).end(); ++it) {
    cout << *it;
    if (++it != c.end()) cout << deli;
    --it;
  }
  while (br--) cout << endl;
}
template <class T>
void print2d(T a, int w, int h, int width = -1, int br = 1) {
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (width != -1) cout.width(width);
      cout << a[i][j] << ' ';
    }
    cout << endl;
  }
  while (br--) cout << endl;
}
template <class T>
void input(T& a, int n) {
  for (int i = 0; i < n; ++i) cin >> a[i];
}
template <class T>
void input(T* a, int n) {
  for (int i = 0; i < n; ++i) cin >> a[i];
}
void fast_io() {
  cin.tie(0);
  ios::sync_with_stdio(false);
}
bool valid(int x, int y, int w, int h) {
  return 0 <= x && x < w && 0 <= y && y < h;
}
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const double PI = acos(-1.0);
const int mod = ((long long)(1e9)) + 7;
double disdis(double x1, double y1, double x2, double y2) {
  double dx = x1 - x2;
  double dy = y1 - y2;
  return dx * dx + dy * dy;
}
int main() {
  fast_io();
  int n, m;
  double a, b;
  cin >> n >> m >> a >> b;
  static double ya[((long long)(1e5)) + 100], yb[((long long)(1e5)) + 100],
      len[((long long)(1e5)) + 100];
  input(ya, n);
  input(yb, m);
  input(len, m);
  double min_dis = 1e100;
  int res_p, res_q;
  for (int q = 0; q < (int)(m); ++q) {
    double y_inc = yb[q] / b;
    double cross_y = y_inc * a;
    int k = lower_bound(ya, ya + n, cross_y) - ya;
    for (int p = max(0, k - 50); p < min(n, k + 50); ++p) {
      double dis = disdis(0, 0, a, ya[p]) + disdis(a, ya[p], b, yb[q]) + len[q];
      if (dis < min_dis) {
        min_dis = dis;
        res_p = p + 1;
        res_q = q + 1;
      }
    }
  }
  cout << res_p << " " << res_q << endl;
}
