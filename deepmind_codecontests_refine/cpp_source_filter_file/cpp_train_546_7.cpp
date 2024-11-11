#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10;
const long long mod = 1e9 + 7;
const long long INF = 1e18;
const long long inf = -1e18;
pair<long long, string> a[N];
long long dp[N], n, cnt = 3002;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].second >> a[i].first;
  }
  sort(a + 1, a + n + 1);
  if (a[1].first > 0) {
    cout << -1;
    cin.get(), cin.get();
    return 0;
  }
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i].first > i) {
      cout << -1;
      cin.get(), cin.get();
      return 0;
    }
    dp[i] = a[i].first;
    for (int j = 0; j <= i; j++) {
      if (dp[j] >= a[i].first) {
        dp[j]++;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i].second << " " << cnt - dp[i] << '\n';
  }
  cin.get(), cin.get();
}
