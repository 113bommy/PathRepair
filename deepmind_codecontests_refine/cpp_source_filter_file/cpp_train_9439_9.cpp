#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int dx[8] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
vector<int> adj[200010], val(300010, 1), vis(300010, 0), dis1(300010, 0),
    dis2(300010, 0);
int myrandom(int i) { return std::rand() % i; }
vector<long long> v(100);
vector<long long> pre(100, 0);
long long n, k;
bool solve(long long num) {
  long long dp[n + 1][k + 1];
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      for (int l = 0; l < i; l++) {
        long long sum = pre[i] - pre[l];
        long long cum = sum & num;
        if (cum == num) {
          dp[i][j] |= dp[l][j - 1];
        }
      }
    }
  }
  return dp[n][k];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) {
    cin >> v[i];
  }
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + v[i];
  }
  long long num = 0;
  for (long long i = 51; i >= 0; i--) {
    if (solve(num | (1ll << i))) {
      num = num | (1ll << i);
    }
  }
  cout << num << '\n';
}
