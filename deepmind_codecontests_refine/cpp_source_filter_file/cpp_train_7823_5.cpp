#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
const long long int N = 500005;
vector<long long int> adj[N], v[N];
long long int d[N], f[N], s[N];
long long int n;
bool cmp(long long int a, long long int b) { return f[a] < f[b]; }
void dfs(long long int x, long long int pr) {
  s[x] = 1;
  for (auto i : adj[x])
    if (i != pr) dfs(i, x);
  for (auto i : adj[x])
    if (i != pr) s[x] += s[i];
  d[x] = s[x] * s[x];
  f[x] = d[x];
  for (auto i : adj[x])
    if (i != pr) d[x] = min(d[x], d[i] + (s[x] - s[i]) * (s[x] - s[i]));
  f[x] += d[x] - 2 * n * s[x];
  for (auto i : adj[x])
    if (i != pr) v[x].push_back(i);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cin >> n;
  for (long long int i = 1; i < n; i++) {
    long long int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1, 1);
  long long int ans = 0;
  for (long long int i = 1; i <= n; i++) {
    sort(v[i].begin(), v[i].end());
    if (v[i].size() == 0) continue;
    if (v[i].size() == 1) ans = min(ans, f[i]);
    if (v[i].size() > 1) {
      long long int x = v[i][0], y = v[i][1];
      long long int val = f[x] + f[y] + 2 * s[x] * s[y];
      ans = min(ans, val);
    }
  }
  long long int val = n * (n - 1);
  cout << (val - ans) / 2;
}
