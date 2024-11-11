#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int dx[8] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
vector<int> adj[300010], val(300010, 1), vis(300010, 0), dis1(300010, 0),
    dis2(300010, 0);
int myrandom(int i) { return std::rand() % i; }
long long dp[10010][110];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, l;
  cin >> n >> l;
  vector<vector<int>> v;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (a == b) {
      v.push_back({a, b, i});
    } else {
      v.push_back({a, b, i});
      v.push_back({b, a, i});
    }
  }
  n = (int)v.size();
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++) {
    dp[v[i][1]][i] = 1;
  }
  for (int i = 1; i < l; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (v[j][2] != v[k][2] && v[j][1] == v[k][0]) {
          dp[i + v[k][1]][k] = (dp[i + v[k][1]][k] + dp[i][j]) % 1000000007;
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans = (ans + dp[l][i]) % 1000000007;
  }
  cout << ans << '\n';
}
