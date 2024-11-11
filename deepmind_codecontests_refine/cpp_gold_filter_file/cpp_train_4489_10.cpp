#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx,tune=native")
using namespace std;
template <typename T>
using pq_gt = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using pq_lt = priority_queue<T, vector<T>, less<T>>;
vector<int> edges[200200];
vector<int> rooted_edge[200200];
long long int dp[200200];
long long int sz[200200];
queue<int> q;
int par[200200];
long long int num[200200];
void dfs(int from, int to) {
  sz[from] = 1;
  for (int neigh : edges[from]) {
    if (neigh == to) continue;
    dp[neigh] = dp[from] + 1;
    dfs(neigh, from);
    sz[from] += sz[neigh];
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    edges[x].push_back(y);
    edges[y].push_back(x);
  }
  dfs(1, 0);
  long long int cnt = 0;
  long long int res = 0;
  for (int i = 1; i <= n; i++) {
    res += sz[i] * (long long int)(n - sz[i]);
    if (dp[i] % 2 == 1) cnt++;
  }
  res += cnt * (long long int)(n - cnt);
  cout << res / 2 << "\n";
}
