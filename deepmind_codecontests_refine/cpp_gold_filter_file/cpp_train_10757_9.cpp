#include <bits/stdc++.h>
using namespace std;
char A[2005], B[2005];
int p[2005], r[2][2];
const int MOD = 1000000007;
int main(void) {
  int k, n;
  scanf("%s%s", A, B);
  n = strlen(A);
  scanf("%d", &k);
  for (int i = 0; i < n; i++) A[n + i] = A[i];
  for (int i = 0; i < n; i++)
    if (strncmp(A + i, B, n) == 0) p[i] = 1;
  int S = 0, T = 0;
  for (int i = 0; i < n; i++)
    if (p[i])
      ++S;
    else
      ++T;
  r[0][0] = max(0, S - 1);
  r[0][1] = max(0, S);
  r[1][0] = max(0, T);
  r[1][1] = max(0, T - 1);
  int X = (p[0] == 1), Y = (p[0] == 0);
  while (k > 0) {
    if (k % 2) {
      int U = (r[0][0] * 1LL * X + r[0][1] * 1LL * Y) % MOD;
      int V = (r[1][0] * 1LL * X + r[1][1] * 1LL * Y) % MOD;
      X = U;
      Y = V;
    }
    int tmp[2][2] = {};
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++)
        for (int s = 0; s < 2; s++)
          tmp[i][j] = (tmp[i][j] + 1LL * r[i][s] * r[s][j]) % MOD;
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++) r[i][j] = tmp[i][j];
    k /= 2;
  }
  printf("%d\n", X);
  return 0;
}
