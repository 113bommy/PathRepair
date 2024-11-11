#include <bits/stdc++.h>
using namespace std;
template <class T, class X>
inline bool checkbit(T a, X pos) {
  T t = 1;
  return ((a & (t << pos)) > 0);
}
template <class T, class X>
inline T setbit(T a, X pos) {
  T t = 1;
  return (a | (t << pos));
}
template <class T, class X>
inline T resetbit(T a, X pos) {
  T t = 1;
  return (a & (~(t << pos)));
}
template <class T, class X>
inline T togglebit(T a, X pos) {
  T t = 1;
  return (a ^ (t << pos));
}
template <typename T>
T POW(T base, T power) {
  T ret = 1;
  while (power) {
    if (power & 1) ret = (ret * base);
    base = (base * base);
    power >>= 1;
  }
  return ret;
}
template <typename T>
T PPOW(T B, T printf) {
  if (printf == 0) return 1;
  if (printf & 1)
    return B * POW(B, printf - 1);
  else
    return (POW(B, printf / 2) * POW(B, printf / 2));
}
template <typename T>
T Bigmod(T base, T power, T mod) {
  T ret = 1;
  while (power) {
    if (power & 1) ret = (ret * base) % mod;
    base = (base * base) % mod;
    power >>= 1;
  }
  return ret;
}
template <typename T>
T ModInverse(T number, T mod) {
  return Bigmod(number, mod - 2, mod);
}
template <typename T>
T GCD(T a, T b) {
  if (a < 0) return GCD(-a, b);
  if (b < 0) return GCD(a, -b);
  return (b == 0) ? a : GCD(b, a % b);
}
template <typename T>
T LCM(T a, T b) {
  if (a < 0) return LCM(-a, b);
  if (b < 0) return LCM(a, -b);
  return a * (b / GCD(a, b));
}
template <typename T>
T EUCLIDE(T a, T b, T &x, T &y) {
  if (a < 0) {
    T d = euclide(-a, b, x, y);
    x = -x;
    return d;
  }
  if (b < 0) {
    T d = euclide(a, -b, x, y);
    y = -y;
    return d;
  }
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    T d = euclide(b, a % b, x, y);
    T t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
  }
}
template <typename T>
T ABS(T a) {
  if (a < 0)
    return -a;
  else
    return a;
}
template <typename T>
double DIS(T x1, T y1, T x2, T y2) {
  return sqrt((double)((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
}
template <typename T>
T ANGLE(T x1, T y1, T x2, T y2) {
  return atan(double(y1 - y2) / double(x1 - x2));
}
template <typename T>
long long isLeft(T a, T b, T c) {
  return (c.x - a.x) * (b.y - a.y) - (b.x - a.x) * (c.y - a.y);
}
double DEG(double x) { return (180.0 * x) / (M_PI * 1.0); }
double RAD(double x) { return (x * (M_PI * 1.0)) / (180.0); }
void P_ARR(int *ar, int a, int b) {
  if (a > b) swap(a, b);
  if (a <= b) cout << ar[a];
  for (int i = a + 1; i <= b; i++) cout << " " << ar[i];
  cout << endl;
}
template <typename T>
T In() {
  char ch;
  T n = 0;
  bool ng = false;
  while (1) {
    ch = getchar();
    if (ch == '-') {
      ng = true;
      ch = getchar();
      break;
    }
    if (ch >= '0' && ch <= '9') break;
  }
  while (1) {
    n = n * 10 + (ch - '0');
    ch = getchar();
    if (ch < '0' || ch > '9') break;
  }
  return (ng ? -n : n);
}
int dir[5][2] = {{0, 0}, {1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int dp[507][507];
int ar[507];
bool is[507][507];
bool vis[507][507];
bool check(int s, int e) {
  if (vis[s][e]) return is[s][e];
  vis[s][e] = 1;
  if (s >= e) {
    is[s][e] = 1;
    return 1;
  }
  if (ar[s] != ar[e])
    return 0;
  else {
    return check(s + 1, e - 1);
  }
}
int call(int s, int e) {
  if (s > e) return 0;
  int &ret = dp[s][e];
  if (ret != -1) return ret;
  if (check(s, e)) return 1;
  ret = e - s + 1;
  int t;
  int cst = 0;
  if (ar[s] == ar[e]) {
    cst = call(s + 1, e - 1);
    ret = min(cst, ret);
  }
  for (int i = s; i <= e; i++) {
    cst = call(s, i) + call(i + 1, e);
    ret = min(ret, cst);
  }
  return ret;
}
int main() {
  int n;
  scanf("%d", &(n));
  ;
  for (int i = 1; i <= n; i++) scanf("%d", &(ar[i]));
  memset(dp, -1, sizeof dp);
  printf("%d\n", call(1, n));
  return 0;
}
