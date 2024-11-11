#include <bits/stdc++.h>
using namespace std;
int a[1000000], n, dp[100000], ans;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    dp[a[i]] = i;
  }
  for (int i = n; i >= 1; i--)
    if (dp[a[i]] == i) ans = i;
  cout << a[ans] << endl;
  return 0;
}
