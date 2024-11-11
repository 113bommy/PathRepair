#include <bits/stdc++.h>
using namespace std;
int N;
long long a[1000100];
long long dp[1000100][2];
int unext[1000100];
int dnext[1000100];
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%lld", &a[i]);
  int prev = -(1 << 30), prevat = 0;
  a[N] = -(1 << 30);
  for (int i = 0; i <= N; i++) {
    if (prev < a[i]) {
      prev = a[i];
    } else {
      for (int j = prevat; j <= i; j++) {
        unext[j] = i;
      }
      prevat = i;
      prev = a[i];
    }
  }
  prev = (1 << 30), prevat = 0;
  a[N] = (1 << 30);
  for (int i = 0; i <= N; i++) {
    if (prev > a[i]) {
      prev = a[i];
    } else {
      for (int j = prevat; j <= i; j++) {
        dnext[j] = i;
      }
      prevat = i;
      prev = a[i];
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        dp[unext[i]][k] =
            max(dp[unext[i]][k], dp[i][j] + abs(a[unext[i] - 1] - a[i]));
        if (unext[i] - 2 >= 0 && unext[i] - 1 != i) {
          dp[unext[i] - 1][k] =
              max(dp[unext[i] - 1][k], dp[i][j] + abs(a[unext[i] - 2] - a[i]));
        }
        dp[dnext[i]][k] =
            max(dp[dnext[i]][k], dp[i][j] + abs(a[dnext[i] - 1] - a[i]));
        if (dnext[i] - 2 >= 0 && dnext[i] - 1 != i) {
          dp[dnext[i] - 1][k] =
              max(dp[dnext[i] - 1][k], dp[i][j] + abs(a[dnext[i] - 2] - a[i]));
        }
      }
    }
  }
  printf("%lld\n", max(dp[N][0], dp[N][1]));
}
