#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (!b) {
    x = 1, y = 0;
    return a;
  }
  long long g = exgcd(b, a % b, x, y), t = x;
  x = y, y = t - a / b * y;
  return g;
}
long long mypow(long long a, long long n) {
  long long ans = 1;
  a %= mod;
  for (long long i = n; i; i >>= 1, a = a * a % mod)
    if (i & 1) ans = ans * a % mod;
  return ans;
}
const int maxn = 110, maxp = 2010;
int p[maxp], pn;
int a[maxn][maxp], b[maxn][maxp], n;
bool init() {
  static int u[maxn], v[maxn];
  scanf("%d", &n), pn = 0;
  for (int i = 1, x, y; i <= n; ++i) {
    scanf("%d%d", u + i, v + i);
    for (x = u[i], y = 2; y <= x / y; ++y)
      if (x % y == 0)
        for (p[++pn] = y; x % y == 0; x /= y)
          ;
    if (x != 1) p[++pn] = x;
    for (x = v[i], y = 2; y <= x / y; ++y)
      if (x % y == 0)
        for (p[++pn] = y; x % y == 0; x /= y)
          ;
    if (x != 1) p[++pn] = x;
  }
  if (n == 1) {
    printf("%d\n", u[1]);
    return true;
  }
  sort(p + 1, p + pn + 1), pn = unique(p + 1, p + pn + 1) - p - 1;
  memset(a, 0, sizeof(a)), memset(b, 0, sizeof(b));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= pn; ++j)
      while (u[i] % p[j] == 0) ++b[i][j], u[i] /= p[j];
    for (int j = 1; j <= pn; ++j)
      while (v[i] % p[j] == 0) ++a[i][j], v[i] /= p[j];
  }
  return false;
}
struct equation {
  long long A, B, C;
  equation() : A(0), B(0), C(0) {}
  equation(long long newA, long long newB, long long newC)
      : A(newA), B(newB), C(newC) {}
};
bool empty(equation &t) {
  if (!t.A && !t.B) return t.C;
  long long g = gcd(abs(t.A), abs(t.B));
  if (t.C % g) return true;
  t.A /= g, t.B /= g, t.C /= g;
  return false;
}
int merge(equation p, equation q, long long &x, long long &y) {
  long long D = p.A * q.B - p.B * q.A;
  x = p.C * q.B - q.C * p.B, y = p.A * q.C - p.C * q.A;
  if (D) {
    if (x % D || y % D) {
      x = -1, y = -1;
      return -1;
    }
    x /= D, y /= D;
    return +1;
  }
  if (x || y) {
    x = -1, y = -1;
    return -1;
  }
  return 0;
}
long long check(long long x) {
  if (x < 0) return -1;
  for (int i = 2; i <= n; ++i) {
    vector<long long> s;
    s.clear();
    for (int u = 1; u <= pn; ++u) {
      long long z = a[1][u] * x + b[1][u] - b[i][u];
      if (a[i][u]) {
        if (z % a[i][u]) return -1;
        s.push_back(z / a[i][u]);
      } else if (z)
        return -1;
    }
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    if (s.size() > 1 || (s.size() == 1 && s.front() < 0)) return -1;
  }
  long long ans = 1;
  for (int i = 1; i <= pn; ++i)
    ans = ans * mypow(p[i], a[1][i] * x + b[1][i]) % mod;
  return ans;
}
void solve() {
  long long x = 0, y = 0;
  bool find = false;
  for (int i = 2; !find && i <= n; ++i)
    for (int u = 1; !find && u <= pn; ++u) {
      equation p(a[1][u], -a[i][u], b[i][u] - b[1][u]);
      if (empty(p)) {
        puts("-1");
        return;
      }
      if (!p.B && p.A) {
        x = p.C / p.A, find = true;
        break;
      }
      for (int v = u + 1; v <= pn; ++v) {
        equation q(a[1][v], -a[i][v], b[i][v] - b[1][v]);
        int t = merge(p, q, x, y);
        if (t == +1) {
          find = true;
          break;
        }
        if (t == -1) {
          puts("-1");
          return;
        }
      }
    }
  if (find) {
    printf("%I64d\n", check(x));
    return;
  }
  static long long c[maxn], d[maxn];
  int m = 0;
  long long minx = 0;
  for (int i = 2; i <= n; ++i) {
    for (int u = 1; u <= pn; ++u)
      if (a[1][u]) {
        long long A = a[1][u], B = a[i][u], C = b[i][u] - b[1][u];
        long long g = exgcd(A, B, x, y);
        ++m;
        minx = max(minx, (long long)ceil(1.0 * C / A));
        c[m] = (C / g) * x % B, d[m] = B / g;
        break;
      }
  }
  for (int i = 2; i <= m; ++i) {
    long long A = d[1], B = d[i], C = c[i] - c[1];
    long long g = exgcd(A, B, x, y);
    if (C % g) {
      puts("-1");
      return;
    }
    x = x * (C / g) % B;
    c[1] = c[1] + x * A, d[1] = A / g * B;
    c[1] %= d[1];
    if (c[1] < 0) c[1] += d[1];
  }
  c[1] += ceil(1.0 * (minx - c[1]) / d[1]);
  printf("%I64d\n", check(c[1]));
}
int main() {
  if (!init()) solve();
  return 0;
}
