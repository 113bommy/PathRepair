#include <bits/stdc++.h>
using namespace std;
int s, t, K;
char bx[200011], bt[200011];
char rec(int a) {
  if (a == 0)
    return 'A';
  else if (a == 1)
    return 'C';
  else if (a == 2)
    return 'T';
  else if (a == 3)
    return 'G';
}
bool canf[200011][4];
struct cplx {
  double x, y;
  cplx() {}
  cplx(double _x, double _y) {
    x = _x;
    y = _y;
  }
  cplx operator+(const cplx &a) const { return cplx(x + a.x, y + a.y); }
  cplx operator-(const cplx &a) const { return cplx(x - a.x, y - a.y); }
  cplx operator*(const cplx &a) const {
    return cplx(x * a.x - y * a.y, x * a.y + y * a.x);
  }
};
const double pi = acos(-1.0);
cplx _g[30], _ig[30];
void init() {
  for (int i = 0; i < 30; i++) {
    _g[i] = cplx(cos(-pi / (1 << i)), sin(-pi / (1 << i)));
    _ig[i] = cplx(cos(pi / (1 << i)), sin(pi / (1 << i)));
  }
}
void FFT(cplx F[], int len, int f) {
  int i, j, k, cnt = 0;
  cplx x, y, w = cplx(1, 0), wn;
  for (i = 1, j = len >> 1; i < len - 1; i++) {
    if (i < j) swap(F[i], F[j]);
    k = len >> 1;
    while (j >= k) j ^= k, k >>= 1;
    j |= k;
  }
  for (i = 1; i < len; i <<= 1) {
    wn = f == 1 ? _g[cnt++] : _ig[cnt++];
    for (j = 0; j < len; j += i << 1, w = cplx(1, 0))
      for (k = j; k < j + i; k++, w = w * wn) {
        x = F[k];
        y = w * F[k + i];
        F[k] = x + y;
        F[k + i] = x - y;
      }
  }
  if (f == -1)
    for (i = 0; i < len; i++) F[i].x /= len;
}
cplx a[800000], b[800000];
void conv(int ca[], int l1, int cb[], int l2, int c[], int &l) {
  l = 1;
  while (l < l1 + l2) l <<= 1;
  init();
  for (int i = 0; i < l; i++) {
    a[i] = i < l1 ? cplx(ca[i], 0) : cplx(0, 0);
    b[i] = i < l2 ? cplx(cb[i], 0) : cplx(0, 0);
  }
  FFT(a, l, 1);
  FFT(b, l, 1);
  for (int i = 0; i < l; i++) a[i] = a[i] * b[i];
  FFT(a, l, -1);
  for (int i = 0; i < l; i++) c[i] = a[i].x + 0.5;
}
int a1[800000], a2[800000], ans[800000], f_ans[800000];
int main() {
  scanf("%d%d%d", &s, &t, &K);
  scanf("%s", bx);
  scanf("%s", bt);
  int len = strlen(bx);
  int m = strlen(bt);
  for (int i = 0; i < 4; i++) {
    char a = rec(i);
    int pr = 0;
    for (int j = 0; j < len; j++) {
      if (bx[j] == a) {
        int l = max(j - K, 0);
        int r = min(j + K, len - 1);
        l = max(pr, l);
        if (pr > r)
          continue;
        else {
          for (int k = l; k <= r; k++) {
            canf[k][i] = 1;
          }
          pr = r + 1;
        }
      }
    }
  }
  for (int i = 0; i < 4; i++) {
    memset(a1, 0, sizeof(a1));
    memset(a2, 0, sizeof(a2));
    for (int j = 0; j < len; j++) {
      if (canf[j][i]) a1[j] = 1;
    }
    for (int j = 0; j < m; j++) {
      if (bt[j] == rec(i)) {
        a2[m - j - 1] = 1;
      }
    }
    int ll;
    conv(a1, len, a2, m, ans, ll);
    for (int j = 0; j < ll; j++) {
      f_ans[j] += ans[j];
    }
  }
  int ff = 0;
  for (int j = 0; j < len + m; j++) {
    if (f_ans[j] == m) ff++;
  }
  printf("%d\n", ff);
  return 0;
}
