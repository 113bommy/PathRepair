#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
vector<vector<int>> edges;
long long DP[200010];
long long fac[200010];
void solve(const int u, const int p) {
  DP[u] = 1;
  int tot = 0;
  for (auto& e : edges[u]) {
    if (e != p) {
      tot++;
      solve(e, u);
      DP[u] = (DP[u] * DP[e]) % MOD;
    }
  }
  DP[u] = (DP[u] * fac[tot]) % MOD;
  if (u != 1 && tot) DP[u] = (2 * DP[u]) % MOD;
}
int main() {
  fac[0] = 1;
  for (int i = 1; i <= 200000; i++) fac[i] = (fac[i - 1] * i) % MOD;
  int N, t, f;
  scanf("%d", &N);
  edges.assign(N + 5, vector<int>());
  for (int i = 0; i < N - 1; i++) {
    scanf("%d %d", &t, &f);
    edges[t].push_back(f);
    edges[f].push_back(t);
  }
  solve(1, 1);
  printf("%d\n", int((N * DP[1]) % MOD));
  return 0;
}
