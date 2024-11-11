#include <bits/stdc++.h>
using namespace std;
const int nax = 2 * (int)1e5 + 10;
const int INF = (int)1e9 + 47;
vector<int> g[nax];
int n, k;
int lvl[nax], tin[nax], tout[nax];
int cnt = 0;
int timer = 0;
int ver[nax];
int seen[nax];
int par[nax];
int vr[nax];
vector<pair<int, int>> vec;
void dfs(int v, int p = -1) {
  if (p != -1) lvl[v] = lvl[p] + 1;
  vec.push_back({lvl[v], v});
  par[v] = p;
  if (g[v].size() == 1 && p != -1) cnt++;
  if (p != -1) lvl[v] = lvl[p] + 1;
  for (auto to : g[v]) {
    if (to == p) continue;
    dfs(to, v);
  }
}
long long f(int red, int blue) {
  int w = n - red - blue;
  return w * 1ll * (red - blue);
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0);
  sort(vec.begin(), vec.end(), greater<pair<int, int>>());
  vector<int> vv;
  for (int i = 0; i < n; i++) {
    int cur = vec[i].second;
    int cc = 0;
    while (cur != -1 && !seen[cur]) {
      cc++;
      seen[cur] = 1;
      cur = par[cur];
    }
    vv.push_back(cc);
  }
  sort(vv.begin(), vv.end(), greater<int>());
  int blue = n;
  long long best_ans = -(int)1e18;
  for (int i = 0; i < min(k, cnt); i++) {
    blue -= vv[i];
    int l = 0, r = blue;
    for (int it = 0; it < 40; it++) {
      int mid = (l + r) / 2;
      if (f(i + 1, mid + 1) <= f(i + 1, mid))
        l = mid;
      else
        r = mid;
    }
    if ((f(i + 1, r) > f(i + 1, r + 1) && r + 1 < blue) ||
        (f(i + 1, r - 1) < f(i + 1, r) && r - 1 >= 0))
      throw 47;
    best_ans = max(best_ans, f(i + 1, r));
  }
  while (cnt <= k) {
    best_ans = max(best_ans, (n - cnt) * 1ll * cnt);
    cnt++;
  }
  cout << best_ans << '\n';
}
