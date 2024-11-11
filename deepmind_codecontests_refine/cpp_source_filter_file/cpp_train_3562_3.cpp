#include <bits/stdc++.h>
const int LG = 21;
const int N = 500005;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long long INFLL = 1e18;
using namespace std;
void dfs(int v, int paint, vector<int> &col,
         vector<vector<pair<int, int> > > &graph, vector<int> &need, int &cnt0,
         int &cnt1, int &fl) {
  col[v] = paint;
  if (paint == -1)
    cnt0++;
  else
    cnt1++;
  if (need[v] != 0) {
    if (paint == need[v])
      fl = 1;
    else
      fl = -1;
  }
  for (auto p : graph[v]) {
    if (col[p.first] == 0) {
      dfs(p.first, p.second * paint, col, graph, need, cnt0, cnt1, fl);
    }
  }
}
int root[N];
vector<int> suns[N];
int cntsame[N];
int sametoroot[N];
int fl[N];
int ans;
int Root(int x) { return root[x] == x ? x : Root(root[x]); }
void complete_data(int v, int FL) {
  int x = Root(v);
  if (fl[v] != 0) return;
  FL *= sametoroot[v];
  int took_before = min(cntsame[x], (int)suns[x].size() - cntsame[x]);
  ans -= took_before;
  fl[x] = FL;
  if (FL == 1)
    ans += cntsame[x];
  else
    ans += suns[x].size() - cntsame[x];
}
void Merge(int v, int u, int w) {
  int x = Root(v), y = Root(u);
  if (x == y) return;
  if (suns[x].size() > suns[y].size()) {
    swap(v, u);
    swap(x, y);
  }
  w *= sametoroot[v];
  w *= sametoroot[u];
  if (fl[x] == 0 && fl[y] == 0) {
    ans -= min(cntsame[x], (int)suns[x].size() - cntsame[x]);
    ans -= min(cntsame[y], (int)suns[y].size() - cntsame[y]);
  }
  if (fl[x] == 0 && fl[y] != 0) {
    complete_data(x, fl[y] * w);
  }
  if (fl[x] != 0 && fl[y] == 0) {
    complete_data(y, fl[x] * w);
  }
  for (auto u : suns[x]) {
    suns[y].push_back(u);
    sametoroot[u] *= w;
    if (sametoroot[u] == 1) cntsame[y]++;
  }
  if (fl[x] == 0 && fl[y] == 0) {
    ans += min(cntsame[y], (int)suns[y].size() - cntsame[y]);
  }
  root[x] = y;
}
signed main() {
  srand(time(NULL));
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<vector<int> > contains(n);
  for (int i = 0; i < k; i++) {
    int c;
    cin >> c;
    for (int j = 0; j < c; j++) {
      int x = 0;
      cin >> x;
      x--;
      contains[x].push_back(i);
    }
  }
  vector<vector<pair<int, int> > > graph(k);
  vector<int> need(k, 0);
  for (int i = 0; i < k; i++) root[i] = i;
  for (int i = 0; i < k; i++) suns[i].push_back(i);
  for (int i = 0; i < k; i++) cntsame[i] = 1;
  for (int i = 0; i < k; i++) sametoroot[i] = 1;
  for (int i = 0; i < n; i++) {
    if (contains[i].size() == 1) {
      if (s[i] == '1') {
        need[contains[i][0]] = -1;
        complete_data(contains[i][0], -1);
      } else {
        need[contains[i][0]] = 1;
        complete_data(contains[i][0], 1);
      }
    }
    if (contains[i].size() == 2) {
      if (s[i] == '0') {
        graph[contains[i][0]].push_back({contains[i][1], -1});
        graph[contains[i][1]].push_back({contains[i][0], -1});
        Merge(contains[i][0], contains[i][1], -1);
      } else {
        graph[contains[i][0]].push_back({contains[i][1], 1});
        graph[contains[i][1]].push_back({contains[i][0], 1});
        Merge(contains[i][0], contains[i][1], 1);
      }
    }
    cout << ans << endl;
  }
}
