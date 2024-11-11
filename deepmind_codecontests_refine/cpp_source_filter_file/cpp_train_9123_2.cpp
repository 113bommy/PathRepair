#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const long long inf64 = ((long long)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
template <class T>
T sqr(T x) {
  return x * x;
}
template <class T>
T abs(T x) {
  return x < 0 ? -x : x;
}
int main() {
  double w;
  int n, m;
  cin >> n >> w >> m;
  if (m > 2 * n) {
    cout << "NO" << endl;
  } else {
    bool key = false;
    if (m < n) {
      key = true;
    } else {
      for (int i = 1; i < n + 1; ++i) {
        if (m * i == n * (i + 1)) {
          key = true;
          break;
        }
      }
    }
    if (!key) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      double v = (w * n) / m;
      double w_left = 0, v_left = 0;
      int num = 1;
      for (int i = 0; i < m; ++i) {
        if (w_left > eps) {
          printf("%d %0.6lf ", num, w_left);
          num++;
        }
        v_left = v - w_left;
        w_left = 0;
        while (v_left > w) {
          printf("%d %0.6lf ", num, w);
          v_left -= w;
          num++;
        }
        if (v_left > eps) {
          printf("%d %0.6lf ", num, v_left);
          w_left = w - v_left;
        }
        cout << endl;
      }
    }
  }
  return 0;
}
