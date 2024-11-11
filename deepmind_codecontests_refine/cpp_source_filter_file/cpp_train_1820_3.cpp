#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T first, T second) {
  while (second > 0) {
    first %= second;
    swap(first, second);
  }
  return first;
}
template <class _T>
inline _T sqr(const _T &first) {
  return first * first;
}
template <class _T>
inline string tostr(const _T &a) {
  ostringstream os("");
  os << a;
  return os.str();
}
const long double PI = 3.1415926535897932384626433832795L;
template <typename T>
inline void input(T &a) {
  static int c;
  a = 0;
  while (!isdigit(c = getchar()) && c != '-') {
  }
  char neg = 0;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  while (isdigit(c)) {
    a = 10 * a + c - '0';
    c = getchar();
  }
  if (neg) a = -a;
}
template <typename T = int>
inline T nxt() {
  T res;
  input(res);
  return res;
}
long long mod = 1000000007;
long long many = 7 * mod;
const int N = 111;
struct matrix {
  long long u[N][N];
  matrix() { memset((u), 0, sizeof(u)); }
};
void operator*=(matrix &l, const matrix &r) {
  matrix res;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < N; ++k) {
        res.u[i][j] += l.u[i][k] * r.u[k][j];
        if (res.u[i][j] >= many) {
          res.u[i][j] -= many;
        }
      }
      res.u[i][j] %= mod;
    }
  }
  memcpy(l.u, res.u, sizeof(res.u));
}
void pw(matrix a, matrix &res, int n) {
  for (int i = 0; i < N; ++i) {
    res.u[i][i] = 1;
  }
  while (n) {
    if (n & 1) {
      res *= a;
    }
    a *= a;
    n >>= 1;
  }
}
int main() {
  int n = nxt();
  int first = nxt();
  int d[n];
  for (int i = 0; i < n; ++i) {
    d[i] = nxt();
  }
  matrix M;
  for (int i = 0; i < n; ++i) {
    M.u[0][d[i] - 1]++;
  }
  const int K = 101;
  for (int i = 1; i < K; ++i) {
    M.u[i][i - 1] = 1;
  }
  M.u[K + 1][K + 1] = 1;
  M.u[0][K + 1] = 1;
  matrix X;
  pw(M, X, first);
  long long ans = X.u[0][K + 1] + X.u[0][0];
  ans %= mod;
  cout << ans << "\n";
  return 0;
}
