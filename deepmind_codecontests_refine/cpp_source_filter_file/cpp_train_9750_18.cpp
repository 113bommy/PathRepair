#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int MAXN = (int)2e5 + 5;
struct comp {
  double real, imag;
  comp(double _real = 0, double _imag = 0) : real(_real), imag(_imag) {}
  comp operator+(const comp &a) const {
    return comp(real + a.real, imag + a.imag);
  }
  comp operator-(const comp &a) const {
    return comp(real - a.real, imag - a.imag);
  }
  comp operator*(const comp &a) const {
    return comp(real * a.real - imag * a.imag, real * a.imag + a.real * imag);
  }
};
comp fa[6][MAXN << 2], fb[6][MAXN << 2], res[MAXN << 2];
void fft(comp *a, int n, bool flag) {
  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for (; j >= bit; bit >>= 1) j -= bit;
    j += bit;
    if (i < j) swap(a[i], a[j]);
  }
  for (int len = 2; len <= n; len <<= 1) {
    double ang = 2 * acos(-1.0) / len * (flag ? -1 : 1);
    comp wlen(cos(ang), sin(ang));
    for (int i = 0; i < n; i += len) {
      comp w(1);
      for (int j = 0; j < len / 2; j++) {
        comp u = a[i + j], v = a[i + j + len / 2] * w;
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
        w = w * wlen;
      }
    }
  }
  if (flag)
    for (int i = 0; i < n; i++) a[i].real /= n;
}
char s[MAXN];
char t[MAXN];
int gh[MAXN][5][5];
int ans[MAXN];
int f[10];
int fifa(int a) {
  if (f[a] != a) f[a] = fifa(f[a]);
  return f[a];
}
void cal(int x) {
  for (int i = 0; i < 6; i++) f[i] = i;
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      if (gh[x][i][j]) {
        int u = fifa(i), v = fifa(j);
        if (u != v) {
          ans[x]++;
          f[v] = u;
        }
      }
    }
  }
}
void solve(int la, int lb) {
  int n = 1, ma = la;
  while (n < ma) n <<= 1;
  n <<= 1;
  for (int j = 0; j < 6; j++) {
    for (int i = 0; i < la; i++) fa[j][i] = comp(s[i] - 'a' == j);
    for (int i = la; i < n; i++) fa[j][i] = comp(0);
    for (int i = 0; i < lb; i++) fb[j][i] = comp(t[i] - 'a' == j);
    for (int i = lb; i < n; i++) fb[j][i] = comp(0);
    fft(fa[j], n, 0);
    fft(fb[j], n, 0);
  }
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      if (i == j) continue;
      for (int k = 0; k < n; k++) res[k] = fa[i][k] * fb[j][k];
      fft(res, n, 1);
      for (int k = lb - 1; k < la; k++)
        gh[k - lb + 1][i][j] = (int)(res[k].real + 0.5);
    }
  }
  for (int i = 0; i <= la - lb; i++) cal(i);
}
int n, m;
int main() {
  scanf("%s%s", s, t);
  n = strlen(s);
  m = strlen(t);
  reverse(t, t + m);
  solve(n, m);
  for (int i = 0; i <= n - m; i++) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
