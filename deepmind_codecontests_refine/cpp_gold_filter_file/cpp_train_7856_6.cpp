#include <bits/stdc++.h>
using namespace std;
struct px {
  double x, y;
  friend px operator+(px a, px b) {
    px ret;
    ret.x = a.x + b.x;
    ret.y = a.y + b.y;
    return ret;
  }
  friend px operator-(px a, px b) {
    px ret;
    ret.x = a.x - b.x;
    ret.y = a.y - b.y;
    return ret;
  }
  friend px operator*(px a, px b) {
    px ret;
    ret.x = a.x * b.x - a.y * b.y;
    ret.y = a.x * b.y + a.y * b.x;
    return ret;
  }
};
double dft = 2.0, idft = -2.0, pi = acos(-1.0);
int rev[1000002], cc[1000002];
int tmp[1000002], tmm[1000002], pn[1000002], pm[1000002];
int n, m, len, K;
char c1[1000002], c2[1000002];
px a[1000002], b[1000002];
int ans[1000002];
inline int lowbit(int x) { return (x & (-x)); }
inline void chng(int x) {
  if (x <= 0) return;
  for (int i = x; i <= n; i += lowbit(i)) cc[i]++;
}
inline int ask(int x) {
  int ret = 0;
  for (int i = x; i > 0; i -= lowbit(i)) ret += cc[i];
  return ret;
}
void fft(px x[], double mde) {
  for (int i = 0; i < len; i++) {
    if (i < rev[i]) swap(x[i], x[rev[i]]);
  }
  for (int i = 2; i <= len; i <<= 1) {
    px wn;
    wn.x = cos(2.0 * pi / (double)i);
    wn.y = sin(mde * pi / (double)i);
    for (int j = 0, stp = i >> 1; j < len; j += i) {
      px w;
      w.x = 1;
      w.y = 0;
      for (int k = j; k < j + stp; k++) {
        px t1 = x[k], t2 = x[k + stp] * w;
        x[k] = t1 + t2;
        x[k + stp] = t1 - t2;
        w = w * wn;
      }
    }
  }
  if (mde == idft) {
    for (int i = 0; i < len; i++) x[i].x /= (double)len;
  }
}
void solve(char c) {
  for (int i = 1; i <= n; i++) {
    if (c1[i] == c)
      tmp[i] = 1;
    else
      tmp[i] = 0;
  }
  int sum = 0;
  for (int i = 1; i <= m; i++) {
    if (c2[i] == c)
      tmm[i] = 1, sum++;
    else
      tmm[i] = 0;
  }
  memset(cc, 0, sizeof(cc));
  for (int i = 1; i <= n; i++) {
    if (tmp[i]) chng(i);
    int te = ask(i - 1) - ask(i - K - 1);
    if (te) tmp[i] = 1;
  }
  memset(cc, 0, sizeof(cc));
  for (int i = n; i; i--) {
    if (tmp[i]) chng(i);
    int te = ask(min(i + K, n)) - ask(i);
    if (te) tmp[i] = 1;
  }
  for (int i = 1, j = m; i < j; i++, j--) swap(tmm[i], tmm[j]);
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  for (int i = 0; i < n; i++) a[i].x = tmp[i + 1];
  for (int i = 0; i < m; i++) b[i].x = tmm[i + 1];
  fft(a, dft);
  fft(b, dft);
  for (int i = 0; i < len; i++) a[i] = a[i] * b[i];
  fft(a, idft);
  for (int i = m - 1; i < n; i++) ans[i] += sum - (int)(a[i].x + 0.5);
}
int main() {
  scanf("%d%d%d", &n, &m, &K);
  len = 1;
  while (len <= (n << 1)) len <<= 1;
  for (int i = 1; i <= len; i++) {
    rev[i] = rev[i >> 1] >> 1;
    if (i & 1) rev[i] |= len >> 1;
  }
  scanf("%s%s", c1 + 1, c2 + 1);
  solve('A');
  solve('C');
  solve('G');
  solve('T');
  int totans = 0;
  for (int i = m - 1; i < n; i++) {
    if (!ans[i]) totans++;
  }
  printf("%d\n", totans);
}
