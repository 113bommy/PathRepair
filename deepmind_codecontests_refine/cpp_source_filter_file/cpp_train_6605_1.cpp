#include <bits/stdc++.h>
using namespace std;
const int MAXM = 21;
const int MAXN = 1048576;
int M, N;
long long T, P;
long long e0[MAXN], b[MAXM];
long long comb[MAXM][MAXM];
long long nowmat[MAXM][MAXM], powmat[MAXM][MAXM], tmpmat[MAXM][MAXM];
long long dp1[MAXM][MAXN];
long long ans[MAXN];
void matmul(long long a[MAXM][MAXM], long long b[MAXM][MAXM],
            long long c[MAXM][MAXM]) {
  for (int i = 0; i <= M; i++) {
    for (int j = 0; j <= M; j++) {
      tmpmat[i][j] = 0;
      for (int k = 0; k <= M; k++) {
        tmpmat[i][j] += a[i][k] * b[k][j];
        tmpmat[i][j] %= P;
      }
    }
  }
  for (int i = 0; i <= M; i++)
    for (int j = 0; j <= M; j++) c[i][j] = tmpmat[i][j] % P;
}
long long ncr(int a, int b) {
  if (a < 0 || b < 0 || a < b) return 0;
  return comb[a][b];
}
void make_mat() {
  comb[0][0] = 1;
  for (int i = 1; i < MAXM; i++) {
    comb[i][0] = 1;
    for (int j = 1; j <= i; j++)
      comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % P;
  }
  for (int i = 0; i <= M; i++) {
    for (int j = 0; j <= M; j++) {
      powmat[i][j] = 0;
      int l = max(0, i + j - M), r = min(i, j);
      for (int k = l; k <= r; k++) {
        long long del = (ncr(i, k) * ncr(M - i, j - k)) % P;
        del = (del * b[M - i - j + 2 * k]) % P;
        powmat[i][j] = (powmat[i][j] + del) % P;
      }
    }
  }
  for (int i = 0; i <= M; i++)
    for (int j = 0; j <= M; j++) nowmat[i][j] = (i == j);
  long long rem = T;
  while (rem > 0LL) {
    if (rem & 1LL) matmul(nowmat, powmat, nowmat);
    matmul(powmat, powmat, powmat);
    rem >>= 1;
  }
}
void calc_ans() {
  for (int i = 0; i < N; i++) dp1[0][i] = e0[i];
  for (int j = 1; j <= M; j++) {
    int x = 1 << (j - 1);
    for (int k = j; k >= 1; k--) {
      for (int i = 0; i < N; i++) {
        dp1[k][i] = (dp1[k][i] + dp1[k - 1][i ^ x]) % P;
      }
    }
  }
  for (int i = 0; i < N; i++) {
    ans[i] = 0;
    for (int k = 0; k <= M; k++) {
      ans[i] += dp1[k][i] * nowmat[k][0];
      ans[i] %= P;
    }
  }
}
int main() {
  scanf(
      "%d"
      "%I64d"
      "%I64d",
      &M, &T, &P);
  N = 1 << M;
  for (int i = 0; i < N; i++) {
    scanf("%I64d", &e0[i]);
    e0[i] %= P;
  }
  for (int i = 0; i <= M; i++) {
    scanf("%I64d", &b[i]);
    b[i] %= P;
  }
  make_mat();
  calc_ans();
  for (int i = 0; i < N; i++)
    printf(
        "%I64d"
        "\n",
        ans[i]);
  return 0;
}
