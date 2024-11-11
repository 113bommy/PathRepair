#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj1[N], adj2[N], cmp[N], topol;
int n, m, a[N], dp[N], cnt[N], col[N];
bool mark[N];
string s[N];
void dfs1(int u) {
  mark[u] = true;
  for (auto v : adj1[u])
    if (!mark[v]) dfs1(v);
  topol.push_back(u);
}
void dfs2(int u, int c) {
  mark[u] = true, cmp[col[u] = c].push_back(u);
  for (auto v : adj2[u])
    if (!mark[v]) dfs2(v, c);
}
void dfs3(int c) {
  int x = cmp[c][0];
  for (auto u : cmp[c]) {
    if (make_pair(cnt[u], s[u].size()) < make_pair(cnt[x], s[x].size())) x = u;
    mark[u] = true;
  }
  for (auto u : cmp[c])
    for (auto v : adj1[u]) {
      if (!mark[v]) dfs3(col[v]);
      if (make_pair(cnt[dp[v]], s[dp[v]].size()) <
          make_pair(cnt[x], s[x].size()))
        x = dp[v];
    }
  for (auto u : cmp[c]) dp[u] = x;
}
int get_id(string x) {
  static map<string, int> id;
  for (auto &c : x) c = tolower(c);
  if (id.count(x)) return id[x];
  for (auto c : x) cnt[n] += (c == 'r');
  return s[n] = x, id[x] = n++;
}
void readInput() {
  cin >> m;
  for (int i = 0; i < m; i++) {
    string x;
    cin >> x;
    a[i] = get_id(x);
  }
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    string x, y;
    cin >> x >> y;
    int u = get_id(x), v = get_id(y);
    adj1[u].push_back(v), adj2[v].push_back(u);
  }
}
void solve() {
  for (int u = 0; u < n; u++)
    if (!mark[u]) dfs1(u);
  memset(mark, false, sizeof mark);
  reverse(topol.begin(), topol.end());
  int tmp = 0;
  for (auto u : topol)
    if (!mark[u]) dfs2(u, tmp++);
  memset(mark, false, sizeof mark);
  for (int u = 0; u < n; u++)
    if (!mark[u]) dfs3(col[u]);
}
void writeOutput() {
  long r = 0, len = 0;
  for (int i = 0; i < m; i++) r += cnt[dp[a[i]]], len += s[dp[a[i]]].size();
  cout << r << ' ' << len << endl;
}
int main() {
  ios_base ::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  readInput(), solve(), writeOutput();
  return 0;
}
