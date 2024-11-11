#include <bits/stdc++.h>
using namespace std;
int N, S, a, b;
long long int dp[100005], B[100005], tmp[100005];
bool visit[100005];
struct cmp {
  bool operator()(int a, int b) {
    if (dp[a] != dp[b]) return dp[a] > dp[b];
    return a < b;
  }
};
vector<int> T[100005], G[100005];
set<int, cmp> C[100005];
void root(int x) {
  visit[x] = 1;
  for (int i = 0; i < T[x].size(); ++i)
    if (!visit[T[x][i]]) {
      G[x].push_back(T[x][i]);
      root(T[x][i]);
    }
}
long long int dfs(int x) {
  if (dp[x] != -1) return dp[x];
  dp[x] = 0;
  for (int i = 0; i < G[x].size(); ++i) {
    dfs(G[x][i]);
    tmp[x] += tmp[G[x][i]];
    C[x].insert(G[x][i]);
  }
  int t;
  while (B[x] > (x != S) && !C[x].empty()) {
    t = *C[x].begin();
    C[x].erase(t);
    dp[x] += dp[t] + 2ll;
    --B[x];
  }
  dp[x] += 2ll * min(tmp[x], B[x] - (x != S));
  tmp[x] = B[x] - min(tmp[x], B[x] - (x != S)) - 1ll;
  return dp[x];
}
int main() {
  memset(dp, -1, sizeof(dp));
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) cin >> B[i];
  for (int i = 1; i < N; ++i) {
    scanf("%d%d", &a, &b);
    T[a].push_back(b);
    T[b].push_back(a);
  }
  scanf("%d", &S);
  root(S);
  if (N == 1)
    cout << 0 << endl;
  else
    cout << dfs(S) << endl;
}
