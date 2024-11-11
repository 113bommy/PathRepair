#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
long long const inf = 1e18, linf = 2e9, mod = 1e9 + 7, inf2 = 1e12;
int const mxn = 5e6 + 10;
long long poww(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * poww(a * a % md, b / 2, md) % md
                      : poww(a * a % md, b / 2, md) % md));
}
int n, k;
long long dis[100][100], l[100], dp[10][100], fas[100][100], ans = inf;
vector<int> vec1, vec2;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  srand(time(NULL));
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) cin >> dis[i][j];
  }
  int t = 500;
  for (int i = 2; i <= n; i++) l[i] = i;
  while (t--) {
    vec1.clear(), vec2.clear();
    for (int i = 1; i <= n; i++) {
      int a = rand() % 2;
      if (a or i == 1)
        vec1.push_back(i);
      else
        vec2.push_back(i);
    }
    for (auto v : vec1) {
      for (auto u : vec1) {
        fas[v][u] = inf;
        for (auto z : vec2) fas[v][u] = min(fas[v][u], dis[v][z] + dis[z][u]);
      }
    }
    for (int i = 0; i <= 5; i++)
      for (int j = 1; j <= n; j++) dp[i][j] = inf;
    int s = vec1.size();
    for (auto u : vec1) dp[0][u] = fas[1][u];
    for (int i = 1; i < k / 2; i++) {
      for (auto v : vec1) {
        dp[i][v] = inf;
        for (auto u : vec1) {
          dp[i][v] = min(dp[i][v], dp[i - 1][u] + fas[u][v]);
        }
      }
    }
    ans = min(dp[k / 2 - 1][1], ans);
  }
  cout << ans;
}
