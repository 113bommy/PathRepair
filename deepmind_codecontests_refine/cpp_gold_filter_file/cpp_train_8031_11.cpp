#include <bits/stdc++.h>
using namespace std;
const int INF = (1 << 30) - 1;
const int DIRX[] = {-1, 0, 0, 1, -1, -1, 1, 1},
          DIRY[] = {0, -1, 1, 0, -1, 1, -1, 1};
const double ERR = 1e-11, PI = (2 * acos(0.0));
template <class T>
inline T MIN(T a, T b) {
  return ((a < b) ? (a) : (b));
}
template <class T>
inline T MAX(T a, T b) {
  return ((b < a) ? (a) : (b));
}
template <class T>
inline T ABS(T a) {
  return ((a < (T)0) ? (-a) : (a));
}
template <class T>
inline void checkMIN(T& a, T b) {
  if (b < a) a = b;
}
template <class T>
inline void checkMAX(T& a, T b) {
  if (a < b) a = b;
}
template <class T>
T SQR(T x) {
  return (x * x);
}
template <class T>
T GCD(T a, T b) {
  if (!b)
    return a;
  else
    return GCD(b, a % b);
}
template <class T>
T fastPow(T Base, T Power) {
  T Result = (T)1;
  while (Power > 0) {
    if (Power & (T)1) Result *= Base;
    Power >>= 1;
    Base *= Base;
  }
  return Result;
}
template <class T>
T modPow(T Base, T Power, T Mod) {
  T Result = (T)1;
  while (Power > 0) {
    if (Power & (T)1) Result = (Result * Base) % Mod;
    Power >>= 1;
    Base = (Base * Base) % Mod;
  }
  return (Result % Mod);
}
inline int CompareDouble(double x, double y, double err = ERR) {
  double d = x - y;
  if (d > err) return 1;
  if (d < -err) return -1;
  return 0;
}
char a[155][155];
int l[155], r[155];
int main() {
  int _kase = 1;
  int i, j, k, n, m, e, x;
  while (_kase--) {
    scanf("%d %d", &n, &m);
    for (i = (1); i <= (n); i++)
      for (j = (1); j <= (m); j++) scanf(" %c", &a[i][j]);
    l[n + 1] = m;
    r[n + 1] = 1;
    e = 0;
    for (i = (n); i >= (1); i--) {
      l[i] = l[n + 1];
      r[i] = r[n + 1];
      for (j = (1); j <= (m); j++)
        if (a[i][j] == 'W') r[i] = j, checkMAX(e, i);
      for (j = (m); j >= (1); j--)
        if (a[i][j] == 'W') l[i] = j;
    }
    j = 1;
    k = 0;
    for (i = (1); i <= (e); i++) {
      if (i % 2 == 1) {
        x = ((r[i]) < (r[i + 1]) ? (r[i + 1]) : (r[i]));
        if (x > j) {
          k += x - j;
          j = x;
        }
      } else {
        x = ((l[i]) < (l[i + 1]) ? (l[i]) : (l[i + 1]));
        if (x < j) {
          k += j - x;
          j = x;
        }
      }
    }
    cout << MAX(k + e - 1, 0) << endl;
  }
  return 0;
}
