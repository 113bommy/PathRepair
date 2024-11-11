#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int INF = int(1e9), mod = 1000000007, N = 5000 + 5;
const long long BIG = 100000000000000;
const double PI = 3.141592653589793238463;
long long dp[N][N], n;
pair<long long, long long> a[N];
long long rec(int v, int cnt) {
  if (v == 0) {
    return 0ll;
  }
  if (dp[v][cnt] != -1) {
    return dp[v][cnt];
  }
  long long ans = rec(v - 1, cnt + 1) + (long long)a[v].second;
  if (v - 1 + cnt >= a[v].first) {
    ans = min(ans, rec(v - 1, cnt));
  }
  return dp[v][cnt] = ans;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + n + 1);
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        dp[i][j] = -1;
      }
    }
    cout << rec(n, 0) << endl;
  }
}
