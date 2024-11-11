#include <bits/stdc++.h>
long long S, N, K, x, F[2005], W[2005];
int main() {
  scanf("%I64d%I64d", &N, &K);
  for (int i = 1; i <= N; i++)
    for (int j = i + 1; j <= N; j++) {
      scanf("%I64d", &x);
      S += x < 0 ? 0 : x;
      if (x >= 0) {
        F[i] += x, F[j] += x, W[i]++, W[j]++;
      }
    }
  if (K != 2)
    printf("%I64d", 2 * S / N);
  else {
    S = 0;
    for (int i = 1; i <= N; i++) S += F[i] * (W[i] - 1);
    printf("%I64d", 2 * S / N / (N - 1));
  }
}
