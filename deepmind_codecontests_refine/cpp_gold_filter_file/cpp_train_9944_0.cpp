#include <bits/stdc++.h>
using namespace std;
set<int> S;
void findPrime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      while (x % i == 0) x /= i;
      S.insert(i);
    }
  }
  if (x != 1) S.insert(x);
}
const long long inf = 1e18;
const int MAXN = 1e6 + 10;
int n, a, b;
int A[MAXN];
int B[MAXN];
void load() {
  scanf("%d%d%d", &n, &a, &b);
  for (int i = 1; i <= n; i++) scanf("%d", A + i);
}
long long dp[MAXN][3];
long long opt(int p) {
  for (int i = 1; i <= n; i++) {
    if (A[i] % p == 0) {
      dp[i][0] = dp[i - 1][0];
      dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]) + a;
      dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]);
    } else if (A[i] % p == 1 || A[i] % p == p - 1) {
      dp[i][0] = dp[i - 1][0] + b;
      dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]) + a;
      dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + b;
    } else {
      dp[i][0] = inf;
      dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + a;
      dp[i][2] = inf;
    }
  }
  return min(dp[n][0], min(dp[n][1], dp[n][2]));
}
void solve() {
  int f = A[1], l = A[n];
  if (f > 2) findPrime(f - 1);
  if (l > 2) findPrime(l - 1);
  if (f > 1) findPrime(f);
  if (l > 1) findPrime(l);
  if (f) findPrime(f + 1);
  if (l) findPrime(l + 1);
  long long sol = inf;
  for (auto it = S.begin(); it != S.end(); it++) {
    long long o = opt(*it);
    sol = min(sol, o);
  }
  printf("%I64d\n", sol);
}
int main() {
  load();
  solve();
  return 0;
}
