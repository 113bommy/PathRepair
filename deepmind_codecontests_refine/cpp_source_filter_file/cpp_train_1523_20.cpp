#include <bits/stdc++.h>
using namespace std;
using namespace rel_ops;
const double PI = acos((double)-1);
int ts, ts2, ts3, ts4;
int n, m;
long long gcd(long long x, long long y) {
  long long t;
  for (; y != 0;) {
    t = x % y;
    x = y;
    y = t;
  }
  return x;
}
double sqr(double x) { return x * x; }
int x[10000005], y[10005], col[10005];
int cret, die, MID;
void dfs(int k, int p) {
  col[k] = p;
  for (int i = 1; i <= n; i++)
    if (abs(x[i] - x[k]) + abs(y[i] - y[k]) > MID) {
      if (col[i] == -1)
        dfs(i, !p);
      else if (col[i] == col[k]) {
        die = 1;
        return;
      }
      if (die) return;
    }
}
int check(int mid) {
  MID = mid;
  int i, j, k, l, t1, t2, t3, t4, t5, t6, t7, t8, t9, t, nw;
  cret = 0;
  if (mid == 2000) ts = 0;
  (memset((col), -1, sizeof((col))));
  for (i = 1; i <= n; i++)
    if (col[i] == -1) {
      die = 0;
      dfs(i, 0);
      cret++;
      if (die) return 0;
    }
  return 1;
}
int pow(int x, int y) {
  int t1 = 1;
  for (int i = 1; i <= y; i++) t1 = t1 * x % 1000000007;
  return t1;
}
struct poi {
  int x, y;
} a[10005];
void mn(int &x, int y) { x = min(x, y); }
void mx(int &x, int y) { x = max(x, y); }
int main() {
  int i, j, k, l, t1, t2, t3, t4, t5, t6, t7, t8, t9, t, nw;
  int xn = 2000000000, xx = -2000000000, yn = 2000000000, yx = -2000000000;
  int tt1, tt2, tt3, tt4;
  double u1, u2, u3, u4, u5, u6, u7, u8, u9;
  char c1, c2, c3;
  srand((unsigned)time(0));
  int le = 0, ri = 20000;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> t1 >> t2;
    a[i].x = t1 - t2, a[i].y = t1 + t2;
    x[i] = a[i].x, y[i] = a[i].y;
  }
  for (i = 1; i <= n; i++) {
    mn(xn, a[i].x);
    mx(xx, a[i].x);
    mn(yn, a[i].y);
    mx(yx, a[i].y);
  }
  t1 = t2 = 0;
  for (i = 1; i <= n; i++) {
    mx(t1, min(max(abs(x[i] - xn), abs(y[i] - yn)),
               max(abs(x[i] - xx), abs(y[i] - yx))));
    mx(t2, min(max(abs(x[i] - xn), abs(y[i] - yx)),
               max(abs(x[i] - xx), abs(y[i] - yn))));
  }
  if (t1 == t2 && xn + t1 < xx && yn + t1 < yx) cret++;
  for (i = 1; i <= n; i++)
    if (max(max(abs(x[i] - xn), abs(y[i] - yn)),
            max(abs(x[i] - xx), abs(y[i] - yx))) < min(t1, t2))
      cret++;
  cret++;
  cout << min(t1, t2) << endl << pow(2, cret) << endl;
  return 0;
}
