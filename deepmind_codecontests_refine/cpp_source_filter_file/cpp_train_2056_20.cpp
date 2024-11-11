#include <bits/stdc++.h>
using LL = long long;
using namespace std;
const int N = 3005, M = (int)1e9 + 7;
int n, d, dp[N][N], ps[N][N], rv[N];
vector<int> ed[N];
void dfs(int u) {
  for (int v : ed[u]) dfs(v);
  for (int i = 1; i <= n + 1; i++) {
    dp[u][i] = 1;
    for (int v : ed[u]) dp[u][i] = (LL)dp[u][i] * ps[v][i] % M;
    ps[u][i] = dp[u][i] + ps[u][i - 1];
  }
}
int calc() {
  if (d <= n + 1) return ps[1][d];
  int ans = 0;
  rv[0] = rv[1] = 1;
  for (int i = 2; i <= n + 1; i++) rv[i] = (LL)(M - M / i) * rv[M % i] % M;
  for (int i = 1; i <= n + 1; i++) {
    int b = ps[1][i];
    for (int j = 1; j < i; j++) b = (LL)b * (d - j) % M * rv[i - j] % M;
    for (int j = i + 1; j <= n + 1; j++) {
      b = (M - (LL)b * (d - j) % M * rv[j - i] % M) % M;
    }
    ans = (ans + b) % M;
  }
  return ans;
}
int main() {
  scanf("%d%d", &n, &d);
  for (int i = 2; i <= n; i++) {
    int p;
    scanf("%d", &p);
    ed[p].push_back(i);
  }
  dfs(1);
  printf("%d\n", calc());
}
