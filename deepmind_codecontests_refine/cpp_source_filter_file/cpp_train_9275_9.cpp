#include <bits/stdc++.h>
using namespace std;
int n;
int ind[100001], a[100001];
int dp[100001][3];
int f(int cur, int p) {
  if (dp[cur][p] != -1) {
    return dp[cur][p];
  }
  int res = 0;
  for (int nex = cur; nex <= n; nex += cur) {
    int right = ind[cur] + cur;
    int left = ind[cur] - cur;
    if (right <= n && a[right] > cur) {
      if (f(a[right], 3 - p) == p) {
        res = 1;
      }
    }
    if (left >= 1 && a[left] > cur) {
      if (f(a[left], 3 - p) == p) {
        res = 1;
      }
    }
  }
  dp[cur][p] = (res ? p : 3 - p);
  return dp[cur][p];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  memset(dp, -1, sizeof dp);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ind[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    cout << (f(a[i], 1) == 1 ? 'A' : 'B');
  }
}
