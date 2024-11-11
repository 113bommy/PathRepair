#include <bits/stdc++.h>
using namespace std;
struct cpx {
  double r, i;
  cpx(double real = 0.0, double image = 0.0) {
    r = real;
    i = image;
  }
  cpx operator+(cpx a) { return cpx(r + a.r, i + a.i); }
  cpx operator-(cpx a) { return cpx(r - a.r, i - a.i); }
  cpx operator*(cpx a) { return cpx(r * a.r - i * a.i, i * a.r + r * a.i); }
} a[2000005], wn[2000005];
int c1[600005], s1;
int c2[600005], s2;
int res[600005];
long long tp[600005];
char s[1500005];
const double pi = acos(-1.0);
const int mod = 1000;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline void change(cpx y[], int len) {
  int i, j, k;
  for (i = 1, j = (len >> 1); i < len - 1; i++) {
    if (i < j) swap(y[i], y[j]);
    k = (len >> 1);
    while (j >= k) {
      j -= k;
      k >>= 1;
    }
    j += k;
  }
}
inline void fft(cpx y[], int len, int f) {
  int h, i, j;
  wn[0] = cpx(1, 0);
  change(y, len);
  for (h = 2; h <= len; h <<= 1) {
    cpx wo(cos(-2.0 * pi / h), sin(-2.0 * pi / h));
    for (j = 1; j < (h >> 1); j++) wn[j] = wn[j - 1] * wo;
    for (i = 0; i < len; i += h) {
      cpx *a = y + i, *b = y + i + (h >> 1);
      for (j = 0; j < (h >> 1); j++) {
        cpx u = a[j], v = b[j] * wn[j];
        a[j] = u + v;
        b[j] = u - v;
      }
    }
  }
  if (f == -1) {
    for (i = 1; i < (len >> 1); i++) swap(y[i], y[len - i]);
    double o = 1.0 / len;
    for (i = 0; i < len; i++) y[i].r *= o;
  }
}
inline void mul_poly() {
  int sz = s2, len = 1, i, pos = 0;
  while (len < sz + sz) len <<= 1;
  for (i = 0; i < len; i++) a[i] = cpx(c2[i], 0);
  fft(a, len, 1);
  for (i = 0; i < len; i++) a[i] = a[i] * a[i];
  fft(a, len, -1);
  for (i = 0; i < len; i++) tp[i] = ((long long)(a[i].r + 0.5));
  while (len && (!tp[len - 1])) len--;
  while (pos < len || tp[pos]) {
    tp[pos + 1] += tp[pos] / mod;
    c2[pos] = tp[pos] % mod;
    pos++;
  }
  s2 = pos;
}
inline int mul_num(int p) {
  int i, pos = 0;
  res[s2] = 0;
  for (i = 0; i < s2; i++) res[i] = c2[i] * p;
  while (pos < s2 || res[pos]) {
    res[pos + 1] += res[pos] / mod;
    res[pos] %= mod;
    pos++;
  }
  return pos;
}
inline bool cmp(int a[], int b[], int p1, int p2) {
  if (p1 > p2) return true;
  if (p1 < p2) return false;
  for (int i = p1 - 1; i >= 0; i--) {
    if (a[i] > b[i]) return true;
    if (a[i] < b[i]) return false;
  }
  return false;
}
int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1), i, j, o = 1, ans = 233333333, x;
  int pw = (int)(1.0 * n * log(10) / log(3) - 6.0);
  pw = max(pw, 0);
  for (i = n; i >= 1; i -= 3) {
    for (x = 0, j = max(1, i - 2); j <= i; j++) x = x * 10 + (s[j] - '0');
    c1[s1++] = x;
  }
  c2[s2++] = 1;
  while ((1 << (o + 1)) <= pw) o++;
  for (i = o; i >= 0; i--) {
    mul_poly();
    if (pw & (1 << i)) {
      s2 = mul_num(3);
      for (j = 0; j < s2; j++) c2[j] = res[j];
    }
  }
  while (cmp(c1, c2, s1, s2)) {
    int ss = mul_num(2);
    if (!cmp(c1, res, s1, ss)) ans = min(ans, 3 * pw + 2);
    int sk = mul_num(4);
    if (!cmp(c1, res, s1, sk)) ans = min(ans, 3 * pw + 4);
    pw++;
    s2 = mul_num(3);
    for (j = 0; j < s2; j++) c2[j] = res[j];
  }
  ans = min(ans, 3 * pw);
  ans = max(ans, 1);
  printf("%d\n", ans);
  return 0;
}
