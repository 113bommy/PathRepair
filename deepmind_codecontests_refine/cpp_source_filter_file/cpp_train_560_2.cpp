#include <bits/stdc++.h>
int rd() {
  int k = 0;
  char c = getchar();
  while (c > '9' || c < '0') c = getchar();
  while (c >= '0' && c <= '9') k = k * 10 + c - 48, c = getchar();
  return k;
}
void Min(int& x, int y) {
  if (x == -1 || x > y) x = y;
}
int n, m, w, a[21], b[21], f[21][21];
struct Mat {
  int x[21 << 1][21 << 1];
  Mat operator*(const Mat& b) const {
    Mat a;
    for (int i = 0; i < w; ++i)
      for (int j = 0; j < w; ++j) {
        a.x[i][j] = -1;
        for (int k = 0; k < w; ++k)
          if (x[i][k] > 0 && b.x[k][j] > 0) Min(a.x[i][j], x[i][k] + b.x[k][j]);
      }
    return a;
  }
} A, B;
Mat Pow(Mat x, int a) {
  Mat s(x);
  --a;
  while (a) {
    if (a & 1) s = s * x;
    x = x * x, a >>= 1;
  }
  return s;
}
void Get(int a, int b) {
  for (int i = 0; i < w; ++i) A.x[i + 1][i] = a, A.x[i][i + 1] = b;
}
int main() {
  n = rd(), m = rd(), w = n;
  for (int i = 1; i <= n; ++i) a[i] = rd();
  for (int i = 1; i <= n; ++i) b[i] = rd();
  for (int i = 0; i < w; ++i)
    for (int j = 0; j < w; ++j) A.x[i][j] = -1;
  Get(a[1], b[1]), B = A;
  for (int i = 2; i <= n; ++i) Get(a[i], b[i]), B = A * B;
  B = Pow(B, m), printf("%d\n", B.x[0][0]);
  return 0;
}
