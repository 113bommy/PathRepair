#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
const double eps = 1e-6;
int n, m;
int x[maxn], y[maxn], z[maxn];
struct HK {
  vector<int> G[maxn];
  int uN;
  int Mx[maxn], My[maxn];
  int dx[maxn], dy[maxn];
  int dis;
  bool used[maxn];
  void init() {
    uN = n;
    for (int i = 0; i <= uN - 1; i++) G[i].clear();
  }
  void draw() {}
  bool SearchP() {
    queue<int> Q;
    dis = inf;
    for (int i = 0; i <= uN - 1; i++) dx[i] = dy[i] = -1;
    for (int i = 0; i <= uN - 1; i++)
      if (Mx[i] == -1) Q.push(i), dx[i] = 0;
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
      if (dx[u] > dis) break;
      int sz = G[u].size();
      for (int i = 0; i <= sz - 1; i++) {
        int v = G[u][i];
        if (dy[v] == -1) {
          dy[v] = dx[u] + 1;
          if (My[v] == -1)
            dis = dy[v];
          else {
            dx[My[v]] = dy[v] + 1;
            Q.push(My[v]);
          }
        }
      }
    }
    return dis != inf;
  }
  bool dfs(int u) {
    for (auto v : G[u]) {
      if (!used[v] && dy[v] == dx[u] + 1) {
        used[v] = true;
        if (My[v] != -1 && dy[v] == dis) continue;
        if (My[v] == -1 || dfs(My[v])) {
          My[v] = u;
          Mx[u] = v;
          return true;
        }
      }
    }
    return false;
  }
  int MaxMatch() {
    int res = 0;
    for (int i = 0; i <= uN - 1; i++) Mx[i] = My[i] = -1;
    while (SearchP()) {
      for (int i = 0; i <= uN - 1; i++) used[i] = 0;
      for (int i = 0; i <= uN - 1; i++) {
        if (Mx[i] == -1 && dfs(i)) res++;
      }
    }
    return res;
  }
} hk;
bool ok(int up) {
  hk.init();
  for (int i = 1; i <= m; i++)
    if (z[i] <= up) hk.G[x[i] - 1].push_back(y[i] - 1);
  return hk.MaxMatch() == n;
}
int main() {
  std::ios::sync_with_stdio(false), cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) cin >> x[i] >> y[i] >> z[i];
  int l = 1, r = 1e9 + 1;
  int ans = l;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ok(mid))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  if (ans > 1e9)
    cout << "-1\n";
  else
    cout << ans << '\n';
  return 0;
}
