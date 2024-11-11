#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int logmaxn = 20;
const long long inf = numeric_limits<long long>::max() / 10;
long long dp[2][4], ans = inf;
int A[maxn], b, a, n;
void flush(int i) {
  for (auto j : {0, 1, 2, 3}) {
    dp[i][j] = inf;
  }
}
long long test(int factor) {
  int u, v, rem;
  memset(dp, 0, sizeof dp);
  for (int i = 1; i <= n; ++i) {
    rem = A[i] % factor;
    v = i & 1;
    u = v ^ 1;
    flush(i);
    if (rem == 1 || rem == factor - 1) {
      dp[v][0] = dp[u][0] + b;
      dp[v][1] = min(dp[u][3], dp[u][1]) + b;
    } else if (rem == 0) {
      dp[v][0] = dp[u][0];
      dp[v][1] = min(dp[u][1], dp[u][3]);
    }
    dp[v][3] = min(dp[u][0], dp[u][3]) + a;
    for (auto j : {0, 1, 2, 3}) {
      dp[v][j] = min(dp[v][j], inf);
    }
  }
  long long res = inf;
  for (auto j : {0, 1, 2, 3}) {
    res = min(dp[n][j], res);
  }
  return res;
}
void solve() {
  int opt[] = {A[1], A[1] + 1, A[1] - 1, A[n], A[n] + 1, A[n] - 1};
  for (auto num : opt) {
    for (int i = 2; i * i <= num; ++i) {
      if (num % i == 0) {
        ans = min(ans, test(i));
        while (num % i == 0) num /= i;
      }
    }
    if (num > 1) {
      ans = min(ans, test(num));
    }
  }
}
int main() {
  scanf("%d %d %d", &n, &a, &b);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", A + i);
  }
  if (n == 1) {
    if (A[1] == 1) {
      cout << b;
    } else {
      cout << 0;
    }
    return 0;
  }
  solve();
  cout << ans;
  return 0;
}
