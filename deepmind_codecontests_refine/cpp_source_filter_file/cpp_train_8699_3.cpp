#include <bits/stdc++.h>
using namespace std;
void GO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
}
const long long INF = 1e9 + 7;
const long long mod = (1e9);
const int maxn = (int)1e7 + 1;
const long double PI = acos(-1.0);
const long double eps = 0.000000001;
mt19937 rnd(time(0));
int n, k;
vector<vector<int> > g;
vector<int> dp;
set<int> st;
vector<int> mas;
int s;
void dfs(int v, int p = -1) {
  if (st.count(v)) dp[v] = 1;
  for (auto to : g[v]) {
    if (to == p) continue;
    dfs(to, v);
    dp[v] += dp[to];
  }
}
void dfs_make(int v, int p) {
  if (st.count(v)) mas.push_back(v);
  for (auto to : g[v]) {
    if (to == p) continue;
    dfs_make(to, v);
  }
}
void dfs_ans(int v, int p = -1) {
  for (auto to : g[v]) {
    if (to == p) continue;
    if (dp[to] > k) {
      dfs_ans(to, v);
      return;
    }
  }
  s = v;
  for (auto to : g[v]) dfs_make(to, v);
  if (st.count(v)) mas.push_back(v);
}
void solve() {
  cin >> n >> k;
  g.resize(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dp.resize(n);
  for (int i = 0; i < 2 * k; ++i) {
    int c;
    cin >> c;
    st.insert(c - 1);
  }
  dfs(0), dfs_ans(0);
  cout << "1\n" << s + 1 << '\n';
  for (int i = 0; i < k; ++i) {
    cout << mas[i] + 1 << ' ' << mas[i + k] + 1 << ' ' << s << '\n';
  }
}
signed main() {
  GO();
  int Q = 1;
  while (Q--) {
    solve();
  }
}
