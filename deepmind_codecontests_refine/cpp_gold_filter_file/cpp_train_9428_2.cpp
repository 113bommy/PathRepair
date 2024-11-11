#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 10;
long long n, a[N], b[N], res[N];
vector<long long> adj[N];
bool mark[N];
void fail() {
  cout << -1;
  exit(0);
}
void dfs(long long v, long long c = 1) {
  if (res[v] && res[v] != c) fail();
  res[v] = c;
  mark[v] = true;
  for (auto u : adj[v])
    if (!mark[u]) dfs(u, 3 - c);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; i++)
    cin >> a[i] >> b[i], adj[a[i]].push_back(b[i]), adj[b[i]].push_back(a[i]);
  for (long long i = 1; i <= 2 * n; i += 2)
    adj[i].push_back(i + 1), adj[i + 1].push_back(i);
  adj[1].push_back(2 * n), adj[2 * n].push_back(1);
  for (long long i = 1; i <= 2 * n; i++)
    if (!mark[i]) dfs(i);
  for (long long i = 1; i <= n; i++)
    cout << res[a[i]] << ' ' << res[b[i]] << '\n';
}
