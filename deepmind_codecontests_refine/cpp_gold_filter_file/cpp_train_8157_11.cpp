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
const int maxn = 2e2;
long long n, mark[maxn], p[maxn], v, u, t, s[maxn], chk[maxn], flg;
vector<pair<long long, long long> > g[maxn], ans;
pair<long long, long long> e[maxn];
void dfs(long long w, long long id) {
  chk[w] = 1;
  for (p[w]; p[w] < g[w].size(); p[w]++) {
    if (!mark[g[w][p[w]].second]) {
      mark[g[w][p[w]].second] = 1;
      dfs(g[w][p[w]].first, g[w][p[w]].second);
    }
  }
  ans.push_back({w, id});
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v >> u;
    s[v] = 1;
    s[u] = 1;
    g[v].push_back({u, i});
    g[u].push_back({v, i});
    e[i] = {v, u};
  }
  for (int i = 0; i <= 6; i++) {
    if (g[i].size() % 2 != 0 && t == 0 && s[i]) dfs(i, 0);
    if (g[i].size() % 2 != 0 && s[i]) t++;
  }
  if (t == 0) {
    for (int i = 0; i <= 6; i++) {
      if (s[i]) {
        dfs(i, 0);
        break;
      }
    }
  }
  for (int i = 0; i <= 6; i++) {
    if (!chk[i] && s[i]) flg = 1;
  }
  if ((t != 0 && t != 2) || flg)
    cout << "No solution";
  else {
    for (int i = 0; i < ans.size() - 1; i++) {
      cout << ans[i].second << " ";
      if (e[ans[i].second].first == ans[i].first)
        cout << "+" << endl;
      else
        cout << "-" << endl;
    }
  }
}
