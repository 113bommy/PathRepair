#include <bits/stdc++.h>
using namespace std;
long long labs(long long a) { return a < 0 ? (-a) : a; }
long long max(long long a, long long b) { return a > b ? a : b; }
long long min(long long a, long long b) { return a < b ? a : b; }
template <typename T>
struct Point {
  bool first;
  T x, y;
  Point() {}
  Point(T xx, T yy) : x(xx), y(yy) {}
};
template <typename T>
bool operator<(const Point<T> &p1, const Point<T> &p2) {
  return p1.x < p2.x || p1.x == p2.x && p1.y < p2.y;
}
int main() {
  int n = 6;
  vector<int> v(n);
  for (int(i) = 0; (i) < (n); (i)++) {
    cin >> v[i];
  }
  if (v[2] == 0 && v[3] != 0 || v[0] == 0 && v[1] != 0 && v[3] != 0) {
    cout << "Ron";
    return 0;
  }
  if (v[3] == 0) {
    cout << "Hermione";
    return 0;
  }
  double now = v[0];
  for (int(i) = 0; (i) < (n); (i)++) {
    if (v[i] == 0) {
      now = (v[i + 1] == 0 ? -1 : 1e30);
    } else {
      now = now / v[i] * v[i + 1];
    }
    i++;
  }
  const double EPS = 1e-9;
  if (now - v[0] > EPS) {
    cout << "Ron";
  } else {
    cout << "Hermione";
  }
  return 0;
}
