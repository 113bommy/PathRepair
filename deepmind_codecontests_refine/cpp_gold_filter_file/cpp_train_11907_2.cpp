#include <bits/stdc++.h>
using namespace std;
int N, M, A, B;
int D[1000];
double dp[1000][1000];
int main() {
  scanf("%d%d", &N, &M);
  for (int(i) = 0; (i) < (N); (i)++) scanf("%d", &D[i]);
  for (int(i) = 0; (i) < (N); (i)++)
    for (int(j) = 0; (j) < (N); (j)++)
      if (D[i] > D[j]) dp[i][j] = 1;
  while (M--) {
    scanf("%d%d", &A, &B);
    A--, B--;
    for (int(i) = 0; (i) < (N); (i)++)
      if (i != A && i != B) {
        dp[i][A] = dp[i][B] = (dp[i][A] + dp[i][B]) / 2;
        dp[A][i] = dp[B][i] = (dp[A][i] + dp[B][i]) / 2;
      }
    dp[A][A] = dp[B][B] = 0;
    dp[A][B] = dp[B][A] = (dp[A][B] + dp[B][A]) / 2;
  }
  double res = 0;
  for (int(i) = 0; (i) < (N); (i)++)
    for (int(j) = 0; (j) < (i); (j)++) res += dp[j][i];
  printf("%.12f\n", res);
}
