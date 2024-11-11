#include <bits/stdc++.h>
using namespace std;
int n, k, A[405], S[405], M[405];
int DP1[405][55], DP2[405][55], DP[405][55];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &A[i]);
    S[i] = S[i - 1] + A[i];
  }
  for (int i = 0; i <= n; i++)
    for (int j = 1; j <= k; j++) {
      DP1[i][j] = 0x3f3f3f3f;
      DP2[i][j] = -0x3f3f3f3f;
      DP[i][j] = -0x3f3f3f3f;
    }
  for (int i = 1; i <= n; i++) {
    DP1[i][1] = DP1[i - 1][1];
    DP2[i][1] = DP2[i - 1][1];
    for (int j = 1; j <= i; j++) {
      DP1[i][1] = min(DP1[i][1], -(S[i] - S[j - 1]));
      DP2[i][1] = max(DP2[i][1], S[i] - S[j - 1]);
    }
  }
  for (int i = 2; i <= n; i++)
    for (int so_far = 2; so_far <= k && so_far <= i; so_far++) {
      DP1[i][so_far] = DP1[i - 1][so_far];
      DP2[i][so_far] = DP2[i - 1][so_far];
      DP[i][so_far] = DP[i - 1][so_far];
      for (int j = 2; j <= i; j++)
        if (j >= so_far) {
          int best = max(DP1[j - 1][so_far - 1] + (S[i] - S[j - 1]),
                         DP2[j - 1][so_far - 1] - (S[i] - S[j - 1]));
          DP[i][so_far] = max(DP[i][so_far], best);
          DP1[i][so_far] = min(DP1[i][so_far], best - (S[i] - S[j - 1]));
          DP2[i][so_far] = max(DP2[i][so_far], best + (S[i] - S[j - 1]));
        }
    }
  printf("%d\n", DP[n][k]);
  return 0;
}
