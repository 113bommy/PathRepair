#include <bits/stdc++.h>
using namespace std;
const int Mod = 1000000007;
struct node {
  long long A[31][31];
  node() {}
  friend node operator*(node x, node y) {
    node z;
    memset(z.A, 0, sizeof(z.A));
    for (int i = 0; i <= 30; i++)
      for (int j = 0; j <= 30; j++)
        for (int k = 0; k <= 30; k++)
          z.A[i][j] = (z.A[i][j] + x.A[i][k] * y.A[k][j]) % Mod;
    return z;
  }
} one;
node F[70][31], Pre[70][31], Suf[70][31];
long long N;
int K;
int lg;
int A[70], Alen = 0;
int main() {
  scanf("%I64d%d", &N, &K);
  lg = 0;
  long long x = N;
  while (x) x /= K, lg++;
  memset(one.A, 0, sizeof(one.A));
  for (int i = 0; i <= K; i++) one.A[i][i] = 1;
  for (int i = 0; i < K; i++) {
    F[lg][i] = one;
    for (int j = 0; j <= K; j++) F[lg][i].A[j][i] = 1;
  }
  Pre[lg][0] = F[lg][0];
  for (int i = 1; i < K; i++) Pre[lg][i] = Pre[lg][i - 1] * F[lg][i];
  Suf[lg][K] = one;
  for (int i = K - 1; i >= 0; i--) Suf[lg][i] = F[lg][i] * Suf[lg][i + 1];
  for (int k = lg - 1; k >= 1; k--) {
    for (int i = 0; i < K; i++)
      if (i > 0)
        F[k][i] = Suf[k + 1][i] * Pre[k + 1][i - 1];
      else
        F[k][i] = Suf[k + 1][i];
    Pre[k][0] = F[k][0];
    for (int i = 1; i < K; i++) Pre[k][i] = Pre[k][i - 1] * F[k][i];
    Suf[k][K] = one;
    for (int i = K - 1; i >= 0; i--) Suf[k][i] = F[k][i] * Suf[k][i + 1];
  }
  Alen = 0;
  x = N;
  while (x) {
    A[++Alen] = x % K;
    x /= K;
  }
  node Ans = one;
  int k = 0;
  int s = 0;
  for (int i = Alen; i >= 1; i--) {
    x = A[i];
    for (int o = 0; o < x; o++) Ans = Ans * F[k + 1][(s + o) % K];
    k++;
    (s += A[i]) %= K;
  }
  int ss = 0;
  for (int i = 0; i <= K; i++) ss = (ss + Ans.A[K][i]) % Mod;
  return printf("%d\n", ss), 0;
}
