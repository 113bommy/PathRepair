#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-10;
const double PI = acos(-1.0);
template <class T>
T gcd(T a, T b) {
  for (T c; b; c = a, a = b, b = c % b)
    ;
  return a;
}
template <class T>
void out(const vector<T> &a) {
  for (int i = 0; i < ((int)(a).size()); ++i) cout << a[i] << " ";
  cout << endl;
}
int countbit(int n) { return n == 0 ? 0 : 1 + countbit(n & (n - 1)); }
const int d8[8][2] = {{1, 0}, {-1, 0},  {0, 1},  {0, -1},
                      {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
const int d4[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
inline int dcmp(double x) { return (x > EPS) - (x < -EPS); }
inline double cross(const complex<double> &a, const complex<double> &b) {
  return (conj(a) * b).imag();
}
inline double dot(const complex<double> &a, const complex<double> &b) {
  return (conj(a) * b).real();
}
int main() {
  int n;
  scanf("%d", &n);
  int min_x, min_y, max_x, max_y;
  int min_slash, min_diag, max_slash, max_diag;
  min_slash = min_diag = min_x = min_y = INT_MAX;
  max_slash = max_diag = max_x = max_y = INT_MIN;
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    min_x = min(min_x, x);
    min_y = min(min_y, y);
    max_x = max(max_x, x);
    max_y = max(max_y, y);
    min_slash = min(min_slash, x + y);
    max_slash = max(max_slash, x + y);
    min_diag = min(min_diag, y - x);
    max_diag = max(max_diag, y - x);
  }
  min_x--;
  min_y--;
  max_x++;
  max_y++;
  min_slash--;
  max_slash++;
  min_diag--;
  max_diag++;
  int ret = 2 * (max_x - min_x + max_y - min_y);
  ret -= min_slash - (min_x + min_y);
  ret -= (max_x + max_y) - max_slash;
  ret -= (max_y - min_x) - max_diag;
  ret -= min_diag - (min_y - max_x);
  cout << ret << endl;
  return 0;
}
