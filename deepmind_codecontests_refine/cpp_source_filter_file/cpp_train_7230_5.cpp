#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 19) + 5, M = N, INF = 1e9, mod = 1e9 + 7;
const long long linf = 1e18;
const double eps = 1e-8, pi = acos(-1);
inline int gmin(int &a, int b) {
  if (a > b) a = b;
}
inline long long gmin(long long &a, long long b) {
  if (a > b) a = b;
}
inline int gmax(int &a, int b) {
  if (a < b) a = b;
}
inline long long gmax(long long &a, long long b) {
  if (a < b) a = b;
}
inline int max(int a, int b, int c) {
  if (b > a) a = b;
  if (c > a) a = c;
  return a;
}
inline int max(int a, int b) {
  if (a > b) return a;
  return b;
}
inline int min(int a, int b) {
  if (a > b) return b;
  return a;
}
inline void read(long long &x) {
  long long f = 1, t = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    t = t * 10 + ch - '0';
    ch = getchar();
  }
  x = t * f;
}
inline long long read(long long &x, long long &y) {
  read(x);
  read(y);
}
inline void read(int &x) {
  int f = 1, t = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    t = t * 10 + ch - '0';
    ch = getchar();
  }
  x = t * f;
}
inline int read(int &x, int &y) {
  read(x);
  read(y);
}
inline void read(int &a, int &b, int &c) {
  read(a);
  read(b);
  read(c);
}
inline void read(long long &a, long long &b, long long &c) {
  read(a);
  read(b);
  read(c);
}
inline long long qpow(long long a, long long b, long long p) {
  long long ret = 1;
  for (; b; b >>= 1, a = a * a % p)
    if (b & 1) ret = ret * a % p;
  return ret;
}
inline long long qmul(long long a, long long b, long long p) {
  long long ret = 0;
  for (; b; b >>= 1, a = (a << 1) % p)
    if (b & 1) {
      ret = ret + a;
      if (ret >= p) ret -= p;
    };
  return ret;
}
inline void judge() {
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
}
inline void gen() { freopen("data.in", "w", stdout); }
struct cp {
  double x, y;
  inline cp() {}
  inline cp(double x, double y) : x(x), y(y) {}
  inline cp operator+(const cp &o) { return cp(x + o.x, y + o.y); }
  inline cp operator-(const cp &o) { return cp(x - o.x, y - o.y); }
  inline cp operator*(const cp &o) {
    return cp(x * o.x - y * o.y, x * o.y + y * o.x);
  }
} a[M], b[M];
int n, m, q, kuai, nn;
int ge[100][N], id[N], rev[N], l[N], r[N], h[N], ln;
int b1[30][M / 20], b2[30][M / 20];
char p[M], s[M];
void pre() {
  for (int i = (0); i < (nn); i++)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (ln - 1));
}
void fft(cp *a, int n, int opt) {
  for (int i = (0); i < (n); i++)
    if (i > rev[i]) swap(a[i], a[rev[i]]);
  for (int i = 1; i < n; i <<= 1) {
    cp wn(cos(pi / i), sin(pi / i) * opt);
    for (int j = 0, p = i << 1; j < n; j += p) {
      cp w(1, 0);
      for (int k = (0); k < (i); k++) {
        cp x = a[j + k], y = w * a[i + j + k];
        a[j + k] = x + y;
        a[j + k + i] = x - y;
        w = w * wn;
      }
    }
  }
  if (opt == -1)
    for (int i = (0); i < (n); i++) a[i].x /= n;
}
void merge() {
  fft(a, nn, 1);
  fft(b, nn, 1);
  for (int i = (0); i < (nn); i++) a[i] = a[i] * b[i];
  fft(a, nn, -1);
}
void clear() {
  for (int i = (0); i <= (nn); i++) a[i] = b[i] = cp(0, 0);
}
int calc(int x) { return h[x / (1 << 19)] + h[x % (1 << 19)]; }
int suan(int l1, int r1, int l2, int r2) {
  l1--;
  r1--;
  l2--;
  r2--;
  int a = (30 - l1 % 30) % 30, b = (30 - l2 % 30) % 30;
  int i, j, ans = 0;
  int l = (l1 + a) / 30, r = (r1 + a) / 30;
  int L = (l2 + b) / 30, R = (r2 + b) / 30;
  for (i = l, j = L; i < r; i++, j++) ans += calc(b1[a][i] ^ b2[b][j]);
  for (i = r * 30 - a, j = R * 30 - b; i <= r1; i++, j++)
    ans += p[i + 1] != s[j + 1];
  return ans;
}
void work(int l1, int r1, int l2, int r2) {
  int ans = 0;
  if (id[l2] == id[r2])
    ans += suan(l1, r1, l2, r2);
  else {
    int len = r[id[l2]] - l2;
    ans += suan(l1, l1 + len, l2, l2 + len);
    len = r2 - l[id[r2]];
    ans += suan(r1 - len, r1, r2 - len, r2);
    for (int i = (id[l2] + 1); i <= (id[r2] - 1); i++) {
      int a = l1 + l[i] - l2;
      ans += ge[i][n - a];
    }
  }
  printf("%d\n", ans);
}
void Pre() {
  for (int i = (0); i < (1 << 19); i++) h[i] = h[i] / 2 + (i & 1);
  int _;
  for (int _ = (0); _ <= (29); _++) {
    for (int i = (0); i < (n); i++) {
      int a = i + _;
      b1[_][a / 30] += (p[i + 1] - '0') << (a % 30);
    }
    for (int i = (0); i < (m); i++) {
      int a = i + _;
      b2[_][a / 30] += (s[i + 1] - '0') << (a % 30);
    }
  }
}
int main() {
  scanf("%s%s", p + 1, s + 1);
  n = strlen(p + 1);
  m = strlen(s + 1);
  kuai = 20000;
  for (int i = (1); i <= (m); i++) id[i] = (i - 1) / kuai + 1;
  int j;
  for (int i = 1; i <= m; i = j) {
    for (j = i; j <= m && id[j] == id[i]; j++)
      ;
    int len = j - i + n;
    ln = 0;
    for (nn = 1; nn < len; nn <<= 1) ln++;
    pre();
    clear();
    for (int k = (i); k <= (j - 1); k++) a[k - i].x = s[k] - '0';
    for (int k = (1); k <= (n); k++) b[n - k].x = (p[k] - '0') ^ 1;
    merge();
    for (int k = (0); k <= (nn - 1); k++) ge[id[i]][k] = int(a[k].x + 0.1);
    clear();
    for (int k = (i); k <= (j - 1); k++) a[k - i].x = (s[k] - '0') ^ 1;
    for (int k = (1); k <= (n); k++) b[n - k].x = p[k] - '0';
    merge();
    for (int k = (0); k <= (nn - 1); k++) ge[id[i]][k] += int(a[k].x + 0.1);
    l[id[i]] = i;
    r[id[i]] = j - 1;
  }
  Pre();
  read(q);
  while (q--) {
    int x, y, z;
    read(x, y, z);
    x++;
    y++;
    work(x, x + z - 1, y, y + z - 1);
  }
}
