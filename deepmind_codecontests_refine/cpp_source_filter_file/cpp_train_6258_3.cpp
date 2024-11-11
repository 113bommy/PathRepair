#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void read(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void readc(char &x) {
  char c;
  while (((c = getchar()) == ' ') || c == '\n')
    ;
  x = c;
}
const long double eps = 0;
int n, i, j, k, l;
long long m;
long double mx;
struct mat {
  long double a[3][3];
} pw[35];
mat mul(mat x, mat y) {
  mat z;
  int i, j, k;
  for (((i)) = (0); ((i)) <= (((int)(3)) - 1); ((i))++)
    for (((j)) = (0); ((j)) <= (((int)(3)) - 1); ((j))++) {
      z.a[i][j] = 0;
      for (((k)) = (0); ((k)) <= (((int)(3)) - 1); ((k))++) {
        z.a[i][j] = z.a[i][j] + x.a[i][k] * y.a[k][j];
      }
    }
  return z;
}
struct _ {
  long double x, y;
  long double calc(long double t) { return y - x * t; }
} a[100005], stk[100005];
int tp;
_ operator-(_ x, _ y) { return (_){x.x - y.x, x.y - y.y}; }
long double crs(_ x, _ y) { return x.x * y.y - x.y * y.x; }
int ta[100005], tb[100005];
long double pp[100005], ans, f[3], g[3];
bool cmp(_ x, _ y) { return x.x < y.x; }
int main() {
  cin >> n >> m;
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
    double a, b, p;
    cin >> a >> b >> p;
    ta[i] = a;
    tb[i] = b;
    pp[i] = p;
    mx = max(mx, tb[i] * pp[i]);
  }
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
    a[i] = (_){pp[i], pp[i] * (ta[i] + m * mx)};
  }
  sort(a + 1, a + n + 1, cmp);
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
    while (tp > 1 && crs(a[i] - stk[tp - 1], stk[tp] - stk[tp - 1]) < eps) tp--;
    stk[++tp] = a[i];
  }
  i = 1;
  while (i <= tp) {
    f[0] = ans;
    f[1] = m;
    f[2] = 1;
    while (i < tp && stk[i].calc(f[0] + f[1] * mx) <
                         stk[i + 1].calc(f[0] + f[1] * mx) + eps)
      i++;
    pw[0].a[0][0] = 1 - stk[i].x;
    pw[0].a[1][1] = 1;
    pw[0].a[1][0] = -stk[i].x * mx;
    pw[0].a[2][0] = stk[i].y;
    pw[0].a[2][1] = -1;
    pw[0].a[2][2] = 1;
    for (((j)) = (1); ((j)) <= ((34)); ((j))++) {
      pw[j] = mul(pw[j - 1], pw[j - 1]);
    }
    for ((j) = (34); (j) >= (0); (j)--) {
      for (((k)) = (0); ((k)) <= (((int)(3)) - 1); ((k))++) g[k] = 0;
      for (((k)) = (0); ((k)) <= (((int)(3)) - 1); ((k))++)
        for (((l)) = (0); ((l)) <= (((int)(3)) - 1); ((l))++) {
          g[l] = (g[l] + f[k] * pw[j].a[k][l]);
        }
      if (g[1] > 0 &&
          (i == tp || stk[i].calc(g[0] + g[1] * mx) >
                          stk[i + 1].calc(g[0] + g[1] * mx) + eps)) {
        memcpy(f, g, sizeof(f));
      }
    }
    for (((k)) = (0); ((k)) <= (((int)(3)) - 1); ((k))++) g[k] = 0;
    for (((k)) = (0); ((k)) <= (((int)(3)) - 1); ((k))++)
      for (((l)) = (0); ((l)) <= (((int)(3)) - 1); ((l))++) {
        g[l] = (g[l] + f[k] * pw[0].a[k][l]);
      }
    memcpy(f, g, sizeof(f));
    ans = f[0];
    m = f[1];
    if (m == 0) break;
  }
  printf("%.10f\n", double(ans));
  return 0;
}
