#include <bits/stdc++.h>
using namespace std;
int ans;
int max(int x, int y) { return x > y ? x : y; }
int min(int x, int y) { return x < y ? x : y; }
int abs(int x) { return x > 0 ? x : -x; }
int gcd(int x, int y) { return (!y) ? x : gcd(y, x % y); }
void exgcd(int a, int b, int &d, int &x, int &y) {
  if (!b) {
    d = a, x = 1, y = 0;
  } else {
    exgcd(b, a % b, d, y, x);
    y -= x * (a / b);
  }
}
int quick_power(long long a, int b) {
  long long r = 1;
  for (; b; b >>= 1, a = a * a)
    if (b & 1) r = r * a;
  return r;
}
inline char read() {
  static const int IN_LEN = 1000000;
  static char buf[IN_LEN], *s, *t;
  return (s == t               ? t = (s = buf) + fread(buf, 1, IN_LEN, stdin),
          (s == t ? -1 : *s++) : *s++);
}
template <class T>
inline void read(T &x) {
  static bool iosig;
  static char c;
  for (iosig = false, c = read(); !isdigit(c); c = read()) {
    if (c == '-') iosig = true;
    if (c == -1) return;
  }
  for (x = 0; isdigit(c); c = read()) x = x * 10 + (c ^ '0');
  if (iosig) x = -x;
}
char sr[10000000], z[20];
int C = -1, Z = 0;
void Ot() { fwrite(sr, 1, C + 1, stdout), C = -1; }
void print(int x) {
  if (x < 0) sr[++C] = '-', x = -x;
  while (z[++Z] = x % 10 + 48, x /= 10)
    ;
  while (sr[++C] = z[Z], --Z)
    ;
  sr[++C] = ' ';
}
const int N = 400400;
struct p {
  double x, y;
  p operator+(const p &a) const { return (p){x + a.x, y + a.y}; }
  p operator-(const p &a) const { return (p){x - a.x, y - a.y}; }
  p operator*(const p &a) const {
    return (p){x * a.x - y * a.y, x * a.y + y * a.x};
  }
} a[N], b[N];
int c[N], R[N], vis[N / 2][6][6], fa[10];
char s[N], t[N];
int num = 1, l = 0;
int n;
int find(int x) { return fa[x] = fa[x] == x ? x : find(fa[x]); }
void FFT(p *a, int f) {
  for (int i = 0; i < num; i++)
    if (i < R[i]) swap(a[i], a[R[i]]);
  for (int i = 1; i < num; i <<= 1) {
    p wn = {cos(3.14159265358979323846264 / i),
            f * sin(3.14159265358979323846264 / i)};
    for (int j = 0; j < num; j += (i << 1)) {
      p w = {1, 0};
      for (int k = 0; k < i; ++k, w = w * wn) {
        p x = a[j + k], y = w * a[j + k + i];
        a[j + k] = x + y;
        a[j + k + i] = x - y;
      }
    }
  }
}
int L;
int main() {
  scanf("%s", s);
  scanf("%s", t);
  int lens = strlen(s), lent = strlen(t);
  while (num <= lens + lent) num <<= 1, l++;
  for (int i = 0; i <= num - 1; i++) {
    R[i] = (R[i >> 1] >> 1) | ((i & 1) << (l - 1));
  }
  for (int i = 0; i <= 5; i++) {
    for (int j = 0; j <= 5; j++) {
      for (int k = 0; k <= num - 1; k++) a[k].x = a[k].y = b[k].x = b[k].y = 0;
      for (int k = 0; k <= lens - 1; k++)
        if (s[k] == 'a' + i) a[k].x = 1;
      for (int k = 0; k <= lent - 1; k++)
        if (t[lent - k - 1] == 'a' + j) b[k].x = 1;
      FFT(a, 1), FFT(b, 1);
      for (int k = 0; k <= num - 1; k++) a[k] = a[k] * b[k];
      FFT(a, -1);
      for (int k = 0; k <= num - 1; k++)
        vis[k][i][j] = (int)(a[k].x / num + 0.3);
    }
  }
  for (int i = lent - 1; i <= lens - 1; i++) {
    for (int j = 0; j <= 5; j++) fa[j] = j;
    for (int j = 0; j <= 5; j++)
      for (int k = 0; k <= 5; k++)
        if (vis[i][j][k]) fa[find(j)] = find(k);
    ans = 0;
    for (int j = 0; j <= 5; j++)
      if (find(j) != j) ans += 1;
    print(ans);
  }
  Ot();
  return 0;
}
