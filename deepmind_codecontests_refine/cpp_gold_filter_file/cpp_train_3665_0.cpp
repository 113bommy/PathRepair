#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int a[200005][4], z, n, dp[200005][4];
int k1, k2, k3;
int f(int x, int pr) {
  if (pr > 2) return 1e9;
  if (x == n + 1) return 0;
  if (dp[x][pr] != -1) return dp[x][pr];
  int pl = 0;
  if (a[x][pr] == 0) pl++;
  int mn = 1e9;
  mn = min(mn, f(x + 1, pr) + pl);
  mn = min(mn, f(x + 1, pr + 1) + pl);
  mn = min(mn, f(x + 1, pr + 2) + pl);
  return dp[x][pr] = mn;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  memset(dp, -1, sizeof dp);
  cin >> k1 >> k2 >> k3;
  for (int i = 0; i < k1; i++) {
    int x;
    cin >> x;
    n = max(n, x);
    a[x][0]++;
  }
  for (int i = 0; i < k2; i++) {
    int x;
    cin >> x;
    n = max(n, x);
    a[x][1]++;
  }
  for (int i = 0; i < k3; i++) {
    int x;
    cin >> x;
    n = max(n, x);
    a[x][2]++;
  }
  cout << min(f(1, 0), min(f(1, 1), f(1, 2))) << endl;
}
