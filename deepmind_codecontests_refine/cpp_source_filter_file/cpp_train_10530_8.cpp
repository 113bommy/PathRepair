#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long f = 1, ans = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    ans = ans * 10 + c - '0';
    c = getchar();
  }
  return f * ans;
}
long long N, K, M, tot, U, Cont[1 << 12];
struct Matrix {
  long long A[201][201];
  void init() {
    memset(A, 0, sizeof(A));
    return;
  }
} F, G;
Matrix operator*(Matrix x1, Matrix x2) {
  Matrix x3;
  x3.init();
  for (long long i = 1; i <= tot; i++)
    for (long long j = 1; j <= tot; j++)
      for (long long k = 1; k <= tot; k++)
        x3.A[i][j] += x1.A[i][k] * x2.A[k][j], x3.A[i][j] %= 1000000007;
  return x3;
}
Matrix ksm(Matrix a, long long b) {
  Matrix Ans;
  Ans.init();
  for (long long i = 1; i <= tot; i++) Ans.A[i][i] = 1;
  while (b) {
    if (b & 1) Ans = Ans * a;
    a = a * a;
    b >>= 1;
  }
  return Ans;
}
void print(Matrix F) {
  for (long long i = 1; i <= tot; i++) {
    for (long long j = 1; j <= tot; j++) cerr << F.A[i][j] << " ";
    cerr << endl;
  }
  return;
}
long long Ma[1 << 12][13];
signed main() {
  N = read(), K = read(), M = read();
  U = (1 << M) - 1;
  for (long long i = 1; i <= U; i++) Cont[i] = Cont[i >> 1] + (i & 1);
  for (long long i = 0; i <= U; i++)
    for (long long j = 0; j <= K; j++) Ma[i][j] = (++tot);
  for (long long i = 0; i <= U; i++)
    for (long long j = 0; j <= K; j++) {
      F.A[Ma[i][j]][Ma[(i << 1) & U][j]]++;
      F.A[Ma[i][j]][Ma[(i << 1 | 1) & U][j + 1]] += (Cont[i] + 1);
      F.A[Ma[i][j]][Ma[(i << 1 | 1) & U][j + 1]] %= 1000000007;
      F.A[Ma[i][j]][Ma[(i << 1) & U][j]] %= 1000000007;
    }
  G = ksm(F, N);
  long long res = 0;
  for (long long i = 0; i <= U; i++)
    res += G.A[Ma[0][0]][Ma[i][K]], res %= 1000000007;
  printf("%lld\n", res);
  return 0;
}
