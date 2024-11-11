#include <bits/stdc++.h>
const int INF = 1e9 + 23;
using namespace std;
struct Edge {
  int to, num;
  Edge(int to = -1, int num = -1) : to(to), num(num){};
};
int n, m, h;
vector<int> u, comp, ts;
vector<vector<Edge>> g, tg, cg;
vector<bool> used;
void dfsTS(int v) {
  used[v] = true;
  for (auto& e : g[v])
    if (!used[e.to]) dfsTS(e.to);
  ts.push_back(v);
}
void dfsCond(int v, int cmp) {
  comp[v] = cmp;
  for (auto& e : tg[v]) {
    if (comp[e.to] == -1) {
      dfsCond(e.to, cmp);
    } else if (comp[v] != comp[e.to]) {
      cg[comp[e.to]].emplace_back(comp[v]);
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  cin >> n >> m >> h;
  u.resize(n);
  for (auto& el : u) cin >> el;
  g.resize(n);
  tg.resize(n);
  used.resize(n);
  comp.resize(n, -1);
  for (int i = 0; i < m; i++) {
    int c1, c2;
    cin >> c1 >> c2;
    c1--;
    c2--;
    if ((u[c1] + 1) % h == u[c2]) {
      g[c1].emplace_back(c2);
      tg[c2].emplace_back(c1);
    }
    if ((u[c2] + 1) % h == u[c1]) {
      g[c2].emplace_back(c1);
      tg[c1].emplace_back(c2);
    }
  }
  for (int i = 0; i < n; i++) {
    if (!used[i]) dfsTS(i);
  }
  reverse(ts.begin(), ts.end());
  int ccnt = 0;
  for (int v = 0; v < n; v++) {
    if (comp[v] == -1) {
      cg.emplace_back();
      dfsCond(v, ccnt++);
    }
  }
  used.assign(cg.size(), false);
  int num = -1;
  vector<int> cnt(cg.size());
  for (int v = 0; v < n; v++) {
    cnt[comp[v]]++;
  }
  for (int v = 0; v < n; v++) {
    if (cg[comp[v]].empty() && (num == -1 || cnt[comp[v]] < cnt[num]))
      num = comp[v];
  }
  cout << cnt[num] << '\n';
  for (int i = 0; i < n; i++) {
    if (comp[i] == num) cout << i + 1 << ' ';
  }
}
