#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1000005;
const long long SQRTN = 1003;
const long long LOGN = 22;
const double PI = acos(-1);
const long long INF = 1e18;
const long long MOD = 1e9 + 7;
const long long FMOD = 998244353;
const double eps = 1e-9;
void __print(long long x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  long long f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
T gcd(T a, T b) {
  if (b == 0) return a;
  a %= b;
  return gcd(b, a);
}
template <typename T>
T lcm(T a, T b) {
  return (a * (b / gcd(a, b)));
}
long long add(long long a, long long b, long long c = MOD) {
  long long res = a + b;
  return (res >= c ? res % c : res);
}
long long mod_neg(long long a, long long b, long long c = MOD) {
  long long res;
  if (abs(a - b) < c)
    res = a - b;
  else
    res = (a - b) % c;
  return (res < 0 ? res + c : res);
}
long long mul(long long a, long long b, long long c = MOD) {
  long long res = (long long)a * b;
  return (res >= c ? res % c : res);
}
long long muln(long long a, long long b, long long c = MOD) {
  long long res = (long long)a * b;
  return ((res % c) + c) % c;
}
long long mulmod(long long a, long long b, long long m = MOD) {
  long long q = (long long)(((long double)a * (long double)b) / (long double)m);
  long long r = a * b - q * m;
  if (r > m) r %= m;
  if (r < 0) r += m;
  return r;
}
template <typename T>
T expo(T e, T n) {
  T x = 1, p = e;
  while (n) {
    if (n & 1) x = x * p;
    p = p * p;
    n >>= 1;
  }
  return x;
}
template <typename T>
T power(T e, T n, T m = MOD) {
  T x = 1, p = e;
  while (n) {
    if (n & 1) x = mul(x, p, m);
    p = mul(p, p, m);
    n >>= 1;
  }
  return x;
}
template <typename T>
T extended_euclid(T a, T b, T &x, T &y) {
  T xx = 0, yy = 1;
  y = 0;
  x = 1;
  while (b) {
    T q = a / b, t = b;
    b = a % b;
    a = t;
    t = xx;
    xx = x - q * xx;
    x = t;
    t = yy;
    yy = y - q * yy;
    y = t;
  }
  return a;
}
template <typename T>
T mod_inverse(T a, T n = MOD) {
  T x, y, z = 0;
  T d = extended_euclid(a, n, x, y);
  return (d > 1 ? -1 : mod_neg(x, z, n));
}
const long long FACSZ = 1e4;
long long fact[FACSZ], ifact[FACSZ];
void precom(long long c = MOD) {
  fact[0] = 1;
  for (long long i = 1; i < FACSZ; i++) fact[i] = mul(fact[i - 1], i, c);
  ifact[FACSZ - 1] = mod_inverse(fact[FACSZ - 1], c);
  for (long long i = FACSZ - 1 - 1; i >= 0; i--) {
    ifact[i] = mul(i + 1, ifact[i + 1], c);
  }
}
long long ncr(long long n, long long r, long long c = MOD) {
  return mul(mul(ifact[r], ifact[n - r], c), fact[n], c);
}
const long long MOD2 = static_cast<long long>(MOD) * MOD;
struct Matrix {
  vector<vector<long long> > mat;
  long long n_rows, n_cols;
  Matrix() {}
  Matrix(vector<vector<long long> > values)
      : mat(values), n_rows(values.size()), n_cols(values[0].size()) {}
  static Matrix identity_matrix(long long n) {
    vector<vector<long long> > values(n, vector<long long>(n, 0));
    for (long long i = 0; i < n; i++) values[i][i] = 1;
    return values;
  }
  Matrix operator*(const Matrix &other) const {
    long long n = n_rows, m = other.n_cols;
    vector<vector<long long> > result(n_rows, vector<long long>(n_cols, 0));
    for (long long i = 0; i < n; i++)
      for (long long j = 0; j < m; j++) {
        long long tmp = 0;
        for (long long k = 0; k < n_cols; k++) {
          tmp += mat[i][k] * 1ll * other.mat[k][j];
          while (tmp >= MOD2) tmp -= MOD2;
        }
        result[i][j] = tmp % MOD;
      }
    return move(Matrix(move(result)));
  }
  inline bool is_square() const { return n_rows == n_cols; }
};
Matrix pw(Matrix a, long long p) {
  Matrix result = Matrix::identity_matrix(a.n_cols);
  while (p > 0) {
    if (p & 1) result = a * result;
    a = a * a;
    p >>= 1;
  }
  return result;
}
void solvethetestcase() {
  string s;
  cin >> s;
  long long n = s.size();
  string ans1[2] = {"11", "13"};
  string ans0[4] = {"21", "22", "23", "24"};
  long long cnt0 = 0;
  long long cnt1 = 0;
  ;
  for (long long i = 0; i < n; i++) {
    if (s[i] == '0') {
      cout << ans1[cnt0 % 4][0] << " " << ans1[cnt0 % 4][1] << "\n";
      cnt0++;
    } else {
      cout << ans0[cnt1 % 2][0] << " " << ans1[cnt1 % 2][1] << "\n";
      cnt1++;
    }
  }
}
signed main() {
  cout << fixed << setprecision(12);
  ;
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  for (long long testcase = 1; testcase < t + 1; testcase++) {
    solvethetestcase();
  }
}
