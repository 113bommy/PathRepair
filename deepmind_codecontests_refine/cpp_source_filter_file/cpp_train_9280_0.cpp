#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int MAXN = 2e5 + 100;
struct Edge {
  int to;
  int next;
} e[MAXN << 1];
int head[MAXN], n, tot;
long long dp[MAXN][3];
void add_edge(int u, int v) {
  e[++tot].next = head[u];
  e[tot].to = v;
  head[u] = tot;
}
void dfs(int x) {
  if (!head[x])
    dp[x][2] = 1;
  else
    dp[x][0] = 1;
  for (int i = head[x]; i; i = e[i].next) {
    int to = e[i].to;
    dfs(to);
    dp[0][0] = dp[x][0];
    dp[0][1] = dp[x][1];
    dp[0][2] = dp[x][2];
    dp[x][0] = (dp[0][0] * (dp[to][0] + dp[to][2])) % mod;
    dp[x][1] = (dp[0][0] * (dp[to][1] + dp[to][2]) +
                dp[0][1] * (dp[to][0] + dp[to][2])) %
               mod;
    dp[x][2] = (dp[0][1] * (dp[to][1], dp[to][2]) +
                dp[0][2] * (dp[to][0] + 2 * dp[to][2] + dp[to][1])) %
               mod;
  }
}
int main() {
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int f;
    scanf("%d", &f);
    add_edge(f, i);
  }
  dfs(1);
  cout << (dp[1][0] + dp[1][2]) % mod;
}
