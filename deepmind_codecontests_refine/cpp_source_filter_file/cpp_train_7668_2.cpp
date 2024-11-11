#include <bits/stdc++.h>
const int N = 60;
long long a[N], b[N];
long long dp[2][N];
std::pair<long long, long long> p[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
    a[i] *= 1000;
  }
  for (int j = 0; j < n; ++j) {
    scanf("%lld", &b[j]);
  }
  long long left = 1, right = 1e4;
  while (left < right) {
    long long mid = left + right >> 1;
    for (int i = 0; i < n; ++i) {
      p[i] = {a[i], a[i] - mid * b[i]};
    }
    std::sort(p, p + n);
    int pre = 0;
    for (int i = 0; i < N; ++i) {
      dp[0][i] = LLONG_MIN;
    }
    dp[0][0] = 0;
    int now = 0;
    for (int i = 0; i < n; ++i) {
      if (i == n - 1 || p[i].first < p[i + 1].first) {
        for (int i = 0; i < N; ++i) {
          dp[now ^ 1][i] = LLONG_MIN;
        }
        int cnt = i - pre + 1;
        for (int j = 0; j < N; ++j) {
          if (dp[now][j] == LLONG_MIN) continue;
          for (int k = 0; k <= cnt; ++k) {
            long long sum = dp[now][j];
            for (int u = pre; u < pre + k; ++u) {
              sum += p[u].second;
            }
            long long &u = dp[now ^ 1][std::max(0, j - k) + cnt - k];
            if (u == LLONG_MIN || u > sum) {
              u = sum;
            }
          }
        }
        pre = i + 1;
        now ^= 1;
      }
    }
    if (dp[now][0] <= 0) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  printf("%lld\n", left);
  return 0;
}
