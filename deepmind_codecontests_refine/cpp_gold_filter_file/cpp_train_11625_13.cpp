#include <bits/stdc++.h>
using namespace std;
long long ans;
const int C = 20;
vector<int> adj[300010];
int dp[C + 2][300010];
int mx[C + 2][300010];
int h[300010];
int n;
void dfs(int root, int dad = -1) {
  h[root] = 1;
  for (auto x : adj[root])
    if (x != dad) {
      dfs(x, root);
      h[root] = max(h[root], h[x] + 1);
      for (int(k) = (0); (k) < (C); (k)++)
        mx[k][root] = max(mx[k][root], mx[k][x]);
    }
  dp[1][root] = n;
  mx[1][root] = n;
  for (int(d) = (2); (d) < (C); (d)++) {
    int st = 0;
    int en = n + 1;
    while (st != en - 1) {
      int mid = (st + en) / 2;
      int cnt = 0;
      for (auto x : adj[root])
        if (x != dad && dp[d - 1][x] >= mid) cnt++;
      if (cnt >= mid)
        st = mid;
      else
        en = mid;
    }
    dp[d][root] = st;
    mx[d][root] = max(mx[d][root], st);
  }
  int mm = 0;
  for (int d = C - 1; d > 0; d--) {
    ans += d * (mx[d][root] - mx[d + 1][root]);
    if (mx[d][root]) mm = max(mm, d);
  }
  ans -= mm;
  ans += h[root];
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int(i) = (1); (i) < (n); (i)++) {
    int v, u;
    cin >> v >> u;
    v--, u--;
    adj[v].push_back(u);
    adj[u].push_back(v);
  }
  dfs(0);
  cout << ans << "\n";
}
