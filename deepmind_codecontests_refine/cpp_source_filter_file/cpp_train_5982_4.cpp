#include <bits/stdc++.h>
using namespace std;
const long long int N = 2e5 + 5;
const long long int mod = 1e9 + 7;
const long long int level = 17;
long long int dx[] = {1, -1, 0, 0};
long long int dy[] = {0, 0, 1, -1};
long long int dp[N][2], color[N];
vector<long long int> v[N];
void dfs(long long int cur, long long int par) {
  dp[cur][0] = 1 - color[cur];
  dp[cur][1] = color[cur];
  long long int one = 0;
  long long int zero = 0;
  for (auto x : v[cur]) {
    if (x == par) continue;
    dfs(x, cur);
    zero = dp[cur][0];
    one = dp[cur][1];
    dp[cur][0] = 0;
    dp[cur][1] = 0;
    dp[cur][0] = (zero * dp[x][0]) % mod;
    dp[cur][1] = (zero * dp[x][1] + dp[x][0] * one) % mod;
    dp[cur][0] += (zero * dp[x][1]) % mod;
    dp[cur][1] += (one * dp[x][1]) % mod;
  }
}
int main() {
  ios::sync_with_stdio(false);
  long long int n;
  cin >> n;
  for (long long int i = 1; i < n; i++) {
    long long int x;
    cin >> x;
    v[i].push_back(x);
    v[x].push_back(i);
  }
  for (long long int i = 0; i < n; i++) cin >> color[i];
  dfs(0, -1);
  cout << dp[0][1] << endl;
  return 0;
}
