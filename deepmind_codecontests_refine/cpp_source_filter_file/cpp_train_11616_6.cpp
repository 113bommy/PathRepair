#include <bits/stdc++.h>
using namespace std;
long long int m, i, j, n, tmp, p, q, cnt, d, k, u, vv, t,
    ans = -12345678998, a[223456], mx[223456], sm[223456];
string s;
vector<vector<long long int> > g(223456);
void dfs(long long int ver, long long int par) {
  mx[ver] = -12345678998;
  sm[ver] = a[ver];
  for (auto &it : g[ver]) {
    if (it == par) continue;
    dfs(it, ver);
    sm[ver] += a[it];
    mx[ver] = max(mx[ver], mx[it]);
  }
  mx[ver] = max(mx[ver], sm[ver]);
}
void dfs1(long long int ver, long long int par, long long int out) {
  if (out != -12345678998) ans = max(ans, out + mx[ver]);
  vector<long long int> v;
  v.push_back(-12345678998);
  v.push_back(-12345678998);
  for (auto &it : g[ver]) {
    if (it == par) continue;
    v.push_back(mx[it]);
    sort(v.begin(), v.end(), greater<long long int>());
    if (v.size() > 2) v.pop_back();
  }
  for (auto &it : g[ver]) {
    if (it == par) continue;
    if (v[0] == mx[it])
      dfs1(it, ver, max(out, v[1]));
    else
      dfs1(it, ver, max(out, v[0]));
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  if (fopen("inp.txt", "r")) freopen("inp.txt", "r", stdin);
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n - 1; i++) {
    cin >> u >> vv;
    u--;
    vv--;
    g[u].push_back(vv);
    g[vv].push_back(u);
  }
  dfs(0, -1);
  long long int out = -12345678998;
  dfs1(0, -1, out);
  if (ans == -12345678998)
    cout << "Impossible";
  else
    cout << ans;
  return 0;
}
