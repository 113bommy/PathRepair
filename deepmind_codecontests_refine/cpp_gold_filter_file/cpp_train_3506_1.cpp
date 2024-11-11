#include <bits/stdc++.h>
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline void sub(long long &a, long long b) {
  a -= b;
  if (a < 0) a += 1000000007;
}
inline void add(long long &a, long long b) {
  a += b;
  if (a >= 1000000007) a -= 1000000007;
}
template <typename T>
inline T const &MAX(T const &a, T const &b) {
  return a > b ? a : b;
}
template <typename T>
inline T const &MIN(T const &a, T const &b) {
  return a < b ? a : b;
}
inline long long qp(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % 1000000007;
    a = a * a % 1000000007, b >>= 1;
  }
  return ans;
}
inline long long qp(long long a, long long b, long long c) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % c;
    a = a * a % c, b >>= 1;
  }
  return ans;
}
using namespace std;
const unsigned long long ba = 233;
const double eps = 1e-5;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int N = 400000 + 10, maxn = 1000000 + 10, inf = 0x3f3f3f3f;
struct cd {
  double x, y;
  cd(double _x = 0.0, double _y = 0.0) : x(_x), y(_y) {}
  cd operator+(const cd &b) const { return cd(x + b.x, y + b.y); }
  cd operator-(const cd &b) const { return cd(x - b.x, y - b.y); }
  cd operator*(const cd &b) const {
    return cd(x * b.x - y * b.y, x * b.y + y * b.x);
  }
  cd operator/(const double &b) const { return cd(x / b, y / b); }
} x[N << 3];
int rev[N << 3];
void getrev(int bit) {
  for (int i = 0; i < (1 << bit); i++)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
}
void fft(cd *a, int n, int dft) {
  for (int i = 0; i < n; i++)
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  for (int step = 1; step < n; step <<= 1) {
    cd wn(cos(dft * acos(-1.0) / step), sin(dft * acos(-1.0) / step));
    for (int j = 0; j < n; j += step << 1) {
      cd wnk(1, 0);
      for (int k = j; k < j + step; k++) {
        cd x = a[k];
        cd y = wnk * a[k + step];
        a[k] = x + y;
        a[k + step] = x - y;
        wnk = wnk * wn;
      }
    }
  }
  if (dft == -1)
    for (int i = 0; i < n; i++) a[i] = a[i] / n;
}
int a[N], b[N];
long long ans[N];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1, y; i <= n; i++) {
    scanf("%d", &y);
    a[i] = y < k;
    a[i] += a[i - 1];
    b[a[i]]++;
  }
  b[0]++;
  for (int i = 0; i <= n; i++) x[i] = b[i], x[i + 2 * n + 1] = b[n - i];
  int sz = 1;
  while ((1 << sz) <= n * 3 + 2) sz++;
  sz++;
  getrev(sz);
  fft(x, (1 << sz), 1);
  for (int i = 0; i < (1 << sz); i++) x[i] = x[i] * x[i];
  fft(x, (1 << sz), -1);
  for (int i = 3 * n + 1; i <= 4 * n + 2; i++)
    ans[i - 3 * n - 1] = (long long)((x[i].x + 0.5) / 2);
  ans[0] = 0;
  for (int i = 0; i <= n; i++) ans[0] += 1LL * b[i] * (b[i] - 1) / 2;
  for (int i = 0; i <= n; i++) printf("%lld ", ans[i]);
  puts("");
  return 0;
}
