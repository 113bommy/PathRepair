#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int MX = 1e8 + 5;
int vsz;
long long val[N / 10], sumval[N / 10];
long long calc(long long n) {
  int p = upper_bound(val, val + vsz, n) - val;
  return n * p - sumval[p - 1];
}
vector<pair<int, int> > adj[N], radj[N], sadj[N];
vector<int> ord;
int vis[N], scc[N];
long long score[N];
void dfs_ord(int v) {
  vis[v] = 1;
  for (auto it : adj[v]) {
    if (not vis[it.first]) dfs_ord(it.first);
  }
  ord.push_back(v);
}
void dfs_scc(int v, int k) {
  scc[v] = k;
  for (auto it : radj[v]) {
    if (scc[it.first]) {
      if (scc[it.first] != k) {
        sadj[scc[it.first]].push_back(make_pair(k, it.second));
      } else {
        score[k] += calc(it.second);
      }
    } else {
      dfs_scc(it.first, k);
      score[k] += calc(it.second);
    }
  }
}
long long dp[N];
long long fun(int v) {
  long long &memo = dp[v];
  if (memo != -1) return memo;
  long long ans = 0;
  for (auto it : sadj[v]) {
    ans = max(ans, it.second + fun(it.first));
  }
  return memo = ans + score[v];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  val[0] = sumval[0] = 0;
  vsz = 1;
  for (int i = 1; val[i - 1] < MX; i++) {
    val[i] = val[i - 1] + i;
    sumval[i] = sumval[i - 1] + val[i];
    vsz++;
  }
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back(make_pair(b, c));
    radj[b].push_back(make_pair(a, c));
  }
  for (int i = 1; i <= n; i++) {
    if (not vis[i]) dfs_ord(i);
  }
  reverse(ord.begin(), ord.end());
  int kc = 0;
  for (auto it : ord) {
    if (not scc[it]) dfs_scc(it, ++kc);
  }
  int s;
  cin >> s;
  memset(dp, -1, sizeof dp);
  cout << fun(scc[s]) << "\n";
  return 0;
}
