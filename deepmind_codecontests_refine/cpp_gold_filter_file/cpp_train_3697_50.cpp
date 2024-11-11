#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool getmin(T *a, const T &b) {
  if (b < *a) {
    *a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool getmax(T *a, const T &b) {
  if (b > *a) {
    *a = b;
    return true;
  }
  return false;
}
template <class T>
inline void read(T *a) {
  char c;
  while (isspace(c = getchar())) {
  }
  bool flag = 0;
  if (c == '-')
    flag = 1, *a = 0;
  else
    *a = c - 48;
  while (isdigit(c = getchar())) *a = *a * 10 + c - 48;
  if (flag) *a = -*a;
}
const int mo = 1000000007;
template <class T>
T pow(T a, T b, int c = mo) {
  T res = 1;
  for (T i = 1; i <= b; i <<= 1, a = 1LL * a * a % c)
    if (b & i) res = 1LL * res * a % c;
  return res;
}
const int N = 2001;
const double eps = 1e-12;
struct node {
  double x, y;
  node() {}
  node(const double &_x, const double &_y) : x(_x), y(_y) {}
} a[N];
node operator+(const node &A, const node &B) {
  return node(A.x + B.x, A.y + B.y);
}
node operator-(const node &A, const node &B) {
  return node(A.x - B.x, A.y - B.y);
}
double area(const node &A, const node &B) { return A.x * B.y - A.y * B.x; }
double angle(const node &A) { return atan2(A.y, A.x); }
node rotate(const node &A, double deg) {
  return node(A.x * cos(deg) - A.y * sin(deg), A.x * sin(deg) + A.y * cos(deg));
}
node calc(double A, double B, double C) {
  if (A == 0) return node(0, -C / B);
  if (B == 0) return node(-C / A, 0);
  double x1 = 1.213893821, x2 = -9.129384;
  node P(x1, (-A * x1 - C) / B), Q(x2, (-A * x2 - C) / B);
  double deg = angle(P - Q);
  P = rotate(P, -deg);
  return rotate(node(0, P.y), deg);
}
int n;
double s[N];
int main() {
  cin >> n;
  double A, B, C;
  for (int i = (1); i <= (n); ++i) {
    read(&A);
    read(&B);
    read(&C);
    a[i] = calc(A, B, C);
  }
  long long ans = 0;
  for (int i = (1); i <= (n - 2); ++i) {
    int tot = 0;
    int zero = 0;
    for (int j = (i + 1); j <= (n); ++j) {
      if (fabs(a[i].x - a[j].x) < eps && fabs(a[i].y - a[j].y) < eps) {
        ++zero;
        continue;
      }
      s[++tot] = angle(a[j] - a[i]);
      if (s[tot] < 0) s[tot] += 3.14159265358979323846264338327950288;
      if (fabs(s[tot] - 3.14159265358979323846264338327950288) < eps)
        s[tot] = 0;
    }
    sort(s + 1, s + tot + 1);
    int num = 0;
    s[0] = 1e100;
    for (int j = (1); j <= (tot); ++j)
      if (fabs(s[j] - s[j - 1]) > eps)
        ans += num * (num - 1) / 2, num = 1;
      else
        ++num;
    ans += num * (num - 1) / 2;
    ans += zero * (zero - 1) / 2;
    ans += zero * tot;
  }
  cout << ans << endl;
  return 0;
}
