#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T read() {
  T f = 0, x = 0;
  char c = getchar();
  while (!isdigit(c)) f = c == '-', c = getchar();
  while (isdigit(c)) x = x * 10 + c - 48, c = getchar();
  return f ? -x : x;
}
namespace run {
const int N = 209, mod = 1e9 + 7, lim = 100;
inline int add(int x, int y) { return x + y >= mod ? x - mod + y : x + y; }
inline int sub(int x, int y) { return x >= y ? x - y : x + mod - y; }
inline int qpow(int x, int y) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = 1LL * x * ret % mod;
    x = 1LL * x * x % mod, y >>= 1;
  }
  return ret;
}
int n;
struct Vector {
  int a[N];
  explicit Vector() { memset(a, 0, sizeof a); }
  inline int &operator[](const int &B) { return a[B]; }
  inline Vector operator*(const int &B) {
    Vector C;
    for (int i = 0; i <= n; i++) C[i] = 1LL * a[i] * B % mod;
    return C;
  }
  inline Vector operator+(const Vector &A) const {
    Vector C;
    for (int i = 0; i <= n; i++) C[i] = add(a[i], A.a[i]);
    return C;
  }
  inline Vector operator-(const Vector &A) const {
    Vector C;
    for (int i = 0; i <= n; i++) C[i] = sub(a[i], A.a[i]);
    return C;
  }
  inline Vector operator+(const int &B) const {
    Vector C;
    for (int i = 0; i <= n; i++) C[i] = a[i];
    C[n] = add(C[n], B);
    return C;
  }
} a[N][N];
inline void print(Vector A) {
  for (int i = 0; i <= n; i++) cout << A[i] << " ";
  cout << endl;
}
namespace Gauss {
int a[N][N], b[N];
inline void Gauss() {
  for (int k = 0; k < n; k++) {
    int pos = k;
    for (int i = k; i < n; i++)
      if (a[i][k]) {
        pos = i;
        break;
      }
    swap(a[pos], a[k]), swap(b[pos], b[k]);
    for (int i = 0; i < n; i++)
      if (i ^ k) {
        int tmp = 1LL * qpow(a[k][k], mod - 2) * a[i][k] % mod;
        for (int j = k; j < n; j++)
          a[i][j] = sub(a[i][j], 1LL * tmp * a[k][j] % mod);
        b[i] = sub(b[i], 1LL * tmp * b[k] % mod);
      }
  }
  for (int i = 0; i < n; i++) b[i] = 1LL * b[i] * qpow(a[i][i], mod - 2) % mod;
}
}  // namespace Gauss
int R, p1, p2, p3, p4;
inline bool check(int x, int y) { return x * x + y * y <= R; }
int main() {
  R = read<int>(), p1 = read<int>(), p2 = read<int>(), p3 = read<int>(),
  p4 = read<int>();
  int sum = add(add(p1, p2), add(p3, p4));
  sum = qpow(sum, mod - 2);
  p1 = 1LL * p1 * sum % mod, p2 = 1LL * sum * p2 % mod,
  p3 = 1LL * sum * p3 % mod, p4 = 1LL * p4 * sum % mod;
  n = 2 * R + 1;
  for (int j = -R; j <= R; j++) {
    int fst = -R;
    while (j * j + fst * fst > R * R) fst++;
    a[fst + R + 1][j + R + 1][j + R] = 1;
  }
  for (int i = -R; i <= R; i++)
    for (int j = -R; j <= R; j++)
      if (check(i, j)) {
        a[i + 1 + R + 1][j + R + 1] =
            a[i + R + 1][j + R + 1] - a[i - 1 + R + 1][j + R + 1] * p1 -
            a[i + R + 1][j - 1 + R + 1] * p2 -
            a[i + R + 1][j + 1 + R + 1] * p4 + (mod - 1);
        a[i + 1 + R + 1][j + R + 1] =
            a[i + 1 + R + 1][j + R + 1] * qpow(p3, mod - 2);
        if (!check(i + 1, j)) {
          for (int k = 0; k < n; k++)
            Gauss::a[j + R][k] = a[i + 1 + R + 1][j + R + 1][k];
          Gauss::b[j + R] = sub(0, a[i + 1 + R + 1][j + R + 1][n]);
        }
      }
  Gauss::Gauss();
  int ans = 0;
  for (int i = 0; i < n; i++)
    ans = (1LL * Gauss::b[i] * a[R + 1][R + 1][i] + ans) % mod;
  printf("%d\n", add(ans, a[R + 1][R + 1][n]));
  return 0;
}
}  // namespace run
int main() { return run::main(); }
