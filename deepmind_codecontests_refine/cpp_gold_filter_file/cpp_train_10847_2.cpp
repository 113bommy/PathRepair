#include <bits/stdc++.h>
using namespace std;
int a[40];
int b[40];
long long dp[40][2][2];
long long dfs(int pos, int l1, int l2) {
  if (pos == -1) return 1;
  if (dp[pos][l1][l2] != -1) return dp[pos][l1][l2];
  int up1 = l1 ? a[pos] : 1;
  int up2 = l2 ? b[pos] : 1;
  long long ans = 0;
  for (int i = 0; i <= up1; i++) {
    for (int j = 0; j <= up2; j++) {
      if (!(i & j)) ans += dfs(pos - 1, l1 && i == a[pos], l2 && j == b[pos]);
    }
  }
  dp[pos][l1][l2] = ans;
  return ans;
}
long long slove(long long l, long long r) {
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i <= 35; i++) {
    a[i] = b[i] = 0;
  }
  int posa = 0;
  while (l) {
    a[posa++] = l % 2;
    l /= 2;
  }
  posa--;
  int posb = 0;
  while (r) {
    b[posb++] = r % 2;
    r /= 2;
  }
  posb--;
  return dfs(30, 1, 1);
}
void solve(int T) {
  long long l, r;
  cin >> l >> r;
  cout << slove(r, r) - 2ll * slove(l - 1ll, r) + slove(l - 1ll, l - 1ll)
       << endl;
}
signed main() {
  int t = 1;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    solve(i);
  }
  return 0;
}
