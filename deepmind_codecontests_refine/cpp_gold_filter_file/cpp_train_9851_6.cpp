#include <bits/stdc++.h>
using namespace std;
const int P = 1000 * 1000 * 1000 + 7;
const int N = 2 * 100 * 1000 + 2;
int n, cnt, vis[N], ans = 1;
vector<int> adj[N], vec;
map<int, int> idx, idy;
inline long long _mul(long long a, long long b, long long c = 1) {
  return a * b % P * c % P;
}
long long _pow(int a) {
  if (a < 2) return a ? 2 : 1;
  long long t = _pow(a / 2);
  return _mul(t, t, a & 1 ? 2 : 1);
}
pair<int, int> dfs(int u, int par) {
  pair<int, int> res = {1, 1};
  vis[u] = true;
  for (auto v : adj[u])
    if (v ^ par) {
      if (vis[v])
        res.second = 0;
      else {
        pair<int, int> t = dfs(v, u);
        res.first += t.first;
        res.second &= t.second;
      }
    }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 0, x, y; i < n; i++) {
    cin >> x >> y;
    if (idx[x] == 0) idx[x] = ++cnt;
    if (idy[y] == 0) idy[y] = ++cnt;
    adj[idx[x]].push_back(idy[y]);
    adj[idy[y]].push_back(idx[x]);
  }
  for (int i = 1; i <= cnt; i++)
    if (!vis[i]) {
      pair<int, int> t = dfs(i, -1);
      ans = _mul(ans, _pow(t.first) - t.second);
    }
  cout << ans << endl;
}
