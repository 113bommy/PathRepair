#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9;
const int N = 1 << 18;
int n, m;
long long f[N];
long long Q0[2 * N];
long long Q1[2 * N];
long long A[2][2], B[2][2], C[2][2];
void add(long long* q, int pos, long long x) {
  pos += N;
  long long t = q[pos];
  while (pos) {
    q[pos] = (q[pos] + x) % MOD;
    q[pos] = (q[pos] - t + MOD) % MOD;
    pos >>= 1;
  }
}
long long sum(long long* q, int L, int R) {
  long long res = 0;
  for (L += N, R += N; L < R; L >>= 1, R >>= 1) {
    if (L & 1) res = (res + q[L++]) % MOD;
    if (R & 1) res = (res + q[--R]) % MOD;
  }
  return res;
}
int main() {
  f[0] = 1, f[1] = 1;
  for (int i = 2; i < 1 << 18; ++i) f[i] = (f[i - 1] + f[i - 2]) % MOD;
  scanf("%d%d", &n, &m);
  memset(Q0, 0, sizeof(Q0));
  memset(Q1, 0, sizeof(Q1));
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    long long add0 = (f[i] * x) % MOD;
    add(Q0, i, add0);
    long long add1 = (f[i + 1] * x) % MOD;
    add(Q1, i, add1);
  }
  for (int i = 0; i < m; ++i) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int pos;
      int v;
      scanf("%d%d", &pos, &v);
      pos--;
      long long add0 = (f[pos] * v) % MOD;
      add(Q0, pos, add0);
      long long add1 = (f[pos + 1] * v) % MOD;
      add(Q1, pos, add1);
    } else {
      int L, R;
      scanf("%d%d", &L, &R);
      long long b = (sum(Q0, 0, R) - sum(Q0, 0, L - 1) + MOD) % MOD;
      long long a = (sum(Q1, 0, R) - sum(Q1, 0, L - 1) + MOD) % MOD;
      A[0][0] = 0;
      A[1][0] = 1;
      A[0][1] = 1;
      A[1][1] = -1;
      int p = L - 1;
      C[0][0] = 1;
      C[0][1] = 0;
      C[1][0] = 0;
      C[1][1] = 1;
      while (p) {
        if (p & 1) {
          memset(B, 0, sizeof(B));
          for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
              for (int k = 0; k < 2; ++k)
                B[i][j] = (B[i][j] + C[i][k] * A[k][j]) % MOD;
          for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j) C[i][j] = B[i][j];
        }
        p >>= 1;
        memset(B, 0, sizeof(B));
        for (int i = 0; i < 2; ++i)
          for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
              B[i][j] = (B[i][j] + A[i][k] * A[k][j]) % MOD;
        for (int i = 0; i < 2; ++i)
          for (int j = 0; j < 2; ++j) A[i][j] = B[i][j];
      }
      long long res = a * C[0][1] % MOD;
      res = (res + b * C[1][1] % MOD) % MOD;
      printf("%d\n", (int)res);
    }
  }
  return 0;
}
