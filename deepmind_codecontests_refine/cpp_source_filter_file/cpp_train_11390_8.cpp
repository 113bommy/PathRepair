#include <bits/stdc++.h>
using namespace std;
const int maxn = 500000 + 100;
int n;
vector<int> adj[maxn];
int st[maxn], ed[maxn], now;
void dfs(int v, int par) {
  st[v] = now++;
  for (auto u : adj[v])
    if (u != par) dfs(u, v);
  ed[v] = now;
}
int mg[maxn * 3];
void change(int x, int l, int r, int L, int R, int val) {
  if (r <= L || R <= l) return;
  if (L <= l && r <= R) {
    mg[x] = val;
    return;
  }
  if (mg[x] != -1) mg[2 * x + 1] = mg[2 * x + 2] = mg[x];
  mg[x] = -1;
  int md = (l + r) / 2;
  change(2 * x + 1, l, md, L, R, val);
  change(2 * x + 2, md, r, L, R, val);
}
int getval(int x, int l, int r, int pos) {
  if (r <= pos || pos < l) return 0;
  if (r - l == 1) return mg[x];
  if (mg[x] != -1) mg[2 * x + 1] = mg[2 * x + 2] = mg[x];
  mg[x] = -1;
  int md = (l + r) / 2;
  return getval(2 * x + 1, l, md, pos) + getval(2 * x + 2, md, r, pos);
}
int mx[maxn * 3];
void setit(int x, int l, int r, int pos, int val) {
  if (r <= pos || pos < l) return;
  mx[x] = val;
  if (r - l == 1) return;
  int md = (l + r) / 2;
  setit(2 * x + 1, l, md, pos, val);
  setit(2 * x + 2, md, r, pos, val);
}
int getmax(int x, int l, int r, int L, int R) {
  if (r <= L || R <= l) return 0;
  if (L <= l && r <= R) return mx[x];
  int md = (l + r) / 2;
  return max(getmax(2 * x + 1, l, md, L, R), getmax(2 * x + 2, md, r, L, R));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0, _n = (int)(n - 1); i < _n; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(0, -1);
  int q;
  cin >> q;
  for (int z = (int)(1), _n = (int)(q + 1); z < _n; z++) {
    int type, v;
    cin >> type >> v;
    v--;
    if (type == 1) change(0, 0, n, st[v], ed[v], z);
    if (type == 2) setit(0, 0, n, st[v], z);
    if (type == 3)
      cout << (getval(0, 0, n, st[v]) < getmax(0, 0, n, st[v], ed[v]) ? 0 : 1)
           << endl;
  }
  {
    int _;
    cin >> _;
    return 0;
  }
}
