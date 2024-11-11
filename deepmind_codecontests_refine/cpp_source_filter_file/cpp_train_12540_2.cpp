#include <bits/stdc++.h>
using namespace std;
const int INF = (1LL << 31) - 1;
const long long int LINF = (1LL << 62) - 1;
const int NMAX = 2000 + 5;
const int MMAX = 500 + 5;
const int KMAX = 100000 + 5;
const int PMAX = 100000 + 5;
const int LMAX = 100000 + 5;
const int VMAX = 100000 + 5;
int N, M;
char S[NMAX];
char P[MMAX];
int A[NMAX];
int DP[NMAX][MMAX];
int main() {
  int i, j, k, len;
  scanf("%s", S);
  scanf("%s", P);
  N = strlen(S);
  M = strlen(P);
  for (i = 0; i < N; i++) {
    for (k = 0, len = 0; k < M && i + len < N; len++)
      if (S[i + len] == P[k]) k++;
    if (k < M)
      A[i] = -1;
    else
      A[i] = len;
  }
  for (i = 0; i < N; i++) {
    for (j = 0; j <= i; j++) {
      DP[i + 1][j] = max(DP[i + 1][j], DP[i][j]);
      DP[i + 1][j + 1] = max(DP[i + 1][j + 1], DP[i][j]);
      if (A[i] >= 0)
        DP[i + A[i]][j + A[i] - M] =
            max(DP[i + A[i]][j + A[i] - M], DP[i][j] + 1);
    }
  }
  for (i = 0; i <= N; i++) printf("%d ", DP[N][i]);
  return 0;
}
