#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, size = 1 << 20, mod = 998244353;
template <class o>
void qr(o &x) {
  char c = getchar();
  x = 0;
  int f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  x *= f;
}
template <class o>
void qw(o x) {
  if (x / 10) qw(x / 10);
  putchar(x % 10 + '0');
}
template <class o>
void pr1(o x) {
  if (x < 0) x = -x, putchar('-');
  qw(x);
  putchar(' ');
}
template <class o>
void pr2(o x) {
  if (x < 0) x = -x, putchar('-');
  qw(x);
  puts("");
}
long long mult(long long a, long long b, long long p) {
  a = (a % p + p) % p;
  b = (b % p + p) % p;
  long long c = (long double)a * b / p;
  return a * b - c * p;
}
long long gcd(long long a, long long b) { return !a ? b : gcd(b % a, a); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long power(long long a, long long b = mod - 2) {
  long long c = 1;
  while (b) {
    if (b & 1) c = c * a % mod;
    b /= 2;
    a = a * a % mod;
  }
  return c;
}
long long Power(long long a, long long b = mod - 2) {
  long long c = 1;
  while (b) {
    if (b & 1) c = mult(c, a, mod);
    b /= 2;
    a = mult(a, a, mod);
  }
  return c;
}
int n, k;
map<pair<int, int>, int> s;
int m;
vector<double> v[N];
double a[N], ans;
int cnt;
int main() {
  qr(n);
  qr(k);
  for (int i = 1, x, y, d; i <= n; i++) {
    qr(x);
    qr(y);
    if (!x && !y) continue;
    d = gcd(abs(x), abs(y));
    pair<int, int> t = make_pair(x / d, y / d);
    if (!s.count(t)) s[t] = ++m;
    int id = s[t];
    v[id].push_back(sqrt(1.0 * x * x + 1.0 * y * y));
  }
  a[++cnt] = 0;
  for (int i = 1; i <= m; i++) {
    sort(v[i].begin(), v[i].end(), greater<double>());
    int l = 0, r = ((int)v[i].size()) - 1;
    double sr = 0;
    while (l <= r) {
      double left = v[i][l] * (k - 1 - 2 * l) - sr;
      double right = v[i][r] * (k - 1 - 2 * l) - sr;
      if (left >= right)
        l++, a[++cnt] = left;
      else
        sr += v[i][r--], a[++cnt] = right;
    }
  }
  sort(a + 1, a + cnt + 1, greater<double>());
  for (int i = 1; i <= k; i++) ans += a[i];
  printf("%.10lf\n", ans);
  return 0;
}
