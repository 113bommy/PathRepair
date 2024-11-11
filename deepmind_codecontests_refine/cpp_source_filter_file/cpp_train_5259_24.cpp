#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int a[MAXN], dp[MAXN];
int main() {
  int n, cnt = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) dp[a[i]] = dp[a[i] - 1] + 1;
  for (int i = 0; i < n; i++) cnt = max(cnt, dp[i]);
  cout << n - cnt;
}
