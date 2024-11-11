#include <bits/stdc++.h>
using namespace std;
vector<string> vec_splitter(string s) {
  s += ',';
  vector<string> res;
  while (!s.empty()) {
    res.push_back(s.substr(0, s.find(',')));
    s = s.substr(s.find(',') + 1);
  }
  return res;
}
void debug_out(vector<string> __attribute__((unused)) args,
               __attribute__((unused)) int idx,
               __attribute__((unused)) int LINE_NUM) {
  cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
  if (idx > 0)
    cerr << ", ";
  else
    cerr << "Line(" << LINE_NUM << ") ";
  stringstream ss;
  ss << H;
  cerr << args[idx] << " = " << ss.str();
  debug_out(args, idx + 1, LINE_NUM, T...);
}
const int MOD = 1e9 + 7;
const long long INF = 1e18;
const int MAXN = 1 << 21;
vector<pair<int, int> > adj[MAXN];
const int MAXM = 5e5 + 5;
pair<int, int> edges[MAXM];
bool vis[MAXN];
bool used[MAXN];
void dfs(int c) {
  vis[c] = true;
  for (auto& v : adj[c]) {
    if (!vis[v.first]) {
      dfs(v.first);
    }
  }
}
int opp(int c) {
  if (c & 1) return c + 1;
  return (c ^ 1) - 2;
}
void construct(vector<int>& ans, int c, int p = -1) {
  while (adj[c].size()) {
    pair<int, int> e = adj[c].back();
    adj[c].pop_back();
    if (!used[e.second]) {
      used[e.second] = true;
      used[opp(e.second)] = true;
      construct(ans, e.first, e.second);
    }
  }
  if (p >= 0) {
    ans.push_back(p);
    ans.push_back(opp(p));
  }
}
bool graph(int lvl, int alvl, int n) {
  for (int i = 0; i <= lvl; i++) {
    adj[i].clear();
    vis[i] = false;
  }
  for (int i = 0; i < n; i++) {
    int a = edges[i].first & lvl;
    int b = edges[i].second & lvl;
    adj[a].push_back({b, 2 * i + 2});
    adj[b].push_back({a, 2 * i + 1});
  }
  int cmp = 0;
  int second = -1;
  bool works = true;
  for (int i = 0; i <= lvl; i++) {
    if (adj[i].size() && !vis[i]) {
      second = i;
      cmp++;
      dfs(i);
    }
    works &= (adj[i].size() + 1) & 1;
  }
  42;
  if (cmp == 1 && works) {
    vector<int> ans;
    construct(ans, second);
    cout << alvl << '\n';
    ;
    for (auto& v : ans) cout << v << " ";
    cout << '\n';
    ;
    return true;
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> edges[i].first >> edges[i].second;
  }
  for (int l = 20; l > 0; l--) {
    if (graph((1 << l) - 1, l, n)) {
      break;
    }
  }
}
