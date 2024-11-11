#include <bits/stdc++.h>
const int MAXN = 20;
int N, K;
double P[MAXN];
double DP[MAXN][1 << MAXN];
double Ans[MAXN];
void Work() {
  scanf("%d%d", &N, &K);
  int Nonzeros = 0;
  for (int i = 0; i < N; i++) {
    scanf("%lf", &P[i]);
    if (P[i] > 0) Nonzeros++;
  }
  if (Nonzeros < K) Nonzeros = K;
  for (int i = 0; i < N; i++) DP[0][1 << i] = P[i];
  for (int i = 0; i < K - 1; i++)
    for (int Mask = 0; Mask < (1 << N); Mask++) {
      if (DP[i][Mask] == 0) continue;
      double Z = 0;
      for (int j = 0; j < N; j++)
        if ((Mask & (1 << j)) == 0) Z += P[j];
      if (Z == 0) Z = 1;
      for (int j = 0; j < N; j++)
        if ((Mask & (1 << j)) == 0)
          DP[i + 1][Mask | (1 << j)] += (P[j] / Z) * DP[i][Mask];
    }
  for (int Mask = 0; Mask < (1 << N); Mask++)
    for (int j = 0; j < N; j++)
      if (Mask & (1 << j)) Ans[j] += DP[K - 1][Mask];
  for (int j = 0; j < N - 1; j++) printf("%.10lf ", Ans[j]);
  printf("%.10lf\n", Ans[N - 1]);
}
int main() {
  Work();
  return 0;
}
