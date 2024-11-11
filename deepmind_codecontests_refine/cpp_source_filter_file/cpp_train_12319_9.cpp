#include <bits/stdc++.h>
using namespace std;
int N = 22;
int n, memo[1 << 22];
int a[1000010];
int st[4000010];
int solve(int mask) {
  if (st[mask]) return mask;
  if (memo[mask] != -1) return memo[mask];
  int cur = 0;
  for (int i = 0; i < N; i++) {
    if (mask & (1 << i)) {
      if (solve(mask - (1 << i))) {
        return memo[mask] = solve(mask - (1 << i));
      }
    }
  }
  return memo[mask] = 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  memset(memo, -1, sizeof(memo));
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    st[a[i]] = 1;
  }
  for (int i = 1; i <= n; i++) {
    int rmask = (1 << N) - 1 - a[i];
    if (solve(rmask) == 0)
      cout << -1 << " ";
    else
      cout << solve(rmask) << " ";
  }
}
