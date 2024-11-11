#include <bits/stdc++.h>
using namespace std;
vector<string> split(const string& s, char c) {
  vector<string> v;
  stringstream ss(s);
  string x;
  while (getline(ss, x, c)) v.emplace_back(x);
  return move(v);
}
void err(vector<string>::iterator it) {}
template <typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
  cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\t';
  err(++it, args...);
}
const int NN = 2e5;
int dp[NN][2], k;
vector<int> adj[NN], cost[NN];
void recur(int u, int par) {
  int i, ret, v, no_ret, c = u > 0 ? adj[u].size() - 1 : adj[u].size(),
                         m = min(c, k - 1), h = min(k - 1, c - 1);
  ret = 0;
  vector<pair<int, int> > pro;
  for (i = 0; i < adj[u].size(); i++) {
    v = adj[u][i];
    if (v != par) {
      recur(adj[u][i], u);
      dp[v][0] += cost[u][i];
      dp[v][1] += cost[u][i];
      pro.emplace_back(dp[v][0], dp[v][1]);
    }
  }
  sort(pro.begin(), pro.end());
  for (i = 0; i < m; i++) {
    ret += pro[i].first;
  }
  int sum = 0, mxx = 0;
  for (i = 0; i < h; i++) {
    sum += pro[i].first;
  }
  for (; i < pro.size(); i++) {
    mxx = max(mxx, pro[i].second);
  }
  no_ret = sum + mxx;
  for (i = h - 1; i >= 0; i--) {
    sum = sum - pro[i].first + pro[i + 1].first;
    no_ret = max(no_ret, sum + pro[i].second);
  }
  dp[u][0] = ret;
  dp[u][1] = no_ret;
}
int main() {
  int n, i, j, m, t, u, v;
  cin >> n >> k;
  for (i = 0; i < n - 1; i++) {
    cin >> u >> v >> t;
    adj[u].push_back(v);
    adj[v].push_back(u);
    cost[u].push_back(t);
    cost[v].push_back(t);
  }
  recur(0, -1);
  m = max(dp[0][0], dp[0][1]);
  cout << m;
  return 0;
}
