#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int inf = 1e9 + 10;
vector<int> g[maxn];
int dp[maxn], cnt[maxn];
bool vis[maxn];
inline int dfs(int x) {
  vis[x] = true;
  int res = 0;
  for (int i = 0; i < (int)g[x].size(); i++) {
    int to = g[x][i];
    if (!vis[to]) res += dfs(to);
  }
  res++;
  return res;
}
inline bool luck(int num) {
  while (num > 0) {
    if ((num % 10 != 4) && (num % 10 != 7)) return false;
    num /= 10;
  }
  return true;
}
inline void upd(int &x, int y) {
  if (x > y) x = y;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < n; i++)
    if (!vis[i]) cnt[dfs(i)]++;
  for (int i = 0; i < maxn; i++) dp[i] = inf + 1;
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] > 0) {
      for (int j = 0; j < i; j++) {
        deque<pair<int, int> > Q;
        int ed = n / i;
        if (ed * i + j > n) ed--;
        for (int k = ed; k >= ed - cnt[i]; k--) {
          if (k * i + j < 0) break;
          while ((!Q.empty()) && (Q.back().first >= dp[k * i + j] - k))
            Q.pop_back();
          Q.push_back(make_pair(dp[k * i + j] - k, k));
        }
        for (int k = ed; k >= 0; k--) {
          if (!Q.empty()) upd(dp[i * k + j], Q.front().first + k);
          while ((k - cnt[i] - 1 >= 0) && (!Q.empty()) &&
                 Q.back().first >=
                     dp[i * (k - cnt[i] - 1) + j] - (k - cnt[i] - 1))
            Q.pop_back();
          if (k - cnt[i] - 1 >= 0)
            Q.push_back(
                make_pair(dp[i * (k - cnt[i] - 1) + j] - (k - cnt[i] - 1),
                          k - cnt[i] - 1));
          if ((!Q.empty()) && Q.front().second == k) Q.pop_front();
        }
      }
    }
  }
  int ans = inf;
  for (int i = 1; i <= n; i++)
    if (luck(i)) ans = min(ans, dp[i] - 1);
  cout << (ans > n ? -1 : ans) << endl;
  return 0;
}
