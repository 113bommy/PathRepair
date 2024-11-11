#include <bits/stdc++.h>
using namespace std;
int m, n, dp[100010] = {};
int *a;
bool check[100010];
int main() {
  cin >> n >> m;
  a = new int[n + 1];
  int l;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = n; i > 0; i--) {
    dp[i] = dp[i + 1] + (!check[a[i]]);
    check[a[i]] = true;
  }
  for (int i = 1; i <= m; i++) {
    cin >> l;
    cout << dp[l] << endl;
  }
  delete a;
  return 0;
}
