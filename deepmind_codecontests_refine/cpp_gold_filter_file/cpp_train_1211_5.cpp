#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}
void write(long long x) {
  if (x < 0) x = -x, putchar('-');
  if (x > 10) write(x / 10);
  putchar(x % 10 + '0');
}
long long quickmod(long long x, long long y) {
  long long Ans = 1;
  while (y) {
    if (y & 1) Ans = (Ans * x) % mod;
    x = (x * x) % mod;
    y >>= 1;
  }
  return Ans;
}
long long n;
long long M[105][105], a[105][105];
struct Matirx_Tree {
  long long A[105][105];
  void clear() { memset(A, 0, sizeof A); }
  long long flag;
  long long get_ans() {
    flag = 1;
    for (long long i = 2; i <= n; i++) {
      for (long long j = i + 1; j <= n; j++) {
        if (A[i][i] == 0 && A[j][i]) {
          flag = -flag;
          swap(A[i], A[j]);
          break;
        }
      }
      long long inv = quickmod(A[i][i], mod - 2);
      for (long long j = i + 1; j <= n; j++) {
        long long tmp = A[j][i] * inv % mod;
        for (long long k = 1; k <= n; k++)
          A[j][k] = ((A[j][k] - A[i][k] * tmp) % mod + mod) % mod;
      }
    }
    long long Ans = flag;
    for (long long i = 2; i <= n; i++) Ans = (Ans * A[i][i]) % mod;
    return Ans;
  }
} T;
long long ans[105];
void Gauss() {
  for (long long i = 1; i <= n; i++) {
    for (long long j = i + 1; j <= n; j++) {
      if (a[i][i] == 0 && a[j][i]) {
        swap(a[i], a[j]);
        break;
      }
    }
    long long inv = quickmod(a[i][i], mod - 2);
    for (long long j = i; j <= n + 1; j++) a[i][j] = (a[i][j] * inv) % mod;
    for (long long j = i + 1; j <= n; j++) {
      inv = a[j][i];
      for (long long k = i; k <= n + 1; k++)
        a[j][k] = ((a[j][k] - a[i][k] * inv) % mod + mod) % mod;
    }
  }
  ans[n] = a[n][n + 1];
  for (long long i = n - 1; i >= 1; i--) {
    ans[i] = a[i][n + 1];
    for (long long j = i + 1; j <= n; j++) {
      ans[i] = ((ans[i] - a[i][j] * ans[j]) % mod + mod) % mod;
    }
  }
  for (long long i = 1; i <= n; i++) printf("%lld ", ans[i]);
}
void ADD(long long u, long long v, long long e) {
  T.A[u][u] += e, T.A[v][v] += e;
  T.A[u][v] -= e, T.A[v][u] -= e;
}
signed main() {
  n = read();
  for (long long i = 1; i < n; i++) {
    long long x = read(), y = read();
    M[x][y] = M[y][x] = 1;
  }
  for (long long i = 1; i <= n; i++) {
    a[i][1] = 1;
    for (long long j = 2; j <= n; j++) {
      a[i][j] = (a[i][j - 1] * i) % mod;
    }
  }
  for (long long k = 1; k <= n; k++) {
    T.clear();
    for (long long i = 1; i <= n; i++) {
      for (long long j = i + 1; j <= n; j++) {
        if (M[i][j])
          ADD(i, j, k);
        else
          ADD(i, j, 1);
      }
    }
    a[k][n + 1] = T.get_ans();
  }
  Gauss();
  return 0;
}
