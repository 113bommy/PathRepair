#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) { return a > b ? a : b; }
long long min(long long a, long long b) { return a < b ? a : b; }
template <typename T>
struct Point {
  T x, y;
  Point() {}
  Point(T xx, T yy) : x(xx), y(yy) {}
};
template <typename T>
bool operator<(const Point<T> &p1, const Point<T> &p2) {
  return p1.x < p2.x || p1.x == p2.x && p1.y < p2.y;
}
template <typename T>
Point<T> operator-(const Point<T> &p1, const Point<T> &p2) {
  return Point<T>(p1.x - p2.x, p1.y - p2.y);
}
template <typename T>
Point<T> operator+(const Point<T> &p1, const Point<T> &p2) {
  return Point<T>(p1.x + p2.x, p1.y + p2.y);
}
template <typename T>
T operator^(const Point<T> &p1, const Point<T> &p2) {
  return p1.x * p2.y - p2.x * p1.y;
}
int n = 4;
vector<int> v, p;
void next() {
  int a = v[0], b = p[0];
  for (int(i) = 0; (i) < n - 1; (i)++) {
    v[i] = v[i + 1];
    p[i] = p[i + 1];
  }
  v[n - 1] = a;
  p[n - 1] = b;
}
bool check() {
  for (int(i) = 0; (i) < n; (i)++) {
    if (v[i] != 1) return false;
  }
  return true;
}
bool is2111() {
  bool fl = 0;
  for (int(i) = 0; (i) < n; (i)++) {
    if (v[i] > 2 || v[i] == 2 && fl) return false;
    if (v[i] == 2) fl = 1;
  }
  if (!fl) return false;
  while (v[0] != 2) next();
  return true;
}
int main() {
  v.resize(n);
  p.resize(n);
  for (int(i) = 0; (i) < n; (i)++) {
    cin >> v[i];
    p[i] = i + 1;
  }
  while (!check()) {
    if (is2111()) {
      v[0] += 2;
      v[1]++;
      v[n - 1]++;
      v[0] /= 4;
      v[n - 1] /= 2;
      v[1] /= 2;
      cout << "+" << p[0] << endl;
      cout << "+" << p[n - 1] << endl;
      cout << "/" << p[n - 1] << endl;
      cout << "/" << p[0] << endl;
      continue;
    }
    int fl = 0;
    int maxch = -1;
    for (int(i) = 0; (i) < n; (i)++) {
      if (v[0] % 2 == 0 && v[1] % 2 == 0) {
        if (v[0] > maxch) {
          fl = p[0];
          maxch = v[0];
        }
        if (v[1] > maxch) {
          fl = p[0];
          maxch = v[1];
        }
      }
      next();
    }
    if (fl) {
      while (p[0] != fl) next();
      v[0] /= 2;
      v[1] /= 2;
      cout << "/" << p[0] << endl;
      continue;
    }
    for (int(i) = 0; (i) < n; (i)++) {
      if (v[0] % 2 == 1 && v[1] % 2 == 1 && (v[0] != 1 || v[1] != 1)) {
        v[0]++;
        v[1]++;
        cout << "+" << p[0] << endl;
        fl = 1;
        break;
      }
      next();
    }
    if (fl) continue;
    for (int(i) = 0; (i) < n; (i)++) {
      if (v[0] != 1 || v[1] != 1) {
        v[0]++;
        v[1]++;
        cout << "+" << p[0] << endl;
        fl = 1;
        break;
      }
      next();
    }
    if (fl) continue;
  }
  return 0;
}
