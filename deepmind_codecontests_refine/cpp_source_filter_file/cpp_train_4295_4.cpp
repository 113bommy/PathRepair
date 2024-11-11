#include <bits/stdc++.h>
using namespace std;
int h, c, t;
double ans(double);
int binarysearch();
double ghadr(double);
bool check();
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> h >> c >> t;
    if (t <= double(c + h) / 2) {
      cout << 2 << endl;
      continue;
    }
    if (h == t) {
      cout << 1 << endl;
      continue;
    }
    if (check()) continue;
    int res = binarysearch();
    if (ghadr(t - ans(res)) <= ghadr(t - ans(res + 1)))
      cout << 2 * res - 1 << endl;
    else
      cout << 2 * res + 1 << endl;
  }
  return 0;
}
double ghadr(double a) { return max(a, -1 * a); }
double ans(double a) {
  double res = c + a / (2 * a - 1) * (h - c);
  return res;
}
int binarysearch() {
  int left = 2, right = 1e9;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (ans(mid) >= t && ans(mid + 1) <= t) {
      return mid;
    }
    if (ans(mid) >= t)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return 0;
}
bool check() {
  if (t >= ans(3)) {
    if (ghadr(t - ans(3)) < h - t)
      cout << 3 << endl;
    else
      cout << 1 << endl;
    return true;
  }
  return false;
}
