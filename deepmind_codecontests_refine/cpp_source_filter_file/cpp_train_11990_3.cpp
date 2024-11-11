#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int B = 1e6 + 5;
const int maxn = 1e5 + 5;
const int N = 21;
int n, m, p[maxn], L[maxn];
pair<int, int> sp[maxn][N];
bool vis[B];
pair<int, int> ed[B];
struct edge {
  int w, x, y, ind;
  bool operator<(const edge& b) const { return w < b.w; }
};
vector<edge> adj;
vector<pair<int, int>> E[maxn];
int ata(int nd) {
  if (p[nd] == nd) return nd;
  return p[nd] = ata(p[nd]);
}
void dfs(int nd, int pr) {
  L[nd] = L[pr] + 1;
  for (auto i : E[nd])
    if (i.first != pr) {
      dfs(i.first, nd);
      sp[i.first][0].first = nd;
      sp[i.first][0].second = i.second;
    }
}
int LCA(int a, int b) {
  int jog = 0;
  if (L[b] > L[a]) swap(a, b);
  for (int i = 20; i >= 0; i--) {
    if (L[a] - (1 << i) >= L[b]) {
      jog = max(jog, sp[a][i].second);
      a = sp[a][i].first;
    }
  }
  if (a == b) return jog;
  for (int i = 20; i >= 0; i--) {
    if (sp[a][i].first and sp[b][i].first and
        sp[a][i].first != sp[b][i].first) {
      jog = min(jog, sp[a][i].second);
      jog = min(jog, sp[b][i].second);
      a = sp[a][i].first;
      b = sp[b][i].first;
    }
  }
  jog = min(jog, sp[a][0].second);
  jog = min(jog, sp[b][0].second);
  return jog;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) p[i] = i;
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    ed[i] = {x, y};
    adj.push_back({w, x, y, i});
  }
  sort(adj.begin(), adj.end());
  for (auto i : adj) {
    int a = ata(i.x);
    int b = ata(i.y);
    if (a != b) {
      p[b] = a, vis[i.ind] = 1;
      E[i.x].push_back({i.y, i.w});
      E[i.y].push_back({i.x, i.w});
    }
  }
  dfs(1, 0);
  for (int i = 1; i < N; i++) {
    for (int j = 1; j <= n; j++) {
      sp[j][i].first = sp[sp[j][i - 1].first][i - 1].first;
      sp[j][i].second =
          max(sp[j][i - 1].second, sp[sp[j][i - 1].first][i - 1].second);
    }
  }
  for (int i = 1; i <= m; i++) {
    if (vis[i]) continue;
    cout << LCA(ed[i].first, ed[i].second) << '\n';
  }
}
