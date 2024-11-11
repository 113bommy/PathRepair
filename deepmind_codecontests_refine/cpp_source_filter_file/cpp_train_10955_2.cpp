#include <bits/stdc++.h>
using namespace std;
const int INF = (int)2e9;
const long long INFL = (long long)9e18;
const int MAXINT = ((~0) ^ (1 << 31));
const long long MAXLL = ((~0) ^ ((long long)1 << 63));
template <class T>
inline T pow2(T a) {
  return a * a;
}
template <class T>
inline bool mineq(T& a, T b) {
  return (a > b) ? (a = b, true) : false;
}
template <class T>
inline bool maxeq(T& a, T b) {
  return (a < b) ? (a = b, true) : false;
}
const int maxn = 2e5;
long long n, v, u, mark[maxn], dp[maxn][2], flg, ans;
vector<long long> g[maxn];
void dfs(long long v) {
  mark[v] = 1;
  long long cnt = 0;
  for (int i = 0; i < g[v].size(); i++) {
    if (!mark[g[v][i]]) {
      if (g[g[v][i]].size() == 1) {
        cnt++;
        dp[v][1]++;
      }
      dfs(g[v][i]);
      dp[v][0] += dp[g[v][i]][1];
      dp[v][1] += dp[g[v][i]][0];
    }
  }
  ans -= max((long long)0, cnt - 1);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> v >> u;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  ans = n - 1;
  for (int i = 1; i <= n; i++) {
    if (g[v].size() != 1) {
      dfs(v);
      if (dp[v][0] && dp[v][1]) flg = 1;
      break;
    }
  }
  if (flg)
    cout << 3 << " ";
  else
    cout << 1 << " ";
  cout << ans;
}
