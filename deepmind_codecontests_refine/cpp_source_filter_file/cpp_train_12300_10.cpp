#include <bits/stdc++.h>
using namespace std;
long long solve() {
  long long n, m, ta, tb, k;
  cin >> n >> m >> ta >> tb >> k;
  vector<long long> a(n);
  vector<long long> b(m);
  for (long long &i : a) cin >> i;
  for (long long &i : b) cin >> i;
  vector<long long> dp(m);
  if (k >= min(n, m)) {
    cout << "-1\n";
    return 0;
  }
  for (int i = 0; i < m; i++) {
    int left = 0, right = n;
    if (a[n - 1] + ta <= b[i]) {
      dp[i] = n;
      continue;
    }
    while (right - left > 1) {
      int mid = (left + right) / 2;
      if (a[mid - 1] + ta <= b[i])
        left = mid;
      else
        right = mid;
    }
    dp[i] = left;
  }
  int max_b = 0;
  for (int i = 0; i < m; i++) {
    if (dp[i] > k) break;
    int to_del_b = k - dp[i];
    if (i + to_del_b + 1 >= m) {
      cout << -1 << '\n';
      return 0;
    } else {
      max_b = max(i + to_del_b + 1, max_b);
    }
  }
  cout << b[max_b] + tb << '\n';
  return 0;
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
