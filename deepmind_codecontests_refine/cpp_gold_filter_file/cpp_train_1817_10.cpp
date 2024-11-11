#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
inline void upmin(T &t, T tmp) {
  if (t > tmp) t = tmp;
}
template <class T>
inline void upmax(T &t, T tmp) {
  if (t < tmp) t = tmp;
}
inline int sgn(double x) {
  if (abs(x) < 1e-9) return 0;
  return (x > 0) ? 1 : -1;
}
const double Pi = acos(-1.0);
int gint() {
  int res = 0;
  bool neg = 0;
  char z;
  for (z = getchar(); z != EOF && z != '-' && !isdigit(z); z = getchar())
    ;
  if (z == EOF) return 0;
  if (z == '-') {
    neg = 1;
    z = getchar();
  }
  for (; z != EOF && isdigit(z); res = res * 10 + z - '0', z = getchar())
    ;
  return (neg) ? -res : res;
}
long long gll() {
  long long res = 0;
  bool neg = 0;
  char z;
  for (z = getchar(); z != EOF && z != '-' && !isdigit(z); z = getchar())
    ;
  if (z == EOF) return 0;
  if (z == '-') {
    neg = 1;
    z = getchar();
  }
  for (; z != EOF && isdigit(z); res = res * 10 + z - '0', z = getchar())
    ;
  return (neg) ? -res : res;
}
const int maxn = 650;
const int maxt = 110;
int n, m, K, a[maxn], t, nn, id[maxn];
double c[maxn][maxn], d[maxt], b[maxt][maxt];
void gauss() {
  int i, j, k;
  for (i = (1); i <= (n); i++) {
    for (j = (i); j <= (n); j++)
      if (c[j][i]) {
        for (k = (i); k <= (t); k++) swap(c[i][k], c[j][k]);
        break;
      }
    for (k = (t); k >= (i); k--) c[i][k] /= c[i][i];
    for (j = (i + 1); j <= (n); j++)
      for (k = (t); k >= (i); k--) c[j][k] -= c[j][i] * c[i][k];
  }
  for (i = (n); i >= (1); i--)
    for (j = (i - 1); j >= (1); j--)
      for (k = (t); k >= (i); k--) c[j][k] -= c[j][i] * c[i][k];
  for (i = (1); i <= (nn); i++) d[i] = -c[1][n + i];
  for (i = (1); i <= (n); i++)
    if (a[i])
      for (j = (1); j <= (nn); j++) b[id[i] - n][j] = -c[i][n + j];
}
void mul() {
  int i, j;
  static double o[maxt];
  for (i = (1); i <= (nn); i++) o[i] = 0.0;
  for (i = (1); i <= (nn); i++)
    for (j = (1); j <= (nn); j++) o[j] += d[i] * b[i][j];
  for (i = (1); i <= (nn); i++) d[i] = o[i];
}
void multi() {
  int i, j, k;
  static double o[maxt][maxt];
  for (i = (1); i <= (nn); i++)
    for (j = (1); j <= (nn); j++) o[i][j] = 0.0;
  for (i = (1); i <= (nn); i++)
    for (j = (1); j <= (nn); j++)
      for (k = (1); k <= (nn); k++) o[i][j] += b[i][k] * b[k][j];
  for (i = (1); i <= (nn); i++)
    for (j = (1); j <= (nn); j++) b[i][j] = o[i][j];
}
int main() {
  int i;
  n = gint();
  m = gint();
  K = gint();
  t = n;
  for (i = (1); i <= (n); i++) {
    a[i] = gint();
    if (a[i]) id[i] = ++t;
  }
  for (i = (1); i <= (m); i++) {
    int x = gint(), y = gint();
    c[x][x]--;
    c[y][y]--;
    if (a[y])
      c[x][id[y]]++;
    else
      c[x][y]++;
    if (a[x])
      c[y][id[x]]++;
    else
      c[y][x]++;
  }
  nn = t - n;
  gauss();
  K -= 2;
  while (K) {
    if (K & 1) mul();
    multi();
    K >>= 1;
  }
  printf("%.10lf\n", sgn(d[nn]) == 0 ? 0.0 : d[nn]);
  return 0;
}
