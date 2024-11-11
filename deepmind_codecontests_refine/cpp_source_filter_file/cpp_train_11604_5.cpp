#include <bits/stdc++.h>
using namespace std;
int abs(int x) {
  if (x < 0) return -x;
  return x;
}
int addmod(int v1, int v2) {
  int v3 = v1 + v2;
  if (v3 >= 1000000009) v3 -= 1000000009;
  return v3;
}
long long dp[100005][2];
long long old[100005][2];
int color[100005];
vector<int> vv[100005];
void dfs(int pos) {
  dp[pos][0] = !color[pos];
  dp[pos][1] = color[pos];
  for (int i = (0); i < (vv[pos].size()); i++) {
    dfs(vv[pos][i]);
    old[pos][0] = dp[pos][0];
    old[pos][1] = dp[pos][1];
    dp[pos][1] = dp[pos][0] = 0;
    int v, u;
    v = pos;
    u = vv[pos][i];
    dp[v][0] += (old[v][0] * dp[u][1]) % 1000000009;
    dp[v][1] += (old[v][1] * dp[u][1]) % 1000000009;
    dp[v][1] += (old[v][1] * dp[u][0]) % 1000000009;
    dp[v][1] += (old[v][0] * dp[u][1]) % 1000000009;
    dp[v][0] += (old[v][0] * dp[u][0]) % 1000000009;
    dp[v][0] %= 1000000009;
    dp[v][1] %= 1000000009;
  }
}
int main() {
  int n;
  scanf("%d", &n);
  int val;
  for (int i = (0); i < (n - 1); i++) {
    scanf("%d", &val);
    vv[val].push_back(i + 1);
  }
  for (int i = (0); i < (n); i++) scanf("%d", &color[i]);
  dfs(0);
  cout << (dp[0][1]), cout << (endl);
}
