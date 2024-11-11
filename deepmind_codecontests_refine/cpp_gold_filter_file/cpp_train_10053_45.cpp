#include <bits/stdc++.h>
using namespace std;
int N, A, B;
double P[2005], Q[2005], F[2005][2005];
int G[2005][2005];
pair<double, int> DP(double x) {
  int i, j, mn = 1 << 30;
  double t, mx = -1e9;
  for (i = 1; i <= N; i++)
    for (j = 0; j <= A; j++) {
      F[i][j] = F[i - 1][j], G[i][j] = G[i - 1][j];
      if (j && (t = F[i - 1][j - 1] + P[i]) > F[i][j])
        F[i][j] = t, G[i][j] = G[i - 1][j - 1];
      else if (j && fabs(t - F[i][j]) < 1e-7)
        G[i][j] = min(G[i][j], G[i - 1][j - 1]);
      if ((t = F[i - 1][j] + Q[i] - x) > F[i][j])
        F[i][j] = t, G[i][j] = G[i - 1][j] + 1;
      else if (fabs(t - F[i][j]) < 1e-7)
        G[i][j] = min(G[i][j], G[i - 1][j] + 1);
      if (j && (t = F[i - 1][j - 1] + P[i] + Q[i] - P[i] * Q[i] - x) > F[i][j])
        F[i][j] = t, G[i][j] = G[i - 1][j - 1] + 1;
      else if (j && fabs(t - F[i][j]) < 1e-7)
        G[i][j] = min(G[i][j], G[i - 1][j - 1] + 1);
    }
  for (i = 0; i <= A; i++)
    if (F[N][i] > mx)
      mx = F[N][i], mn = G[N][i];
    else if (fabs(F[N][i] - mx) < 1e-7)
      mn = min(mn, G[N][i]);
  return {mx, mn};
}
int main() {
  int i;
  double l = 0, r = 1, mid;
  scanf("%d%d%d", &N, &A, &B);
  for (i = 1; i <= N; i++) scanf("%lf", &P[i]);
  for (i = 1; i <= N; i++) scanf("%lf", &Q[i]);
  while (r - l > 1e-9) {
    mid = (l + r) / 2;
    DP(mid).second > B ? l = mid : r = mid;
  }
  printf("%lf\n", DP(l).first + B * l);
  DP(0.16);
  return 0;
}
