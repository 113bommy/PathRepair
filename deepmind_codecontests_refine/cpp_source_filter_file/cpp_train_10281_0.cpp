#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double PI = acos(-1);
template <class T, class S>
inline void add(T& a, S b) {
  a += b;
  if (a >= mod) a -= mod;
}
template <class T, class S>
inline void sub(T& a, S b) {
  a -= b;
  if (a < 0) a += mod;
}
template <class T, class S>
inline bool chkmax(T& a, S b) {
  return a < b ? a = b, true : false;
}
template <class T, class S>
inline bool chkmin(T& a, S b) {
  return a > b ? a = b, true : false;
}
long long x, y;
long long exgcd(long long a, long long b, long long& x, long long& y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  } else {
    long long gcd, t;
    gcd = exgcd(b, a % b, x, y);
    t = x;
    x = y;
    y = t - (a / b) * y;
    return gcd;
  }
}
long long n, m, sx, sy, vx, vy;
long long gao(long long a, long long b, long long t1, long long t2) {
  long long c = t2 - t1;
  long long gcd = exgcd(a, b, x, y);
  if (c % gcd) return INF;
  x *= c / gcd;
  y *= c / gcd;
  long long mo = abs(b / gcd);
  x = (x % mo + mo) % mo;
  return 2 * n * x + t1;
}
long long calc(long long sx, long long sy, long long vx, long long vy,
               long long tx, long long ty) {
  long long t11 = 0, t12 = 0;
  long long t21 = 0, t22 = 0;
  if (vx > 0) {
    if (tx >= sx)
      t11 = tx - sx, t12 = t11 + 2 * (n - tx);
    else
      t11 = sx - tx + 2 * (n - sx), t12 = t11 + 2 * tx;
  } else {
    if (tx <= sx)
      t11 = sx - tx, t12 = t11 + 2 * tx;
    else
      t11 = tx - sx + 2 * sx, t12 = t11 + 2 * (n - tx);
  }
  if (vy > 0) {
    if (ty >= sy)
      t21 = ty - sy, t22 = t21 + 2 * (m - ty);
    else
      t21 = sy - ty + 2 * (m - sy), t22 = t21 + 2 * ty;
  } else {
    if (ty <= sy)
      t21 = sy - ty, t22 = t21 + 2 * ty;
    else
      t21 = ty - sy + 2 * sy, t22 = t21 + 2 * (m - ty);
  }
  long long tim = INF;
  chkmin(tim, gao(2 * n, -2 * m, t11, t21));
  chkmin(tim, gao(2 * n, -2 * m, t11, t22));
  chkmin(tim, gao(2 * n, -2 * m, t12, t21));
  chkmin(tim, gao(2 * n, -2 * m, t12, t22));
  return tim;
}
void print(int who) {
  if (who == 0)
    cout << "0 0"
         << "\n";
  else if (who == 1)
    cout << n << " "
         << "0\n";
  else if (who == 2)
    cout << "0 " << m << "\n";
  else if (who == 3)
    cout << n << " " << m << "\n";
  else
    cout << "-1"
         << "\n";
  exit(0);
}
int main() {
  cin >> n >> m >> sx >> sy >> vx >> vy;
  if (!vx) {
    if (sx == 0 && vy == 1)
      print(2);
    else if (sx == 0 && vy == -1)
      print(0);
    else if (sx == n && vy == 1)
      print(3);
    else if (sx == n && vy == -1)
      print(1);
    else
      print(-1);
  } else if (!vy) {
    if (sy == 0 && vx == 1)
      print(1);
    else if (sy == 0 && vx == -1)
      print(0);
    else if (sy == m && vy == 1)
      print(3);
    else if (sy == m && vy == -1)
      print(2);
    else
      print(-1);
  } else {
    long long tim = INF, who = -1;
    if (chkmin(tim, calc(sx, sy, vx, vy, 0, 0))) who = 0;
    if (chkmin(tim, calc(sx, sy, vx, vy, n, 0))) who = 1;
    if (chkmin(tim, calc(sx, sy, vx, vy, 0, m))) who = 2;
    if (chkmin(tim, calc(sx, sy, vx, vy, n, m))) who = 3;
    print(who);
  }
  return 0;
}
