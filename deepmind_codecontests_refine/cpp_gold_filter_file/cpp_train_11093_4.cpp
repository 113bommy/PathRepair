#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long N = 3e5 + 5;
vector<int> adj[N], adj1[N];
bool visited[N];
int height[N], val[N], grid[55][55];
void solve() {
  int n;
  cin >> n;
  vector<int> v;
  int a[n], strt = -1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i]) strt = i;
  }
  for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      v.push_back(i);
      if (i * i != n) v.push_back(n / i);
    }
  }
  for (auto i : v) {
    int dp[n], ans = 0;
    for (int j = 0; j < n; j++) dp[j] = a[j];
    for (int j = 0; j < n; j++) {
      if (a[j]) {
        dp[j] = max(dp[j], dp[(j - i + n) % n] + 1);
        ans = max(ans, dp[j]);
      }
    }
    if (ans - 1 < 3) continue;
    if (ans - 1 == n / i) {
      cout << "YES";
      return;
    }
  }
  cout << "NO";
}
int main() {
  int t = 1;
  while (t--) solve();
}
