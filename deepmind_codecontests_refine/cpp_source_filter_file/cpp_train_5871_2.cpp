#include <bits/stdc++.h>
using namespace std;
template <class T>
inline string DISPLAYBIT(T n, int s, int e) {
  string a;
  while (s >= e) {
    if (s < sizeof(n) * CHAR_BIT)
      ((sizeof(n) == 4) && (((n) & (1 << (s))) != 0)) ||
              ((sizeof(n) == 8) && (((n) & (((long long)(1)) << (s))) != 0))
          ? a += '1'
          : a += '0';
    s--;
  }
  return a;
}
template <class T>
inline int COUNTBIT(T n) {
  return (sizeof(n) == 4) ? __builtin_popcount(n) : __builin_popcountl(n);
}
template <class T>
inline int LSB(T n) {
  return (sizeof(n) == 4) ? __builtin_ffs(n) - 1 : __builtin_ffsl(n) - 1;
}
template <class T>
inline int MSB(T n) {
  return (sizeof(n) == 4) ? 31 - __builtin_clz(n) : 63 - __builtin_clzl(n);
}
template <class T>
inline T GCD(T a, T b) {
  if (a < 0) return GCD(-a, b);
  if (b < 0) return GCD(a, -b);
  return (b == 0) ? a : GCD(b, a % b);
}
template <class T>
inline T LCM(T a, T b) {
  if (a < 0) return LCM(-a, b);
  if (b < 0) return LCM(a, -b);
  return a * (b / GCD(a, b));
}
template <class T>
inline T EUCLIDEAN(T a, T b, T& x, T& y) {
  if (a < 0) {
    T d = EUCLIDEAN(-a, b, x, y);
    x = -x;
    return d;
  }
  if (b < 0) {
    T d = EUCLIDEAN(a, -b, x, y);
    y = -y;
    return d;
  }
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    T d = EUCLIDEAN(b, a % b, x, y);
    T t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
  }
}
template <class T>
inline vector<pair<T, int> > FACTORISE(T n) {
  vector<pair<T, int> > R;
  for (T i = 2; n > 1;) {
    if (n % i == 0) {
      int C = 0;
      for (; n % i == 0; C++, n /= i)
        ;
      R.push_back(make_pair(i, C));
    }
    i++;
    if (i > n / i) i = n;
  }
  if (n > 1) R.push_back(make_pair(n, 1));
  return R;
}
template <class T>
inline vector<pair<int, int> > FACTORIZE(int n) {
  if (n > 1e7) return FACTORISE(n);
  vector<pair<int, int> > R;
  vector<int> a(({
    int b = ceil(sqrt(n));
    vector<int> d(n, 0);
    vector<int> e;
    int f = 2;
    e.push_back(2);
    e.push_back(3);
    for (int x = 1; x < b + 1; x++) {
      for (int y = 1; y < b + 1; y++) {
        int n = (4 * x * x) + (y * y);
        if (n <= n && (n % 12 == 1 || n % 12 == 5)) {
          d[n] ^= 1;
        }
        n = (3 * x * x) + (y * y);
        if (n <= n && n % 12 == 7) {
          d[n] ^= 1;
        }
        n = (3 * x * x) - (y * y);
        if (x > y && n <= n && n % 12 == 11) {
          d[n] ^= 1;
        }
      }
    }
    for (int r = 5; r < b + 1; r++) {
      if (d[r]) {
        for (int i = r * r; i < n; i += (r * r)) {
          d[i] = 0;
        }
      }
    }
    for (int c = 5; c < n; c++) {
      if (d[c]) {
        e.push_back(c);
      }
    }
    e;
  }));
  int i;
  if (a[({
        int z = (lower_bound((a).begin(), (a).end(), n) - (a).begin());
        (z == 0 && a[0] != n) ? -1 : z;
      })] == n) {
    R.push_back(make_pair(n, 1));
    return R;
  }
  int b = (int)sqrt(n);
  for (i = 0; a[i] <= b; i++) {
    if (n % a[i] == 0) {
      int d = 0;
      for (; n % a[i] == 0; d++, n /= a[i])
        ;
      R.push_back(make_pair(a[i], d));
    }
  }
  for (; a[i] < n; i++) {
    if (n % a[i] == 0) {
      R.push_back(make_pair(a[i], 1));
      break;
    }
  }
  return R;
}
template <class T>
inline bool IZPRIME(T n) {
  if (n <= 1) return false;
  for (T i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
template <class T>
inline bool ISPRIME(T n) {
  if (n > 1e7) return IZPRIME(n);
  vector<int> a(({
    int b = ceil(sqrt(n));
    vector<int> d(n, 0);
    vector<int> e;
    int f = 2;
    e.push_back(2);
    e.push_back(3);
    for (int x = 1; x < b + 1; x++) {
      for (int y = 1; y < b + 1; y++) {
        int n = (4 * x * x) + (y * y);
        if (n <= n && (n % 12 == 1 || n % 12 == 5)) {
          d[n] ^= 1;
        }
        n = (3 * x * x) + (y * y);
        if (n <= n && n % 12 == 7) {
          d[n] ^= 1;
        }
        n = (3 * x * x) - (y * y);
        if (x > y && n <= n && n % 12 == 11) {
          d[n] ^= 1;
        }
      }
    }
    for (int r = 5; r < b + 1; r++) {
      if (d[r]) {
        for (int i = r * r; i < n; i += (r * r)) {
          d[i] = 0;
        }
      }
    }
    for (int c = 5; c < n; c++) {
      if (d[c]) {
        e.push_back(c);
      }
    }
    e;
  }));
  int b = ({
    int z = (lower_bound((a).begin(), (a).end(), n) - (a).begin());
    (z == 0 && a[0] != n) ? -1 : z;
  });
  return (b != -1 && a[b] == n);
}
template <class T>
inline T TOTIENT(T n) {
  vector<pair<T, int> > R = FACTORIZE(n);
  T r = n;
  for (int i = 0; i < R.size(); i++) r = r / R[i].first * (R[i].first - 1);
  return r;
}
template <class T>
inline T CHECKMOD(T n, T m) {
  return (n % m + m) % m;
}
template <class T>
inline T MULTIPLYMOD(T a, T b, T m) {
  return (
      T)((((long long)(a) * (long long)(b) % (long long)(m)) + (long long)(m)) %
         (long long)(m));
}
template <class T>
inline T DIVIDEMOD(T a, T b, T m) {
  T x, y;
  EUCLIDEAN(b, m, x, y);
  return MULTIPLYMOD(a, x, m);
}
template <class T>
inline T POWERMOD(T p, int e, T m) {
  if (e == 0)
    return 1 % m;
  else if (e % 2 == 0) {
    T t = POWERMOD(p, e / 2, m);
    return MULTIPLYMOD(t, t, m);
  } else
    return MULTIPLYMOD(POWERMOD(p, e - 1, m), p, m);
}
template <class T>
inline void SHOWMATRIX(vector<vector<T> >& A) {
  for (int i = 0; i < ((int)(A).size()); i++) {
    for (int j = 0; j < ((int)(A[0]).size()); j++) cout << A[i][j] << " ";
    cout << endl;
  }
}
template <class T>
inline void COPYMATRIX(int m, int n, vector<vector<T> >& A,
                       vector<vector<T> >& B) {
  B.clear();
  B.resize(n - m + 1, vector<T>(n - m + 1));
  for (int i = m, k = 0; i <= n; i++, k++) {
    for (int j = m, l = 0; j <= n; j++, l++) B[k][l] = A[i][j];
  }
}
template <class T>
inline void IDENTITYMATRIX(int n, vector<vector<T> >& A) {
  A.clear();
  A.resize(n, vector<T>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) A[i][j] = (i == j) ? 1 : 0;
}
template <class T, class BinaryOperation>
inline void CHECKMATRIX(vector<vector<T> > A, vector<vector<T> > B,
                        vector<vector<T> >& C, BinaryOperation b) {
  int n = ((int)(A).size());
  C.clear();
  C.resize(((int)(A).size()), vector<T>(((int)(A).size())));
  for (int i = 0; i < ((int)(A).size()); i++)
    for (int j = 0; j < ((int)(A[0]).size()); j++)
      C[i][j] = b(A[i][j], B[i][j]);
}
template <class T>
inline void mulMatrix(vector<vector<T> > A, vector<vector<T> > B,
                      vector<vector<T> >& C) {
  C.clear();
  C.resize(((int)(A).size()), vector<T>(((int)(B[0]).size())));
  for (int i = 0; i < ((int)(A).size()); i++)
    for (int j = 0; j < ((int)(B[0]).size()); j++)
      for (int k = 0; k < ((int)(B).size()); k++) C[i][j] += A[i][k] * B[k][j];
}
template <class T>
inline void TRANSMATRIX(vector<vector<T> >& B, vector<vector<T> >& A) {
  B.clear();
  B.resize(((int)(A[0]).size()), vector<T>(((int)(A).size())));
  for (int i = 0; i < ((int)(B).size()); i++) {
    for (int j = 0; j < ((int)(B[0]).size()); j++) B[i][j] = A[j][i];
  }
}
template <class T, class BinaryOperation>
inline void SCALARMATRIX(vector<vector<T> >& B, vector<vector<T> >& A, T c,
                         BinaryOperation d) {
  B.clear();
  B.resize(((int)(A[0]).size()), vector<T>(((int)(A).size())));
  for (int i = 0; i < ((int)(B).size()); i++) {
    for (int j = 0; j < ((int)(B[0]).size()); j++) B[i][j] = d(A[j][i], c);
  }
}
template <class T>
inline string TOSTRING(T n) {
  ostringstream ost;
  ost << n;
  ost.flush();
  return ost.str();
}
template <class T>
inline void TOVAR(string s, T& r) {
  istringstream sin(s);
  sin >> r;
}
template <class T>
inline void STOV(string s, vector<T>& vi) {
  vi.clear();
  istringstream sin(s);
  for (T v; sin >> v; vi.push_bakc(v))
    ;
}
template <class T>
inline void VTOS(vector<T> vi, string& s) {
  ostringstream sout;
  for (int i = 0; i < vi.size(); i++) {
    if (i > 0) sout << ' ';
    sout << vi[i];
  }
  s = sout.str();
}
template <class T>
inline vector<T> ATOV(T a[]) {
  vector<T> v(a, a + sizeof(a) / sizeof(T));
  return v;
}
template <class T>
struct Fraction {
  T a, b;
  Fraction(T a = 0, T b = 1);
  string toString();
};
template <class T>
Fraction<T>::Fraction(T a, T b) {
  T d = GCD(a, b);
  a /= d;
  b /= d;
  if (b < 0) a = -a, b = -b;
  this->a = a;
  this->b = b;
}
template <class T>
string Fraction<T>::toString() {
  ostringstream sout;
  sout << a << "/" << b;
  return sout.str();
}
template <class T>
Fraction<T> operator+(Fraction<T> p, Fraction<T> q) {
  return Fraction<T>(p.a * q.b + q.a * p.b, p.b * q.b);
}
template <class T>
Fraction<T> operator-(Fraction<T> p, Fraction<T> q) {
  return Fraction<T>(p.a * q.b - q.a * p.b, p.b * q.b);
}
template <class T>
Fraction<T> operator*(Fraction<T> p, Fraction<T> q) {
  return Fraction<T>(p.a * q.a, p.b * q.b);
}
template <class T>
Fraction<T> operator/(Fraction<T> p, Fraction<T> q) {
  return Fraction<T>(p.a * q.b, p.b * q.a);
}
int main() {
  double tmp_start = clock();
  fprintf(stderr, "Start\n");
  int n = ({
    int x;
    scanf("%d", &x);
    x;
  });
  int neg = 0, val = (int)1e9, sum = 0;
  vector<int> a;
  for (int i = 0; i < 2 * n - 1; i++) {
    int t = ({
      int x;
      scanf("%d", &x);
      x;
    });
    sum += (abs(t));
    val = min(val, abs(t));
    if (t < 0) neg++;
  }
  if (neg & 1 && neg > n)
    cout << sum - 2 * val << endl;
  else
    cout << sum << endl;
  fprintf(stderr, "Total time = %.2lf sec\n",
          (double)(clock() - tmp_start) / CLOCKS_PER_SEC);
  return 0;
}
