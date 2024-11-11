#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
void pre() {}
void solve() {}
struct base {
  double x, y;
  base() { x = y = 0; }
  base(double _x, double _y) { x = _x, y = _y; }
  base(double _x) { x = _x, y = 0; }
  void operator=(double _x) { x = _x, y = 0; }
  double real() { return x; }
  double imag() { return y; }
  base operator+(const base& b) { return base(x + b.x, y + b.y); }
  void operator+=(const base& b) { x += b.x, y += b.y; }
  base operator*(const base& b) {
    return base(x * b.x - y * b.y, x * b.y + y * b.x);
  }
  void operator*=(const base& b) {
    double p = x * b.x - y * b.y, q = x * b.y + y * b.x;
    x = p, y = q;
  }
  void operator/=(double k) { x /= k, y /= k; }
  base operator-(const base& b) { return base(x - b.x, y - b.y); }
  void operator-=(const base& b) { x -= b.x, y -= b.y; }
  base conj() { return base(x, -y); }
  base operator/(double k) { return base(x / k, y / k); }
  void Print() { cerr << x << " + " << y << "i\n"; }
};
double PI = 2.0 * acos(0.0);
const int MAXN = 19;
const int maxn = (1 << MAXN);
base W[maxn], invW[maxn], P1[maxn], Q1[maxn];
void precompute_powers() {
  for (int i = 0; i < maxn / 2; i++) {
    double ang = (2 * PI * i) / maxn;
    double _cos = cos(ang), _sin = sin(ang);
    W[i] = base(_cos, _sin);
    invW[i] = base(_cos, -_sin);
  }
}
void fft(vector<base>& a, bool invert) {
  int n = (int)a.size();
  for (int i = 1, j = 0; i < n; ++i) {
    int bit = n >> 1;
    for (; j >= bit; bit >>= 1) j -= bit;
    j += bit;
    if (i < j) swap(a[i], a[j]);
  }
  for (int len = 2; len <= n; len <<= 1) {
    for (int i = 0; i < n; i += len) {
      int ind = 0, add = maxn / len;
      for (int j = 0; j < len / 2; ++j) {
        base u = a[i + j],
             v = (a[i + j + len / 2] * (invert ? invW[ind] : W[ind]));
        a[i + j] = (u + v);
        a[i + j + len / 2] = (u - v);
        ind += add;
      }
    }
  }
  if (invert)
    for (int i = 0; i < n; ++i) a[i] /= n;
}
void mul_big_mod(vector<long long>& a, vector<long long>& b, long long mod) {
  int n1 = a.size(), n2 = b.size();
  int final_size = a.size() + b.size() - 1;
  int n = 1;
  while (n < final_size) n <<= 1;
  vector<base> P(n), Q(n);
  int SQRTMOD = (int)sqrt(mod) + 10;
  for (int i = 0; i < n1; i++) P[i] = base(a[i] % SQRTMOD, a[i] / SQRTMOD);
  for (int i = 0; i < n2; i++) Q[i] = base(b[i] % SQRTMOD, b[i] / SQRTMOD);
  fft(P, 0);
  fft(Q, 0);
  base A1, A2, B1, B2, X, Y;
  for (int i = 0; i < n; i++) {
    X = P[i];
    Y = P[(n - i) % n].conj();
    A1 = (X + Y) * base(0.5, 0);
    A2 = (X - Y) * base(0, -0.5);
    X = Q[i];
    Y = Q[(n - i) % n].conj();
    B1 = (X + Y) * base(0.5, 0);
    B2 = (X - Y) * base(0, -0.5);
    P1[i] = A1 * B1 + A2 * B2 * base(0, 1);
    Q1[i] = A1 * B2 + A2 * B1;
  }
  for (int i = 0; i < n; i++) P[i] = P1[i], Q[i] = Q1[i];
  fft(P, 1);
  fft(Q, 1);
  a.resize(final_size);
  for (int i = 0; i < final_size; i++) {
    long long x = (long long)(P[i].real() + 0.5);
    long long y = (long long)(P[i].imag() + 0.5) % mod;
    long long z = (long long)(Q[i].real() + 0.5);
    a[i] = (x + ((y * SQRTMOD + z) % mod) * SQRTMOD) % mod;
  }
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(cin.failbit);
  pre();
  precompute_powers();
  int n, x;
  cin >> n >> x;
  int ans = 0, p = 0;
  vector<long long> v;
  for (int i = 0; i < (n); ++i) {
    int z;
    cin >> z;
    if (z >= x)
      p++;
    else {
      ans += 1ll * p * (p + 1) / 2;
      v.push_back(p + 1);
      p = 0;
    }
  }
  ans += 1ll * p * (p + 1) / 2;
  v.push_back(p + 1);
  cout << ans << ' ';
  vector<long long> v2 = v;
  int nn = (int)(v).size();
  reverse(v.begin(), v.end());
  mul_big_mod(v, v2, 40000000003ll);
  for (int i = 0; i < (n); ++i) {
    if (nn + i < (int)(v).size())
      cout << v[nn + i] << ' ';
    else
      cout << 0 << ' ';
  }
  return 0;
}
