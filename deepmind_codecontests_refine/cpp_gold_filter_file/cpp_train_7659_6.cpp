#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
vector<vector<int>> adj;
long long arr[N];
long long dp[2][N];
void dfs(int u, int p = -1) {
  long long x = adj[u].size();
  if (p != -1) x--;
  long long cur_b = arr[u] - 1;
  if (x == 0) {
    dp[0][u] = 0;
    dp[1][u] = cur_b;
    return;
  }
  for (auto el : adj[u])
    if (el != p) dfs(el, u);
  if (cur_b >= x) {
    long long sum = 0;
    for (auto el : adj[u])
      if (el != p) dp[0][u] += dp[0][el] + 2, sum += (dp[1][el]);
    cur_b -= x;
    long long act = min(cur_b, sum);
    cur_b -= act;
    dp[0][u] += 2 * act;
    dp[1][u] = cur_b;
  } else {
    vector<long long> v;
    for (auto el : adj[u])
      if (el != p) v.push_back(dp[0][el]);
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < cur_b; i++) dp[0][u] += v[i] + 2;
    dp[1][u] = 0;
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d", arr + i);
  adj.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d %d\n", &u, &v);
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int s;
  cin >> s;
  s--;
  arr[s]++;
  dfs(s);
  cout << dp[0][s];
}
