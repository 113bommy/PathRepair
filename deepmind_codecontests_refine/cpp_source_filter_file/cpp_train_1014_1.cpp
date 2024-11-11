#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1, -1, -1, 0, 1, -1, 0, 1};
long long frq[100005], f[100005], h[100005], dp[510][15], p;
long long dpcall(long long n, long long m) {
  if (m == 0 || n == 0) return 0;
  if (dp[n][m] != -1) return dp[n][m];
  dp[n][m] = 0;
  for (int i = 0; i < (m + 1); i++) {
    if (i > p) break;
    dp[n][m] = max(dp[n][m], h[i] + dpcall(n - 1, m - i));
  }
  return dp[n][m];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, k, a;
  cin >> n >> k;
  p = k;
  for (int i = 0; i < (n * k); i++) {
    cin >> a;
    frq[a]++;
  }
  for (int i = 0; i < (n); i++) {
    cin >> a;
    f[a]++;
  }
  for (int i = 0; i < (k); i++) {
    cin >> h[i + 1];
  }
  long long ans = 0;
  for (int i = 0; i < (100001); i++) {
    if (f[i]) {
      memset((dp), -1, sizeof(dp));
      ans += dpcall(f[i], frq[i]);
    }
  }
  cout << ans << endl;
  return 0;
}
