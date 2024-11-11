#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000 + 10;
const double pai = 3.1415926535898;
const double eps = 1e-9;
int n, a[maxn], b[maxn], c[maxn], ans;
struct Point {
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
};
Point operator-(Point A, Point B) { return Point(A.x - B.x, A.y - B.y); }
double operator*(Point v1, Point v2) { return v1.x * v2.x + v1.y * v2.y; }
double operator&(Point v1, Point v2) { return v1.x * v2.y - v1.y * v2.x; }
double dist(Point v1) { return sqrt(v1.x * v1.x + v1.y * v1.y); }
int top;
double stk[maxn];
double thecos(Point v1, Point v2) {
  return (double)(v1 * v2) / (dist(v1) * dist(v2));
}
double thesin(Point v1, Point v2) {
  return (double)(v1 & v2) / (dist(v1) * dist(v2));
}
Point o = Point(0, 0);
void add(int i, int j) {
  Point p;
  p.x = (double)(c[i] * b[j] - c[j] * b[i]) / (a[i] * b[j] - a[j] * b[i]);
  p.y = (double)(c[i] * a[j] - c[j] * a[i]) / (b[i] * a[j] - b[j] * a[i]);
  double itcos, itsin;
  Point v1 = Point(b[j], -a[j]), v2 = o - p;
  Point v = Point(b[i], -a[i]);
  if ((v1 & v) * (v2 & v) < 0) v2 = p - o;
  itcos = thecos(v1, v2);
  itsin = thesin(v1, v2);
  stk[++top] = atan2(itsin, itcos);
}
int main() {
  cin >> n;
  int s = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &a[i], &b[i], &c[i]);
    if (c[i] == 0) s++;
  }
  ans += s * (s - 1) * (n - s);
  for (int i = 1; i <= n; i++) {
    if (c[i] == 0) continue;
    top = 0;
    for (int j = 1; j <= n; j++) {
      if (c[j] != 0 && i != j) add(i, j);
    }
    sort(stk + 1, stk + 1 + top);
    int k = 1, cnt = 0;
    for (int i = 2; i <= top; i++) {
      if (stk[i] - stk[i - 1] <= eps)
        k++;
      else {
        cnt += (k * (k - 1)) / 2;
        k = 1;
      }
    }
    cnt += (k * (k - 1)) / 2;
    ans += cnt;
    k = 1;
  }
  cout << ans / 2;
  return 0;
}
