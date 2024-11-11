#include <bits/stdc++.h>
using namespace std;
vector<long long int> v[1000001];
vector<long long int> temp;
long long int dp[1000001], a[1000001];
void dfs(long long int cur, long long int par) {
  for (long long int i = 0; i < v[cur].size(); i++) {
    long long int x = v[cur][i];
    if (x == par) continue;
    a[x]--;
    dfs(x, cur);
  }
  temp.clear();
  for (long long int i = 0; i < v[cur].size(); i++) {
    long long int x = v[cur][i];
    if (x == par) continue;
    temp.push_back(dp[x]);
  }
  sort(temp.begin(), temp.end());
  reverse(temp.begin(), temp.end());
  for (long long int i = 0; i < temp.size(); i++) {
    if (!a[cur]) break;
    dp[cur] += temp[i];
    dp[cur] += 2;
    a[cur]--;
  }
  for (long long int i = 0; i < v[cur].size(); i++) {
    long long int x = v[cur][i];
    if (x == par) continue;
    long long int y = min(a[x], a[cur]);
    dp[cur] += 2 * y;
    a[x] -= y;
    a[cur] -= y;
  }
}
int main() {
  ios::sync_with_stdio(false);
  ;
  cin.tie(0);
  ;
  long long int i, j, n, x, y, root;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= n - 1; i++) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  cin >> root;
  dfs(root, -1);
  cout << dp[root];
  return 0;
}
