#include <bits/stdc++.h>
using namespace std;
int N, M, i, j, data[5005], dp[5005], final;
double x;
int main() {
  scanf("%d %d", &N, &M);
  for (i = 1; i <= N; ++i) {
    scanf("%d %lf", &data[i], &x);
  }
  final = 1;
  for (i = 1; i <= N; ++i) {
    dp[i] = 1;
    for (j = 1; j < i; ++j) {
      if (data[j] >= data[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
      final = max(final, dp[i]);
    }
  }
  printf("%d\n", N - final);
  return 0;
}
