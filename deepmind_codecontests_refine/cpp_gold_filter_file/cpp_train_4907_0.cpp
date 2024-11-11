#include <bits/stdc++.h>
using namespace std;
const int maxn = 410;
const int maxm = 251000;
const int oo = 1e9;
int n, m;
int st[maxm], ed[maxm], c[maxm], rr[maxm];
int dis[maxn];
int dp[maxn][maxn];
long long ans = 0;
vector<int> quest[maxn];
int que[maxn], s, t;
int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> dis[i];
  for (int i = 1; i <= m; i++) {
    cin >> st[i] >> ed[i] >> c[i] >> rr[i];
    quest[st[i]].push_back(i);
  }
  for (int l = 1; l <= n; l++) {
    for (int r = l; r <= n; r++) dp[1][r] = dis[r] - dis[l];
    s = 1, t = 0;
    for (int k = 2; k <= n + 1; k++) {
      dp[k][l] = 0;
      que[1] = l;
      s = t = 1;
      for (int r = l + 1; r <= n; r++) {
        t++;
        que[t] = r;
        dp[k][r] = oo;
        while (s <= t) {
          dp[k][r] =
              min(dp[k][r], max(dp[k - 1][que[s]], dis[r] - dis[que[s]]));
          if (dp[k - 1][que[s]] < dis[r] - dis[que[s]])
            s++;
          else
            break;
        }
      }
    }
    for (int i = 0; i < quest[l].size(); i++) {
      int now = quest[l][i];
      ans = max(ans, 1ll * dp[rr[now] + 1][ed[now]] * c[now]);
    }
  }
  cout << ans << endl;
  return 0;
}
