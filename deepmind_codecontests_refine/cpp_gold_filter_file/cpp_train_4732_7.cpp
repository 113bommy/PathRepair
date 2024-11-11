#include <bits/stdc++.h>
using namespace std;
const int SIZEN = 105;
const int INF = 10000007;
int fact[SIZEN], prime[SIZEN];
int a[SIZEN], cnt;
int dp[SIZEN][(1 << 17) + 5];
int pre[SIZEN][(1 << 17) + 5];
bool isprime(int x) {
  if (x == 2) return 1;
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) return 0;
  return 1;
}
void init() {
  cnt = 0;
  for (int i = 2; i < 60; i++)
    if (isprime(i)) prime[cnt++] = i;
  for (int i = 1; i < 60; i++) {
    fact[i] = 0;
    for (int j = 0; j < cnt && prime[j] <= i; j++)
      if (i % prime[j] == 0) fact[i] += (1 << j);
  }
}
void solve(int n) {
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  cnt = (1 << 17);
  memset(dp, 63, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int k = 1; k < 60; k++) {
      int x = (~fact[k]) & ((1 << 17) - 1);
      for (int s = x;; s = (s - 1) & x) {
        if (dp[i][fact[k] | s] > dp[i - 1][s] + abs(a[i] - k)) {
          dp[i][fact[k] | s] = dp[i - 1][s] + abs(a[i] - k);
          pre[i][fact[k] | s] = k;
        }
        if (s == 0) break;
      }
    }
  }
  int flag, Min = INF;
  for (int s = 0; s < cnt; s++) {
    if (Min > dp[n][s]) {
      Min = dp[n][s];
      flag = s;
    }
  }
  int tt, tans;
  int s = flag;
  vector<int> ans;
  for (int i = n; i >= 1; i--) {
    ans.push_back(pre[i][s]);
    s = s & (~fact[pre[i][s]]);
  }
  for (int i = n - 1; i >= 0; i--) printf("%d ", ans[i]);
  printf("\n");
}
int main() {
  int i, j;
  int n;
  init();
  while (scanf("%d", &n) != EOF) solve(n);
}
