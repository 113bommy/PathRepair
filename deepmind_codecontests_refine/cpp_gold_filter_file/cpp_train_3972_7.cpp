#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
const int offset = 3e5;
struct TNode {
  int par, cntL, cntR;
} par[maxn << 1];
vector<tuple<int, int, int, int, int, int64_t> > History;
int64_t res = 0;
vector<pair<int, int> > st[maxn << 2];
int root(int u) {
  while (par[u].par != u) u = par[u].par;
  return u;
}
void update(int id, int l, int r, int u, int v, pair<int, int> edge) {
  if (l > v || r < u) return;
  if (u <= l && r <= v) {
    st[id].push_back(edge);
    return;
  }
  int mid = (l + r) >> 1;
  update(id << 1, l, mid, u, v, edge);
  update(id << 1 | 1, mid + 1, r, u, v, edge);
}
void join(int r, int child) {
  History.push_back(
      make_tuple(child, par[child].par, r, par[r].cntL, par[r].cntR, res));
  if (r == child) return;
  res -= 1ll * par[child].cntL * par[child].cntR;
  res -= 1ll * par[r].cntL * par[r].cntR;
  par[child].par = r;
  par[r].cntL += par[child].cntL;
  par[r].cntR += par[child].cntR;
  res += 1ll * par[r].cntL * par[r].cntR;
}
void RollBack(int id) {
  for (int i = 0, tmp = st[id].size(); i < tmp; ++i) {
    int child, p, r, cntL, cntR;
    tie(child, p, r, cntL, cntR, res) = History.back();
    History.pop_back();
    par[child].par = p;
    par[r].cntL = cntL;
    par[r].cntR = cntR;
  }
}
void Insert(int id) {
  for (pair<int, int> edge : st[id]) {
    int r1 = root(edge.first), r2 = root(edge.second + offset);
    if (par[r1].cntL + par[r1].cntR > par[r2].cntL + par[r2].cntR)
      join(r1, r2);
    else
      join(r2, r1);
  }
}
void DFS(int id, int l, int r) {
  Insert(id);
  if (l == r) {
    cout << res << ' ';
    return void(RollBack(id));
  }
  int mid = (l + r) >> 1;
  DFS(id << 1, l, mid);
  DFS(id << 1 | 1, mid + 1, r);
  return void(RollBack(id));
}
int main() {
  clock_t STARTTIME = clock();
  iostream::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 1; i <= offset + offset; ++i)
    if (i <= offset)
      par[i] = {i, 1, 0};
    else
      par[i] = {i, 0, 1};
  int q;
  cin >> q;
  map<pair<int, int>, int> cur;
  for (int i = 1; i <= q; ++i) {
    int x, y;
    cin >> x >> y;
    if (cur.count({x, y})) {
      update(1, 1, q, cur[{x, y}], i - 1, {x, y});
      cur.erase({x, y});
    } else
      cur[{x, y}] = i;
  }
  for (auto x : cur) update(1, 1, q, x.second, q, x.first);
  DFS(1, 1, q);
  return 0;
}
