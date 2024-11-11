#include <bits/stdc++.h>
using namespace std;
inline int getint() {
  register int xi = 0;
  register char ch = getchar();
  bool f = 0;
  while (ch < '0' || ch > '9') ch == '-' ? f = 1 : f, ch = getchar();
  while (ch >= '0' && ch <= '9')
    xi = (xi << 1) + (xi << 3) + ch - 48, ch = getchar();
  return f ? -xi : xi;
}
inline void pi(int k, char ch = 0) {
  if (k < 0) k = -k, putchar('-');
  if (k >= 10) pi(k / 10, 0);
  putchar(k % 10 + '0');
  if (ch) putchar(ch);
}
inline unsigned int LOG2(unsigned int x) {
  unsigned int ret;
  __asm__ __volatile__("bsrl %1, %%eax" : "=a"(ret) : "m"(x));
  return ret;
}
const int MAXN = 1e2 + 7;
double q[MAXN << 1];
int n;
struct matrix {
  double a[MAXN << 1][MAXN << 1];
  inline double* operator[](int k) { return a[k]; }
  inline matrix operator*(matrix b) {
    matrix c;
    for (int i = 0; i <= n * 2; i++)
      for (int j = 0; j <= n * 2; j++) {
        c[i][j] = 0;
        for (int k = 0; k <= n * 2; k++)
          c[i][j] = max(c[i][j], a[i][k] + b[k][j]);
        c[i][j] /= 2;
      }
    return c;
  }
  inline matrix& operator*=(matrix b) {
    (*this) *= b;
    return (*this);
  }
} a;
int main(void) {
  cin >> n;
  for (int i = 0; i <= n; i++) cin >> q[i];
  for (int i = 0; i <= n * 2; ++i)
    for (int j = 0; j <= n * 2; ++j)
      if (i + j >= n && ((i - j + n) & 1) == 0 && i - j <= n && j - i <= n)
        a[i][j] = q[(i + n - j) >> 1];
      else
        a[i][j] = -1e18;
  for (int i = 1; i < 30; i++) a = a * a;
  double ans = 0;
  for (int i = 0; i <= n * 2; ++i) ans = max(ans, a[0][i]);
  printf("%.10f", ans);
  return 0;
}
