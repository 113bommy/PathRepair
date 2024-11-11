#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2 * 1e5, MAXK = 5;
long long sum[MAXN][MAXK], ans = 0;
int N, K, cnt[MAXN][MAXK];
vector<int> G[MAXN];
void solve(int v, int p) {
  long long childsum[K];
  long long childcnt[K];
  memset(childsum, 0, sizeof(childsum));
  memset(childcnt, 0, sizeof(childcnt));
  for (int i = 0; i < (int)G[v].size(); i++) {
    int u = G[v][i];
    if (u == p) continue;
    solve(u, v);
    for (int k = 0; k < (int)K; k++) {
      childsum[k] += sum[u][k];
      childcnt[k] += cnt[u][k];
    }
  }
  for (int i = 0; i < (int)G[v].size(); i++) {
    int u = G[v][i];
    if (u == p) continue;
    for (int k = 0; k < (int)K; k++) childcnt[k] -= cnt[u][k];
    for (int k = 0; k < (int)K; k++) childsum[k] -= sum[u][k];
    for (int k1 = 0; k1 < (int)K; k1++)
      for (int k2 = 0; k2 < (int)K; k2++) {
        ans += sum[u][k1] * childcnt[k2];
        ans += cnt[u][k1] * childsum[k2];
        ans += cnt[u][k1] * childcnt[k2] * (k1 + k2 + 2 <= K ? 1 : 2);
      }
  }
  for (int i = 0; i < (int)G[v].size(); i++) {
    int u = G[v][i];
    if (u == p) continue;
    for (int k = 0; k < (int)K; k++) {
      cnt[v][(k + 1) % K] += cnt[u][k];
      sum[v][(k + 1) % K] += sum[u][k];
    }
    sum[v][0] += cnt[u][K - 1];
  }
  for (int k = 0; k < (int)K; k++) ans += sum[v][k];
  for (int k = 1; k < (int)K; k++) ans += cnt[v][k];
  cnt[v][0] += 1;
}
int main() {
  scanf("%d", &N), scanf("%d", &K);
  for (int i = 0; i < (int)N - 1; i++) {
    int v, u;
    scanf("%d", &v), scanf("%d", &u);
    v--, u--;
    G[v].push_back(u);
    G[u].push_back(v);
  }
  memset(sum, 0, sizeof(sum));
  memset(cnt, 0, sizeof(cnt));
  solve(0, -1);
  printf("%lld\n", ans);
}
