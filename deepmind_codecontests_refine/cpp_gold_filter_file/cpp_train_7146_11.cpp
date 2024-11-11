#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long int mod = 1000000007;
long long int inf = 1000000000000000010;
long long int ninf = -1000000000000000010;
double PI = 3.141592654;
template <typename T>
inline T gcd(T a, T b) {
  T t;
  if (a < b) {
    while (a) {
      t = a;
      a = b % a;
      b = t;
    }
    return b;
  } else {
    while (b) {
      t = b;
      b = a % b;
      a = t;
    }
    return a;
  }
}
long long int power(long long int x, long long int y) {
  long long int ans = 1;
  while (y > 0) {
    if (y & 1) ans = (ans * x) % mod;
    x = (x * x) % mod;
    y = y >> 1;
  }
  return ans;
}
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
int main() {
  long long int tR, tx1, ty1, tx2, ty2;
  scanf("%lld%lld%lld", &tR, &tx1, &ty1);
  scanf("%lld%lld", &tx2, &ty2);
  double x, y, r, d, R, x1, y1, x2, y2;
  x1 = (double)tx1;
  y1 = (double)ty1;
  R = (double)tR;
  x2 = (double)tx2 - x1;
  y2 = (double)ty2 - y1;
  d = sqrt(x2 * x2 + y2 * y2);
  if (abs(d - R) < 0.000001 || d > R) {
    x = 0;
    y = 0;
    r = R;
  } else if (x2 == 0 && y2 == 0) {
    x = R / 2;
    y = 0;
    r = R / 2;
  } else if (x2 == 0) {
    if (0 < y2)
      y = -1 * R;
    else
      y = R;
    x = 0;
    y = (y + y2) / 2;
    r = (d + R) / 2;
  } else {
    double the = atan(abs(y2) / abs(x2));
    if (0 < x2)
      x = -1 * R * cos(the);
    else
      x = R * cos(the);
    if (0 < y2)
      y = -1 * R * sin(the);
    else
      y = R * sin(the);
    x = (x + x2) / 2;
    y = (y + y2) / 2;
    r = (d + R) / 2;
  }
  printf("%.7lf %.7lf %.7lf\n", x1 + x, y1 + y, r);
  return 0;
}
