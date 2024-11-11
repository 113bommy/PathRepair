#include <bits/stdc++.h>
using namespace std;
struct ed {
  int u, v, num;
  long long w;
  ed() {}
  ed(int u, int v, long long w, int num) : u(u), v(v), w(w), num(num) {}
};
vector<ed> edge[1001];
bool used[1001];
int tin[1001];
int dp[1001];
bool blocked[1001][1001];
vector<ed> w;
int t = 0;
int cur = -1;
const int INF = 2e9 + 7;
bool bad[1001];
int ct[1001];
void dfs(int u, int p) {
  used[u] = true;
  vector<ed> adv;
  for (auto v : edge[u]) {
    if (!used[v.v]) adv.push_back(v);
  }
  for (auto v : adv) {
    if (v.num != cur) ct[v.v]++;
    if (ct[v.v] >= 2) bad[v.v] = true;
  }
  for (auto v : adv)
    if (v.num != cur) ct[v.v]--;
  tin[u] = t++;
  dp[u] = tin[u];
  for (auto v : edge[u]) {
    if (v.num == cur) continue;
    if (!used[v.v]) {
      dfs(v.v, u);
      dp[u] = min(dp[u], dp[v.v]);
      if (dp[v.v] > tin[u] && !bad[v.v]) {
        blocked[u][v.v] = true;
        blocked[v.v][u] = true;
        w.push_back(v);
      }
    }
    if (v.v != p) dp[u] = min(dp[u], tin[v.v]);
  }
  for (auto v : adv)
    if (v.num != cur) bad[v.v] = false;
}
vector<ed> pt;
long long ans = INF;
int a1 = -1, b1 = -1;
vector<ed> eds;
bool find(int s, int t) {
  if (s == t) {
    for (auto v : pt) {
      if (blocked[v.u][v.v]) {
        if (ans > (cur == -1 ? 0 : eds[cur].w) + v.w) {
          ans = (cur == -1 ? 0 : eds[cur].w) + v.w;
          b1 = cur;
          a1 = v.num;
        }
      }
    }
    return true;
  }
  used[s] = true;
  for (auto v : edge[s]) {
    int k = v.num;
    if (k != cur && !used[v.v]) {
      pt.push_back(v);
      if (find(v.v, t)) return true;
      pt.pop_back();
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n, m;
  cin >> n >> m;
  int s, t;
  cin >> s >> t;
  t--;
  s--;
  for (int i = 0; i < m; i++) {
    int u, v;
    long long w1;
    cin >> u >> v >> w1;
    u--;
    v--;
    eds.push_back(ed(u, v, w1, i));
    edge[u].push_back(ed(u, v, w1, i));
    edge[v].push_back(ed(v, u, w1, i));
  }
  dfs(0, 0);
  for (int i = 0; i < n; i++) used[i] = false;
  if (!find(s, t)) {
    cout << "0\n0";
    return 0;
  }
  for (auto v : w) {
    blocked[v.v][v.u] = blocked[v.u][v.v] = false;
  }
  vector<ed> vt1 = pt;
  for (auto k : vt1) {
    int i = k.num;
    cur = i;
    auto p = eds[i];
    for (int i = 0; i < n; i++) used[i] = false;
    vector<ed>().swap(w);
    vector<ed>().swap(pt);
    dfs(0, 0);
    for (int i = 0; i < n; i++) used[i] = false;
    find(s, t);
    for (auto v : w) {
      blocked[v.u][v.v] = blocked[v.v][v.u] = false;
    }
  }
  if (ans == INF) {
    cout << -1;
    return 0;
  }
  if (ans == 0) {
    cout << "0\n0";
    return 0;
  }
  if (b1 == -1) {
    cout << ans << "\n1\n" << a1 + 1;
    return 0;
  }
  cout << ans << "\n2\n" << a1 + 1 << " " << b1 + 1;
  return 0;
}
