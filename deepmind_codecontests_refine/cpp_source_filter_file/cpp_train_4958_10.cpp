#include <bits/stdc++.h>
using namespace std;
long long int n, k, a[100010], ans = 0, inf = 1e9 + 7;
long long int dp[30][100010], f[1001][1001];
inline long long int COST_sub1(long long int L, long long int R) {
  long long int res = 0, x;
  for (auto i = 1; i <= n; ++i) {
    x = f[R][i] - f[L - 1][i];
    res += x * (x - 1) / 2;
  }
  return res;
}
void sub1() {
  for (auto i = 1; i <= n; ++i) {
    for (auto j = 1; j <= n; ++j) {
      f[i][j] = f[i - 1][j];
    }
    f[i][a[i]]++;
  }
  for (auto i = 1; i <= n; ++i)
    for (auto j = 1; j <= k; ++j) dp[j][i] = inf;
  for (auto i = 1; i <= n; ++i) dp[1][i] = COST_sub1(1, i);
  for (auto j = 2; j <= k; ++j) {
    for (auto i = j; i <= n; ++i) {
      for (auto l = 1; l <= i; ++l) {
        dp[j][i] = min(dp[j][i], COST_sub1(l, i) + dp[j - 1][l - 1]);
      }
    }
  }
  cout << dp[k][n];
}
long long int cost[1001][1001];
long long int first = 1, last = 0, total = 0, cnt[100010];
inline long long int COST_sub2(long long int L, long long int R) {
  while (first > L) {
    first--;
    total += cnt[a[first]];
    cnt[a[first]]++;
  }
  while (L > first) {
    cnt[a[first]]--;
    total -= cnt[a[first]];
    first++;
  }
  while (R < last) {
    cnt[a[last]]--;
    total -= cnt[a[last]];
    last--;
  }
  while (R > last) {
    last++;
    total += cnt[a[last]];
    cnt[a[last]]++;
  }
  return total;
}
void sub2() {
  for (auto R = 1; R <= n; ++R)
    for (auto L = 1; L <= R; ++L) cost[L][R] = COST_sub2(L, R);
  for (auto i = 1; i <= n; ++i)
    for (auto j = 1; j <= k; ++j) dp[j][i] = inf;
  for (auto i = 1; i <= n; ++i) dp[1][i] = cost[1][i];
  for (auto j = 2; j <= k; ++j) {
    for (auto i = j; i <= n; ++i) {
      for (auto l = 1; l <= i; ++l) {
        dp[j][i] = min(dp[j][i], cost[l][i] + dp[j - 1][l - 1]);
      }
    }
  }
  cout << dp[k][n];
}
inline void divide(long long int L, long long int R, long long int from,
                   long long int to, const long long int &K) {
  if (L > R) return;
  long long int mid = L + R >> 1;
  long long int best = mid;
  for (auto i = max(from, K); i <= min(mid, to); ++i) {
    long long int tg = COST_sub2(i, mid) + dp[K - 1][i - 1];
    if (dp[K][mid] > tg) {
      best = i;
      dp[K][mid] = tg;
    }
  }
  divide(L, mid - 1, from, best, K);
  divide(mid + 1, R, best, to, K);
}
void sub3() {
  for (auto i = 1; i <= n; ++i)
    for (auto j = 1; j <= k; ++j) dp[j][i] = inf;
  for (auto i = 1; i <= n; ++i) dp[1][i] = COST_sub2(1, i);
  for (auto j = 2; j <= k; ++j) {
    divide(1, n, 1, n, j);
  }
  cout << dp[k][n];
}
int main() {
  if (fopen("SEQ"
            ".inp",
            "r"))
    freopen(
        "SEQ"
        ".INP",
        "r", stdin),
        freopen(
            "SEQ"
            ".OUT",
            "w", stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (auto i = 1; i <= n; ++i) cin >> a[i];
  if (n <= 200)
    sub1();
  else if (n <= 1000)
    sub2();
  else
    sub3();
  return 0;
}
