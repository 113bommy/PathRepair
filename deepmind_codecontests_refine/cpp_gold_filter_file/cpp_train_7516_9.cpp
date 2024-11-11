#include <bits/stdc++.h>
using namespace std;
long long int INF = 2e18;
long long int dp[51];
long long int cnt[51];
long long int ans[51];
bool used[51];
long long int mul(long long int a, long long int b) {
  if ((INF / a) < b) {
    return INF;
  } else {
    return a * b;
  }
}
long long int add(long long int a, long long int b) {
  if (INF - a < b) {
    return INF;
  } else {
    return a + b;
  }
}
int main() {
  long long int t;
  cin >> t;
  cnt[2] = 1;
  cnt[1] = 1;
  cnt[0] = 1;
  for (long long int i = 3; i <= 50; i++) {
    cnt[i] = mul(cnt[i - 1], i - 2);
  }
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    dp[n] = 1;
    dp[n + 1] = 1;
    for (int i = 1; i <= n; i++) {
      used[i] = 0;
    }
    for (long long int i = n - 1; i >= 1; i--) {
      dp[i] = 0;
      for (long long int j = i + 1; j <= n + 1; j++) {
        dp[i] = add(dp[i], mul(dp[j], cnt[j - i]));
      }
    }
    if (dp[1] < m) {
      cout << -1 << "\n";
      continue;
    }
    m--;
    for (int i = 1; i <= n; i++) {
      ans[i] = -1;
    }
    for (long long int i = 1; i <= n; i++) {
      for (long long int j = i; j <= n; j++) {
        long long int len = j - i + 1;
        long long int cur = mul(cnt[len], dp[j + 1]);
        if (cur <= m) {
          m = m - cur;
          continue;
        }
        ans[i] = j;
        used[j] = 1;
        for (long long int k = i + 1; k <= j; k++) {
          for (long long int d = i; d <= j; d++) {
            if (k == d || used[d]) {
              continue;
            }
            if (k != j) {
              long long int tmp = ans[d];
              while (tmp != -1 && tmp != k) {
                tmp = ans[tmp];
              }
              if (tmp == k) {
                continue;
              }
            }
            long long int cur = mul(dp[j + 1], cnt[j - k + 1]);
            if (cur <= m) {
              m = m - cur;
              continue;
            }
            ans[k] = d;
            used[d] = 1;
            break;
          }
        }
        i = j;
        break;
      }
    }
    for (int i = 1; i <= n; i++) {
      cout << ans[i] << " ";
    }
    cout << "\n";
  }
}
