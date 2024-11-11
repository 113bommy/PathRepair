#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m;
struct Edge {
  int s, t, v;
} a[100005];
vector<int> g[N];
int deg[N], ind[N];
queue<int> q;
void init() {
  for (int i = 1; i <= n; i++) g[i].clear(), deg[i] = 0, ind[i] = 0;
}
bool check(int x) {
  init();
  for (int i = 1; i <= m; i++) {
    if (a[i].v <= x) continue;
    g[a[i].s].push_back(a[i].t);
    deg[a[i].t]++;
  }
  int tot = 0;
  for (int i = 1; i <= n; i++) {
    if (deg[i]) continue;
    q.push(i);
    ind[i] = ++tot;
  }
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (auto u : g[v]) {
      deg[u]--;
      if (deg[u] == 0) {
        ind[u] = ++tot;
        q.push(u);
      }
    }
  }
  for (int i = 1; i <= n; i++)
    if (deg[i] > 0) return false;
  return true;
}
void slove(int x) {
  check(x);
  int ans[N];
  int num = 0;
  for (int i = 1; i <= m; i++)
    if (a[i].v <= x && ind[a[i].s] > ind[a[i].t]) ans[num++] = i;
  cout << num << ' ' << x << endl;
  for (int i = 0; i < num; i++) cout << ans[i] << ' ';
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  int x, y, z;
  for (int i = 1; i <= m; i++) {
    cin >> x >> y >> z;
    a[i] = Edge{x, y, z};
  }
  int l = 0, r = 6, ans = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  slove(ans);
}
