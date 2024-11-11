#include <bits/stdc++.h>
using namespace std;
int A, B, k;
string s1, s2;
int qzh[800008][4];
int r[800008];
int a1[800008], a2[800008];
const char ch1[5] = {'A', 'C', 'G', 'T'};
struct c {
  double r, i;
  c() {}
  c(double rr, double ii) { r = rr, i = ii; }
  c operator+(const c &x) { return c(r + x.r, i + x.i); }
  c operator-(const c &x) { return c(r - x.r, i - x.i); }
  c operator*(const c &x) { return c(r * x.r - i * x.i, r * x.i + i * x.r); }
  c operator/(const int &x) { return c(r / x, i / x); }
};
c f[4][800008];
c g[4][800008];
c w[800008];
int l = 1, tmp = 0;
const double pi = 3.1415926535;
int res[800008];
void FFT(c a[], int type) {
  for (int i = 0; i < l; i++)
    if (r[i] > i) swap(a[i], a[r[i]]);
  for (int len = 1, t = l >> 1; len < l; len <<= 1, t >>= 1) {
    for (int i = 0; i < l; i += (len << 1)) {
      for (int j = 0; j < len; j++) {
        c ww = w[t * j];
        ww.i = ww.i * type;
        c x = a[i + j];
        c y = a[i + j + len] * ww;
        a[i + j] = x + y;
        a[i + j + len] = x - y;
      }
    }
  }
  if (type == -1)
    for (int i = 0; i < l; i++) a[i] = a[i] / l;
}
int main() {
  scanf("%d%d%d", &A, &B, &k);
  cin >> s1 >> s2;
  for (int i = 0; i < B / 2; i++) swap(s2[i], s2[B - i - 1]);
  for (int i = 0; i < A; i++)
    for (int j = 0; j <= 3; j++) {
      if (s1[i] == ch1[j]) {
        a1[i] = j;
      }
    }
  for (int i = 0; i < B; i++)
    for (int j = 0; j <= 3; j++) {
      if (s2[i] == ch1[j]) {
        a2[i] = j;
      }
    }
  for (int i = 0; i < B; i++) g[a2[i]][i].r = 1.0;
  for (int i = 0; i < A; i++) {
    for (int j = 0; j < 4; j++) qzh[i][j] = qzh[i - 1][j];
    qzh[i][a1[i]]++;
  }
  for (int i = 0; i < A; i++) {
    int left = max(i - k - 1, -1), right = min(i + k, A - 1);
    for (int j = 0; j < 4; j++)
      if (qzh[right][j] - qzh[left][j] > 0) f[j][i].r = 1.0;
  }
  for (; l < A + B; tmp++, l <<= 1)
    ;
  for (int i = 0; i < l; i++) {
    r[i] = (r[i >> 1] >> 1) | ((i & 1) << (tmp - 1));
    w[i] = c(cos(2 * pi * i / l), sin(2 * pi * i / l));
  }
  for (int j = 0; j < 4; j++) FFT(f[j], 1), FFT(g[j], 1);
  for (int i = 0; i < l; i++)
    for (int j = 0; j < 4; j++) f[j][i] = f[j][i] * g[j][i];
  for (int j = 0; j < 4; j++) FFT(f[j], -1);
  for (int i = 0; i < l; i++)
    for (int j = 0; j < 4; j++) res[i] = res[i] + (int)(f[j][i].r + 0.5);
  int ans = 0;
  for (int i = 0; i < l; i++)
    if (res[i] == B) ans++;
  printf("%d\n", ans);
  return 0;
}
