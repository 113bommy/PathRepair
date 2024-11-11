#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
const int MAXN = 3e5 + 10;
const int MAXM = 1e4 + 500;
const int N = 5000 + 15;
const double EPS = 1e-9;
double len(complex<long long> a) {
  return sqrt(a.real() * a.real() + a.imag() * a.imag());
}
long long sq(complex<long long> a) {
  return a.real() * a.real() + a.imag() * a.imag();
}
complex<long long> perp(complex<long long> p) { return {-p.imag(), p.real()}; }
long long dotProduct(complex<long long> a, complex<long long> b) {
  return (conj(a) * b).real();
}
long long crossProduct(complex<long long> a, complex<long long> b) {
  return (conj(a) * b).imag();
}
long long orient(complex<long long> a, complex<long long> b,
                 complex<long long> c) {
  return crossProduct(b - a, c - a);
}
bool inDisk(complex<long long> a, complex<long long> b, complex<long long> p) {
  return dotProduct(a - p, b - p) <= 0;
}
bool onSegment(complex<long long> a, complex<long long> b,
               complex<long long> p) {
  return orient(a, b, p) == 0 && inDisk(a, b, p);
};
struct cmpX {
  bool operator()(complex<long long> a, complex<long long> b) {
    return make_pair(a.real(), a.imag()) < make_pair(b.real(), b.imag());
  }
};
struct line {
  complex<long long> v;
  long long c;
  line(complex<long long> v, long long c) : v(v), c(c) {}
  line(long long a, long long b, long long c) : v({b, -a}), c(c) {}
  line(complex<long long> p, complex<long long> q)
      : v(q - p), c(crossProduct(v, p)) {}
  long long side(complex<long long> p) { return crossProduct(v, p) - c; }
  double dist(complex<long long> p) { return abs(side(p)) / len(v); }
  line perpThrough(complex<long long> p) { return {p, p + perp(v)}; }
  bool cmpProj(complex<long long> p, complex<long long> q) {
    return dotProduct(v, p) < dotProduct(v, q);
  }
  line translate(complex<long long> t) { return {v, c + crossProduct(v, t)}; }
  complex<long long> proj(complex<long long> p) {
    return p - perp(v) * side(p) / sq(v);
  }
};
double segPoint(complex<long long> a, complex<long long> b,
                complex<long long> p) {
  if (a != b) {
    line l(a, b);
    if (l.cmpProj(a, p) && l.cmpProj(p, b)) return l.dist(p);
  }
  return min(abs(p - a), abs(p - b));
}
bool inAngle(complex<long long> a, complex<long long> b, complex<long long> c,
             complex<long long> p) {
  if (orient(a, b, c) < 0) swap(b, c);
  return orient(a, b, p) >= 0 && orient(a, c, p) <= 0;
}
bool isInsidePol(vector<complex<long long> > &a, complex<long long> b) {
  int n = a.size();
  int pos = 0, neg = 0;
  for (int i = 0; i < n - 1; i++) {
    if (onSegment(a[i], a[(i + 1) % n], b)) return false;
    line l(a[i], a[i + 1]);
    if (l.side(b) > 0)
      pos++;
    else
      neg++;
  }
  line l(a[n - 1], a[0]);
  if (l.side(b) > 0)
    pos++;
  else
    neg++;
  return ((!pos && neg == n) || (!neg && pos == n));
}
long long i, j, k;
long long n, m;
long long binpow(long long val, long long deg) {
  if (!deg) return 1;
  if (deg & 1) return binpow(val, deg - 1) * val % MOD;
  long long res = binpow(val, deg >> 1);
  return (res * res) % MOD;
}
long long inv(long long a, long long m) { return binpow(a, m - 2); }
long long add(long long a, long long b) { return (a += b) < MOD ? a : a - MOD; }
long long mul(long long a, long long b) { return a * b % MOD; }
long long cleverMulMod(long long a, long long b) {
  if (b == 0) return 0;
  long long s = cleverMulMod(a, b / 2);
  if (b % 2 == 1)
    return (a % MOD + 2ll * (s % MOD)) % MOD;
  else
    return (2ll * (s % MOD)) % MOD;
}
class Matrix {
 public:
  vector<vector<long long> > A;
  int dim;
  Matrix(int n) : dim(n) { A.assign(n, vector<long long>(n)); }
  vector<long long> &operator[](int n) { return A[n]; }
};
Matrix operator*(Matrix A, Matrix B) {
  int n = A.dim;
  Matrix C(n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++) {
        C[i][j] = add(C[i][j], mul(A[i][k], B[k][j]));
      }
  return C;
}
Matrix operator^(Matrix A, long long k) {
  int n = A.dim;
  Matrix R(n);
  for (int i = 0; i < n; i++) R[i][i] = 1;
  while (k > 0) {
    if (k % 2) R = R * A;
    A = A * A;
    k /= 2;
  }
  return R;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long loops;
  cin >> loops;
  long long maxCanBeLoops = 38;
  if (loops > maxCanBeLoops) {
    cout << -1 << endl;
    return 0;
  }
  long long full = loops / 2;
  long long rem = loops % 2;
  while (full--) {
    cout << 8;
  }
  while (rem--) {
    cout << 4;
  }
  return 0;
}
