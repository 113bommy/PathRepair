#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4e5 + 100;
int n, m, U[MAXN], V[MAXN], c[MAXN], t[MAXN];
int res[MAXN];
map<int, int> mp;
vector<int> adj[MAXN], in[MAXN], out[MAXN], vec;
bool mark[MAXN], is[MAXN];
void dfs(int u) {
  mark[u] = true;
  for (int i = 0; i < out[u].size(); i++) {
    int v = out[u][i];
    if (!mark[v]) dfs(v);
  }
  vec.push_back(u);
}
void dfs2(int u, int cc) {
  res[u] = cc;
  for (int i = 0; i < in[u].size(); i++) {
    int v = in[u][i];
    if (res[v] == -1) dfs2(v, cc);
  }
}
inline void add_e(int a, int b) {
  out[a ^ 1].push_back(b);
  in[b].push_back(a ^ 1);
  out[b ^ 1].push_back(a);
  in[a].push_back(b ^ 1);
}
bool ok(int mid) {
  int C = m;
  for (int i = 0; i < MAXN; i++) {
    in[i].clear(), out[i].clear();
    mark[i] = is[i] = 0;
    res[i] = -1;
  }
  vec.clear();
  for (int i = 0; i < n; i++) {
    mp.clear();
    int cur = -1;
    for (int j = 0; j < adj[i].size(); j++) {
      int id = adj[i][j];
      if (cur == -1)
        cur = id;
      else {
        add_e(2 * cur + 1, 2 * id + 1);
        add_e(2 * cur + 1, 2 * C);
        add_e(2 * id + 1, 2 * C);
        cur = C;
        C++;
      }
      if (!mp[c[id]])
        mp[c[id]] = id + 1;
      else if (mp[c[id]] == -1)
        return false;
      else
        add_e(2 * (mp[c[id]] - 1), 2 * id), mp[c[id]] = -1;
    }
  }
  for (int i = 0; i < m; i++)
    if (t[i] > mid)
      out[2 * i].push_back(2 * i + 1), in[2 * i + 1].push_back(2 * i);
  for (int i = 0; i < 2 * C; i++)
    if (!mark[i]) dfs(i);
  int cnt = 0;
  for (int i = 2 * C - 1; i >= 0; i--) {
    if (res[vec[i]] == -1) dfs2(vec[i], cnt++);
  }
  for (int i = 0; i < C; i += 2) {
    if (res[i] == res[i + 1])
      return false;
    else if (res[i] > res[i + 1])
      is[i / 2] = true;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> U[i] >> V[i] >> c[i] >> t[i], V[i]--, U[i]--;
    adj[V[i]].push_back(i), adj[U[i]].push_back(i);
  }
  int l = -1, r = INT_MAX / 2 + 10;
  while (r - l > 1) {
    int mid = (r + l) / 2;
    if (ok(mid))
      r = mid;
    else
      l = mid;
  }
  if (r >= INT_MAX / 2 + 5) return cout << "No" << endl, 0;
  ok(r);
  cout << "Yes" << endl;
  int ans = 0;
  for (int i = 0; i < m; i++)
    if (is[i]) ans++;
  cout << r << " " << ans << endl;
  for (int i = 0; i < m; i++)
    if (is[i]) cout << i + 1 << " ";
  return 0;
}
