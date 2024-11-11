#include <bits/stdc++.h>
using namespace std;
int dx[] = {+1, -1, +0, +0};
int dy[] = {+0, +0, +1, -1};
int fx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int fy[] = {-1, +1, +0, +0, +1, +1, -1, -1};
int hr[] = {-2, -2, -1, +1, +2, +2, -1, +1};
int hc[] = {+1, -1, +2, +2, -1, +1, -2, -2};
const int MAXN = (int)1e5 + 9;
long long n;
long long ara[5005], dp[5005][5005], v[5005];
long long solve(int idx, int k) {
  if (idx > n) return 0;
  if (dp[idx][k] != -1) return dp[idx][k];
  return dp[idx][k] = max(solve(idx + v[idx], k),
                          k ? (v[idx] + solve(idx + v[idx], k - 1)) : 0);
}
int main() {
  long long i, j, k, l, m, p, q, r, tc, t;
  cin >> n >> k;
  for (int i = (int)1; i <= (int)n; i++) {
    cin >> ara[i];
  }
  sort(ara + 1, ara + n + 1);
  for (int i = (int)1; i <= (int)n; i++) {
    p = upper_bound(ara + 1, ara + n + 1, ara[i] + 5) - ara;
    v[i] = p - i;
  }
  memset(dp, -1, sizeof(dp));
  long long ans = solve(1, k);
  cout << ans << endl;
  return 0;
}
