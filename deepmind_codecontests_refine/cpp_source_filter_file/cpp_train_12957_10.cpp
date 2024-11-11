#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long a[2001], n, d;
bool visited[2001][2002];
vector<long long> Edges[2001];
long long dfs(long long node, long long root) {
  long long ans = 1;
  for (auto v : Edges[node]) {
    if (((a[v] > a[root]) || (a[v] == a[root] && v > root)) &&
        a[v] - a[root] <= d && visited[root][v] == false) {
      visited[root][v] = true;
      ans = ans * dfs(v, root);
    }
  }
  return (ans + (node != root)) % mod;
}
int main() {
  long long i, x, y;
  cin >> d >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i < n; i++)
    cin >> x >> y, Edges[x].push_back(y), Edges[y].push_back(x);
  long long ans = 0;
  for (i = 1; i <= n; i++) {
    visited[i][i] = true;
    ans = (ans + dfs(i, i)) % mod;
  }
  cout << ans << endl;
  return 0;
}
