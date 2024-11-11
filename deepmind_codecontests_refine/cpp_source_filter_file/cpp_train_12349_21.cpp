#include <bits/stdc++.h>
using namespace std;
int F[55], S[55];
double P[55];
double dp[55][5005];
const double inf = 0x3f3f3f3f;
int main() {
  int N, R;
  double f, s, p;
  cin >> N >> R;
  for (int i = 1; i <= N; i++) cin >> F[i] >> S[i] >> p, P[i] = p / 100;
  double l = 0, r = 5005;
  double mid;
  for (int k = 1; k < 100; k++) {
    mid = (l + r) / 2;
    for (int t = 1; t <= R; t++) dp[N + 1][t] = t;
    for (int t = R + 1; t < 5005; t++) dp[N + 1][t] = inf;
    for (int i = N; i >= 1; i--)
      for (int t = 0; t < 5005; t++)
        dp[i][t] =
            min(mid + (double)(t + F[i]), dp[i + 1][t + F[i]]) * P[i] +
            min(mid + (double)(t + S[i]), dp[i + 1][t + S[i]]) * (1 - P[i]);
    if (dp[1][0] > mid)
      l = mid;
    else
      r = mid;
  }
  printf("%.9f\n", mid);
}
