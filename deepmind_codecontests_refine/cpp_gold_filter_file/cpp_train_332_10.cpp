#include <bits/stdc++.h>
using namespace std;
long long int n, u, v, q, x, y, a, b, k, p[100007][22], d[100007];
vector<long long int> adj[100007];
void dfs(long long int x, long long int par) {
  d[x] = d[par] + 1;
  p[x][0] = par;
  for (long long int i = 1; i <= 20; ++i) {
    p[x][i] = p[p[x][i - 1]][i - 1];
  }
  for (long long int i : adj[x]) {
    if (i != par) dfs(i, x);
  }
}
long long int dist(long long int a, long long int b) {
  if (d[a] > d[b]) swap(a, b);
  long long int res = 0;
  for (long long int i = 20; i >= 0; --i) {
    if (d[p[b][i]] >= d[a]) {
      b = p[b][i];
      res += (1 << i);
    }
  }
  if (a == b) return res;
  for (long long int i = 20; i >= 0; --i) {
    if (p[b][i] != p[a][i]) {
      b = p[b][i];
      a = p[a][i];
      res += (1 << (i + 1));
    }
  }
  return res + 2;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (long long int i = 0; i < n - 1; ++i) {
    long long int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1, 0);
  cin >> q;
  while (q--) {
    cin >> x >> y >> a >> b >> k;
    long long int ans = dist(a, b), ans2 = (dist(a, x) + dist(y, b)) + 1,
                  ans3 = (dist(a, y) + dist(x, b)) + 1;
    long long int f = 0x3f3f3f3f3f3f3f3f;
    if (ans % 2 == k % 2) f = min(f, ans);
    if (ans2 % 2 == k % 2) f = min(f, ans2);
    if (ans3 % 2 == k % 2) f = min(f, ans3);
    if (f <= k)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
