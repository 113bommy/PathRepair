#include <bits/stdc++.h>
using namespace std;
const int inf = 1000 * 1000 * 1000 + 7;
const int maxn = 2012;
vector<long long> vec[maxn];
long long n, d, a[maxn], ans, dp[maxn], h;
bool mark[maxn];
int dfs(int v, int node, int root) {
  mark[v] = true;
  long long ret = 1;
  for (auto &u : vec[v])
    if (!mark[u] && node - a[u] <= d &&
        (a[u] < node || (a[u] == node && root < u)))
      ret = (long long)ret * (dfs(u, node, root) + 1) % inf;
  return ret;
}
int main() {
  cin >> d >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0, c, b; i < n - 1; i++)
    cin >> c >> b, c--, b--, vec[c].push_back(b), vec[b].push_back(c);
  for (int i = 0; i < n; i++) {
    dp[i] = dfs(i, a[i], i);
    memset(mark, 0, sizeof mark);
    ans = (long long)(ans + dp[i]) % inf;
  }
  cout << ans;
}
