#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5, inf = INT_MAX / 4;
int n, m, x[MAXN], y[MAXN], c[MAXN], t[MAXN], cmp[MAXN], cnt;
vector<int> adj[MAXN], in[MAXN], out[MAXN], tmp;
vector<pair<int, int>> es;
map<pair<int, int>, int> e1, e2;
bool mark[MAXN];
inline void add(int u, int v) {
  out[u].push_back(v);
  in[v].push_back(u);
  return;
}
void dfs(int v) {
  mark[v] = true;
  for (int u : out[v])
    if (!mark[u]) dfs(u);
  tmp.push_back(v);
  return;
}
void dfs2(int v) {
  mark[v] = true;
  cmp[v] = cnt;
  for (int u : in[v])
    if (!mark[u]) dfs2(u);
  return;
}
inline bool check(int w) {
  tmp.clear();
  cnt = 0;
  for (int i = 0; i < MAXN; i++) {
    in[i].clear();
    out[i].clear();
    mark[i] = false;
    cmp[i] = 0;
  }
  for (int i = 0; i < m; i++)
    if (t[i] > w) add(i * 2 + 1, i * 2);
  for (auto i : es) {
    add(i.first * 2, i.second * 2 + 1);
    add(i.second * 2, i.first * 2 + 1);
  }
  int last = m, pre;
  for (int i = 0; i < n; i++) {
    if (adj[i].empty()) continue;
    pre = adj[i][0];
    for (int j = 1; j < (int)adj[i].size(); j++) {
      int ind = adj[i][j];
      add(pre * 2 + 1, last * 2 + 1);
      add(last * 2, pre * 2);
      add(ind * 2 + 1, last * 2 + 1);
      add(last * 2, ind * 2);
      add(pre * 2 + 1, ind * 2);
      add(ind * 2 + 1, pre * 2);
      pre = last;
      last++;
    }
  }
  for (int i = 0; i < last * 2; i++)
    if (!mark[i]) dfs(i);
  for (int i = 0; i < MAXN; i++) mark[i] = 0;
  reverse(tmp.begin(), tmp.end());
  for (int v : tmp)
    if (!mark[v]) {
      cnt++;
      dfs2(v);
    }
  for (int i = 0; i < last; i++)
    if (cmp[i * 2] == cmp[i * 2 + 1]) return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> x[i] >> y[i] >> c[i] >> t[i];
    x[i]--;
    y[i]--;
    adj[x[i]].push_back(i);
    adj[y[i]].push_back(i);
    if (e2[{c[i], x[i]}] || e2[{c[i], y[i]}]) {
      cout << "No" << endl;
      return 0;
    }
    swap(e1[{c[i], x[i]}], e2[{c[i], x[i]}]);
    e1[{c[i], x[i]}] = i + 1;
    swap(e1[{c[i], y[i]}], e2[{c[i], y[i]}]);
    e1[{c[i], y[i]}] = i + 1;
    if (e2[{c[i], x[i]}])
      es.push_back({e1[{c[i], x[i]}] - 1, e2[{c[i], x[i]}] - 1});
    if (e2[{c[i], y[i]}])
      es.push_back({e1[{c[i], y[i]}] - 1, e2[{c[i], y[i]}] - 1});
  }
  if (!check(inf)) {
    cout << "No" << endl;
    return 0;
  }
  int l = -1, r = inf;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  check(r);
  vector<int> ans;
  for (int i = 0; i < m; i++)
    if (cmp[i * 2] < cmp[i * 2 + 1]) ans.push_back(i + 1);
  cout << "Yes" << endl << r << " " << (int)ans.size() << endl;
  for (int i : ans) cout << i << " ";
  cout << endl;
  return 0;
}
