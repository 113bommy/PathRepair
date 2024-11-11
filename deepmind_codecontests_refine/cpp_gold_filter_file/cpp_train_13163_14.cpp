#include <bits/stdc++.h>
using namespace std;
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(int64_t &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template <class T, class... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
template <class T>
void _W(const T &x) {
  cout << x;
}
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template <class T, class U>
void _W(const pair<T, U> &x) {
  _W(x.first);
  putchar(' ');
  _W(x.second);
}
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++))
    if (i != x.cbegin()) putchar(' ');
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
int MOD = 1e9 + 7;
void ADD(long long &x, long long v) {
  x = (x + v) % MOD;
  if (x < 0) x += MOD;
}
const int SIZE = 1e6 + 10;
const double EPS = 1e-12;
const double PI = acos(-1);
struct Point {
  long long x, y, z;
  Point(long long x = 0, long long y = 0, long long z = 0) : x(x), y(y), z(z) {}
  Point operator-(const Point &b) const {
    return Point(x - b.x, y - b.y, z - b.z);
  }
  Point operator+(const Point &b) const {
    return Point(x + b.x, y + b.y, z - b.z);
  }
  long double dis() const { return sqrt((long double)(x * x + y * y + z * z)); }
  void scan() { R(x, y, z); }
  void print() { W(x, y); }
} p[SIZE];
int main() {
  int n;
  R(n);
  for (int i = 0; i < (n); ++i) p[i].scan();
  long double an = 2e12;
  for (int i = (1); i < (n); ++i)
    for (int j = (1); j < (i); ++j) {
      an = min(an, ((p[i] - p[0]).dis() + (p[j] - p[0]).dis() +
                    (p[i] - p[j]).dis()) /
                       2);
    }
  W((double)an);
  return 0;
}
