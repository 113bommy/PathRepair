#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 100;
int trie[N * 31][2], tot;
vector<int> g[N * 31];
long long dp[31][2];
void insert(int x, int id) {
  int now = 0;
  for (int i = 30; i >= 0; i--) {
    int c = (x >> i & 1);
    if (!trie[now][c]) trie[now][c] = ++tot;
    now = trie[now][c];
    g[now].push_back(id);
  }
}
void dfs(int dep, int u) {
  int ls = trie[u][0], rs = trie[u][1];
  if (ls) dfs(dep - 1, ls);
  if (rs) dfs(dep - 1, rs);
  if (!ls || !rs) return;
  int j = 0;
  long long sum = 0;
  for (int i = 0; i < (int)g[ls].size(); i++) {
    while (j < (int)g[rs].size() && g[rs][j] < g[ls][i]) j++;
    sum += j;
  }
  dp[dep][0] += sum;
  dp[dep][1] += 1ll * g[rs].size() * g[ls].size() - sum;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    insert(x, i);
  }
  dfs(30, 0);
  long long ans = 0, ret = 0;
  for (int i = 30; i >= 0; i--) {
    ans += min(dp[i][0], dp[i][1]);
    if (dp[i][1] < dp[i][0]) {
      ret += (1ll << i);
    }
  }
  printf("%lld %lld\n", ans, ret);
  return 0;
}
