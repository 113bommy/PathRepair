#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 1000;
vector<int> g[maxn];
int low[maxn], dfn[maxn];
int scc[maxn];
int sta[maxn];
bool vis[maxn];
int num = 0, ind = 0;
int cnt = 0;
int n, p, M, m;
int tol;
int fid(int x) { return p + x; }
int yid(int x) { return 2 * x - 1; }
int nid(int x) { return 2 * x; }
void tarjan(int u) {
  vis[u] = 1;
  dfn[u] = low[u] = ++num;
  sta[++ind] = u;
  for (auto i : g[u]) {
    if (!dfn[i]) {
      tarjan(i);
      low[u] = min(low[u], low[i]);
    } else if (vis[i]) {
      low[u] = min(low[u], low[i]);
    }
  }
  if (dfn[u] == low[u]) {
    ++cnt;
    do {
      vis[sta[ind]] = 0;
      scc[sta[ind]] = cnt;
      --ind;
    } while (u != sta[ind + 1]);
  }
}
int ans[maxn];
int f;
void _2sat() {
  tol = (p + M) * 2;
  for (int i = 1; i <= tol; ++i) {
    if (!dfn[i]) {
      tarjan(i);
    }
  }
  int ft = 0;
  for (int i = 1; i <= p; ++i) {
    int yx = yid(i), nx = nid(i);
    if (scc[yx] == scc[nx]) {
      cout << -1 << endl;
      return;
    }
    if (scc[yx] < scc[nx]) {
      ans[ft++] = i;
    }
  }
  for (int i = 1; i <= M; ++i) {
    int yx = yid(fid(i)), nx = nid(fid(i));
    if (scc[yx] == scc[nx]) {
      cout << -1 << endl;
      return;
    }
    if (scc[yx] < scc[nx]) {
      f = i;
    }
  }
  cout << ft << " " << f << endl;
  for (int i = 0; i < ft; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> p >> M >> m;
  int a, b;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    g[nid(a)].push_back(yid(b));
    g[nid(b)].push_back(yid(a));
  }
  for (int i = 1; i <= p; ++i) {
    cin >> a >> b;
    g[yid(i)].push_back(yid(fid(a)));
    g[nid(fid(a))].push_back(nid(i));
    if (b + 1 <= M) {
      g[yid(i)].push_back(nid(fid(b + 1)));
      g[yid(fid(b + 1))].push_back(nid(i));
    }
  }
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    g[yid(a)].push_back(nid(b));
    g[yid(b)].push_back(nid(a));
  }
  for (int i = 1; i < M; ++i) {
    g[nid(fid(i))].push_back(nid(fid(i + 1)));
    g[yid(fid(i + 1))].push_back(yid(fid(i)));
  }
  _2sat();
  return 0;
}
