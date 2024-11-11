#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
const int maxn = (long long)1e5 + 5;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;
struct node {
  int v, val, id;
  node(int v = 0, int val = 0, int id = 0) : v(v), val(val), id(id) {}
};
vector<node> v[maxn];
int n, m;
bool vis[maxn], tvis[maxn];
bool dfs(int x, int now) {
  vis[x] = true;
  tvis[x] = true;
  for (auto &i : v[x]) {
    int to = i.v, val = i.val;
    if (val <= now) continue;
    if (tvis[to] || !dfs(to, now)) return false;
  }
  tvis[x] = false;
  return true;
}
bool check(int now) {
  memset(vis, false, sizeof(vis));
  memset(tvis, false, sizeof(tvis));
  for (int i = 1; i <= n; ++i)
    if (!vis[i] && !dfs(i, now)) return false;
  return true;
}
int in[maxn];
int dep[maxn];
int cnt;
void top(int now) {
  queue<int> q;
  for (int i = 1; i <= n; ++i)
    if (!in[i]) q.push(i);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    dep[x] = ++cnt;
    for (auto &i : v[x])
      if (i.val > now && !--in[i.v]) q.push(i.v);
  }
}
vector<int> fin;
int f(int now) {
  for (int i = 1; i <= n; ++i)
    for (auto &j : v[i]) {
      if (j.val > now) ++in[j.v];
    }
  top(now);
  for (int i = 1; i <= n; ++i)
    if (!dep[i]) dep[i] = ++cnt;
  for (int i = 1; i <= n; ++i)
    for (auto &j : v[i])
      if (j.val <= now && dep[i] > dep[j.v]) fin.push_back(j.id);
  return fin.size();
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m;
  int maxr = 0;
  for (int i = 1; i <= m; ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    v[x].push_back(node(y, z, i));
    maxr = max(maxr, z);
  }
  int l = 0, r = maxr;
  int ans = r;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      r = mid - 1;
      ans = mid;
    } else
      l = mid + 1;
  }
  cout << ans << ' ' << f(ans) << '\n';
  for (auto &i : fin) cout << i << ' ';
  return 0;
}
