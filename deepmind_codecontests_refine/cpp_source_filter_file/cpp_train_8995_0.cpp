#include <bits/stdc++.h>
using namespace std;
char s[6][7] = {"211012", "120112", "111012", "110112", "000011", "000001"};
struct matrix {
  long long a[6][6];
  matrix() { memset(a, 0, sizeof(a)); }
  void print() {
    for (int i = 0; i < 6; ++i) {
      for (int j = 0; j < 6; ++j) cout << a[i][j] << " ";
      cout << endl;
    }
  }
} r;
int n, sx, sy, dx, dy, xf, yf;
long long t;
matrix mul(matrix a, matrix b) {
  matrix c;
  for (int i = 0; i < 6; ++i)
    for (int j = 0; j < 6; ++j) {
      long long tmp = 0;
      for (int z = 0; z < 6; ++z) tmp = (tmp + a.a[i][z] * b.a[z][j]) % n;
      c.a[i][j] = tmp;
    }
  return c;
}
matrix power(matrix a, long long t) {
  matrix r;
  for (int i = 0; i < 6; ++i) r.a[i][i] = 1;
  while (t) {
    if (t & 1) r = mul(a, r);
    a = mul(a, a);
    t /= 2;
  }
  return r;
}
int main() {
  cin >> n >> sx >> sy >> dx >> dy >> t;
  while (dx < 0) dx += n;
  while (dy < 0) dy += n;
  sx--;
  sy--;
  for (int i = 0; i < 6; ++i)
    for (int j = 0; j < 6; ++j) r.a[i][j] = s[i][j] - '0';
  r = power(r, t);
  if (t) {
    t = (t - 1) % n;
    xf = (r.a[0][0] * sx + r.a[0][1] * sy + r.a[0][2] * dx + r.a[0][3] * dy +
          r.a[0][4] * t + r.a[0][5]) %
         n;
    yf = (r.a[1][0] * sx + r.a[1][1] * sy + r.a[1][2] * dx + r.a[1][3] * dy +
          r.a[1][4] * t + r.a[1][5]) %
         n;
  } else {
    xf = sx;
    yf = sy;
  }
  printf("%i %i\n", xf + 1, yf + 1);
}
