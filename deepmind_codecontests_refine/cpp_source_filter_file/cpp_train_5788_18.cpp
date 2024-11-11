#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
vector<int> v[maxn];
int k, n, cp[maxn], ans, dp[maxn][10];
int mod(int a, int b) { return ((a - b) % k + k) % k; }
void dfs(int u, int p, int sqr) {
  cp[u] = 1, dp[u][sqr % k] = 1;
  for (int x : v[u]) {
    if (x != p) {
      dfs(x, u, sqr + 1);
      cp[u] += cp[x];
      for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
          int ss = mod(i + j, 2 * sqr);
          int wer = mod(k, ss);
          ans += wer * dp[u][i] * dp[x][j];
        }
      }
      for (int i = 0; i < k; i++) dp[u][i] += dp[x][i];
    }
  }
  ans += cp[u] * (n - cp[u]);
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y), v[y].push_back(x);
  }
  dfs(1, -1, 0);
  cout << ans / k;
  return 0;
}
