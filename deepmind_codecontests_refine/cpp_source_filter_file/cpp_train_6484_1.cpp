#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n, mxdeg, ok[N * N], cnt, tot;
vector<int> v[N * N];
queue<int> q;
bool vis[N * N];
void add_edge(int uu, int vv) {
  v[uu].push_back(vv);
  v[vv].push_back(uu);
}
void dfs(int pos, int fa = -1) {
  if (vis[pos]) {
    cout << "SICK" << endl;
    exit(0);
  }
  vis[pos] = 1;
  if (v[pos].size() == 3) mxdeg = 1;
  if (!~ok[N]) ++cnt;
  ++tot;
  for (auto &i : v[pos])
    if (i != fa) dfs(i, pos);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  int cc = 0;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
    x += 2;
    y += 2;
    int id = x * N + y;
    auto proc = [&](int nx, int ny) {
      if (ok[nx * N + ny] < 0)
        cc -= 2, add_edge(id, nx * N + ny);
      else
        ++ok[nx * N + ny];
    };
    cc += 3;
    proc(x + 1, y);
    proc(x - 1, y);
    if (x & 1)
      proc(x - 1, y + 1);
    else
      proc(x + 1, y - 1);
    ok[id] = -1;
  }
  for (int i = 0; i < N * N; i++)
    if (ok[i] >= 2) q.push(i);
  while (!q.empty()) {
    int nd = q.front();
    q.pop();
    int x = nd / N, y = nd - x * N;
    auto proc = [&](int nx, int ny) {
      int nid = nx * N + ny;
      if (ok[nid] < 0)
        add_edge(nd, nid);
      else if (++ok[nid] == 2)
        q.push(nid);
    };
    proc(x + 1, y);
    proc(x - 1, y);
    if (x & 1)
      proc(x - 1, y + 1);
    else
      proc(x + 1, y - 1);
    ok[nd] = -2;
  }
  for (int i = 0; i < N * N; i++)
    if (!~ok[i] && !vis[i]) {
      tot = cnt = mxdeg = 0;
      dfs(i);
      cc -= 2;
      if (cnt == 3 && tot == 4 && mxdeg) cc -= 2;
    }
  cout << "RECOVERED" << endl << cc << endl;
  return 0;
}
