#include <bits/stdc++.h>
using namespace std;
const double EPSILON = 1e-9;
const double PI = acos(-1);
const int MOD = 1e9 + 7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;
int N, M, a, b;
vector<int> G[200003];
long long size[200003];
long long dp[200003][5];
long long ans;
void dfs(int here, int dad) {
  size[here] = 0;
  dp[here][0]++;
  for (int there : G[here]) {
    if (there == dad) continue;
    dfs(there, here);
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < M; ++j) {
        int k = i + j + 1;
        ans += (M - ((k % M) ? (k % M) : M)) * dp[here][i] * dp[there][j];
      }
    }
    for (int i = 0; i < M; ++i) dp[here][(i + 1) % M] += dp[there][i];
    ans += size[there] * (N - size[there]);
    size[here] += size[there];
  }
  size[here]++;
}
int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N - 1; ++i) {
    scanf("%d%d", &a, &b);
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(0, -1);
  printf("%lld", ans / M);
  return 0;
}
