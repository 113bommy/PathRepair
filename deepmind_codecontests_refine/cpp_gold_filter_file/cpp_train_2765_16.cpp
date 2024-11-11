#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const int inf = 0x3f3f3f3f;
const long long inff = 0x3f3f3f3f3f3f3f3f;
int n;
int a[200010];
int dp[200010];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
  }
  dp[n] = a[n];
  int mx = dp[n];
  for (int i = n - 1; i >= 2; i--) {
    dp[i] = max(a[i] - mx, mx);
    mx = max(a[i] - mx, mx);
  }
  cout << mx << endl;
}
