#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3010;
ll a[N], dp[N][N];
void solve() {
  ll n, ans = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) dp[i][j] = 0;
  for (int j = n; j > 0; j--) {
    int k = j;
    for (int i = 1; i < j; i++) {
      ans += dp[a[i]][a[j]];
    }
    for (int l = k + 1; l <= n; l++) {
      dp[a[k]][a[l]]++;
    }
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  cin >> n;
  while (n--) {
    solve();
  }
  getchar();
  getchar();
  return 0;
}
