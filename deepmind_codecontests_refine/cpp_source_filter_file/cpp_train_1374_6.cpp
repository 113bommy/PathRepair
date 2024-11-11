#include <bits/stdc++.h>
using namespace std;
const long long MAX = (long long)2e6 + 100;
long long inf = (long long)1e18;
long long mod = (long long)1e9 + 7;
long long n, m, used[MAX];
vector<long long> gr[MAX][2];
vector<long long> h, c;
void out() {
  cout << "Yes\n";
  cout << h.size() << " " << c.size() << "\n";
  for (int i = 0; i < h.size(); i++) cout << h[i] << " ";
  cout << "\n";
  for (int i = 0; i < c.size(); i++) cout << c[i] << " ";
  cout << "\n";
}
void push(long long vert, long long clr) {
  if (clr == 1)
    h.push_back(vert);
  else
    c.push_back(vert);
}
void bfs(long long v, long long clr) {
  queue<long long> verts;
  verts.push(v);
  used[v] = 1;
  push(v, clr);
  while (verts.size()) {
    long long v = verts.front();
    verts.pop();
    for (auto u : gr[v][clr ^ 1]) {
      if (!used[u]) {
        used[u] = 1;
        push(u, clr);
        verts.push(u);
      }
    }
  }
}
void clear() {
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 2; j++) gr[i][j].clear();
    used[i] = 0;
  }
  h.clear();
  c.clear();
}
void solve() {
  cin >> n >> m;
  clear();
  for (int i = 1; i <= m; i++) {
    long long a, b;
    cin >> a >> b;
    gr[a][1].push_back(b);
    gr[b][0].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      if (i == 1)
        bfs(i, 1);
      else
        bfs(i, 0);
    }
  }
  if (h.size() == n) {
    h.clear();
    c.clear();
    for (int i = 1; i <= n; i++) used[i] = 0;
    for (int i = 1; i <= n; i++) {
      if (!used[i]) {
        if (i == 1)
          bfs(i, 0);
        else
          bfs(i, 1);
      }
    }
  } else {
    out();
    return;
  }
  if (c.size() == n) {
    cout << "No\n";
    return;
  } else
    out();
}
int main() {
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  long long q;
  ios::sync_with_stdio(0);
  cin >> q;
  while (q--) solve();
  return 0;
}
