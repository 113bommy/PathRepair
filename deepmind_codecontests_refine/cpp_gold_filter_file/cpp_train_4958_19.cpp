#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 1000, K = 20 + 3;
int n, k, a[N];
long long ans;
int cnt[N], l = 1, r;
long long cost(int L, int R) {
  while (r < R) ans += cnt[a[++r]]++;
  while (r > R) ans -= --cnt[a[r--]];
  while (l > L) ans += cnt[a[--l]]++;
  while (l < L) ans -= --cnt[a[l++]];
  return ans;
}
long long dp[K][N], newCost;
void calc(int k, int l, int r, int optL, int optR) {
  if (l > r) return;
  int mid = (l + r) >> 1, pos = 0;
  dp[k][mid] = 1e18;
  for (int i = optL, lim = min(optR, mid - 1); i <= lim; ++i) {
    newCost = dp[k - 1][i] + cost(i + 1, mid);
    if (dp[k][mid] > newCost) {
      dp[k][mid] = newCost;
      pos = i;
    }
  }
  calc(k, l, mid - 1, optL, pos);
  calc(k, mid + 1, r, pos, optR);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) dp[1][i] = cost(1, i);
  for (int i = 2; i <= k; ++i) calc(i, i, n, i - 1, n);
  cout << dp[k][n];
}
