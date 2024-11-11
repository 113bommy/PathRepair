#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int INF = 1e9;
vector<int> dp(1000000, INF);
int f(int n) {
  if (n < 10)
    return n;
  else {
    int d = 10, i = n;
    int ans = 1;
    while (n != 0) {
      if (n % d != 0) ans *= n % d;
      n /= d;
    }
    return ans;
  }
}
int g(int n) {
  if (n < 10)
    return n;
  else {
    dp[n] = dp[f(n)];
    return dp[n];
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  vector<int> a(10);
  vector<vector<int>> pf(10, vector<int>(1000000));
  for (int i = 1; i < 10; i++) dp[i] = i;
  for (int i = 1; i < 1000000; i++) {
    int d = g(i);
    for (int j = 0; j < 10; j++) {
      if (d == j)
        pf[j][i] = ++a[j];
      else
        pf[j][i] = a[j];
    }
  }
  while (t--) {
    int l, r, k, ans = 0;
    cin >> l >> r >> k;
    cout << pf[k][r] - pf[k][l - 1] << endl;
  }
  return 0;
}
