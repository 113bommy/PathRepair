#include <bits/stdc++.h>
using namespace std;
int _pow(int a, int b, int mo) {
  int tmp = 1;
  a %= mo;
  for (; b; b >>= 1) {
    if (b & 1) tmp = (long long)tmp * a % mo;
    a = (long long)a * a % mo;
  }
  return tmp;
}
template <class T>
inline void R(T &xx) {
  xx = 0;
  char ch = getchar();
  bool F = 0;
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') F = 1, ch = getchar();
  while (ch >= '0' && ch <= '9')
    xx = xx + xx + (xx << 3) + ch - 48, ch = getchar();
  if (F) xx = -xx;
}
struct mat {
  int a[128][128];
  mat() { memset(a, 0, sizeof(a)); }
  inline void operator*=(const mat &b) {
    mat c;
    for (int i = 0; i < (int)128; i++)
      for (int j = 0; j < (int)128; j++) {
        long long t = 0;
        for (int k = 0; k < (int)128; k++) {
          t += (long long)a[i][k] * b.a[k][j];
          if (t > (1000000007LL << 10)) t -= 1000000007LL << 10;
        }
        c.a[i][j] = t % 1000000007LL;
      }
    memcpy(a, c.a, sizeof(a));
  }
} base, res;
mat _pow(mat a, int b) {
  mat tmp = base;
  for (; b; b >>= 1) {
    if (b & 1) tmp *= a;
    a *= a;
  }
  return tmp;
}
int main() {
  for (int i = 0; i < (int)128; i++) base.a[i][i] = 1;
  res = base;
  for (int H = 1; H <= 7; H++) {
    int w;
    R(w);
    mat a;
    for (int i = 0; i < (int)(1 << H); i++)
      for (int j = 0; j < (int)(1 << H); j++)
        for (int k = 0; k < (int)(1 << H - 1); k++)
          if ((i | j | k | (k << 1)) == (1 << H) - 1) a.a[i][j]++;
    res *= _pow(a, w);
  }
  printf("%d\n", res.a[0][0]);
  return 0;
}
