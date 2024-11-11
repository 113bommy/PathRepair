#include <bits/stdc++.h>
using namespace std;
const int NMAX = 111111;
int U[NMAX], V[NMAX];
vector<int> g[NMAX];
int assign(int cl, int u, int v, int val_u, int val_v) {
  if (U[cl] != u) swap(u, v), swap(val_u, val_v);
  return (U[cl] > 0 ? val_u : val_u ^ 1) | (V[cl] > 0 ? val_v : val_v ^ 1);
}
bool visited[NMAX];
vector<int> trace;
const long long MOD = 1e9 + 7;
long long dp[2][2];
void dfs(int u, int st, int st_val) {
  visited[u] = true;
  trace.push_back(u);
  long long cache[2][2] = {
      0,
  };
  for (int here = 0; here < 2; here++) {
    if (u == st && here != st_val) continue;
    for (int sum = 0; sum < 2; sum++)
      for (int there = 0; there < 2; there++) {
        int delta = 0;
        for (int cl : g[u]) {
          int v = abs(U[cl]) + abs(V[cl]) - u;
          int v_val = there;
          if (v == u)
            v_val = here;
          else if (v == st)
            v_val = st_val;
          if (visited[v]) delta ^= assign(cl, u, v, here, v_val);
        }
        cache[sum ^ delta][here] += dp[sum][there];
        cache[sum ^ delta][here] %= MOD;
      }
  }
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) dp[i][j] = cache[i][j];
  for (int cl : g[u]) {
    int v = abs(U[cl]) + abs(V[cl]) - u;
    if (!visited[v]) dfs(v, st, st_val);
  }
}
int main() {
  int N, M;
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++) {
    int s;
    scanf("%d", &s);
    if (s == 1) {
      int x;
      scanf("%d", &x);
      U[i] = V[i] = x;
    } else {
      int x, y;
      scanf("%d%d", &x, &y);
      U[i] = x, V[i] = y;
    }
    g[abs(U[i])].push_back(i);
    if (abs(U[i]) != abs(V[i])) g[abs(V[i])].push_back(i);
  }
  long long ans[2] = {
      1,
  };
  for (int i = 1; i <= M; i++)
    if (!visited[i]) {
      trace.clear();
      long long sum[2] = {
          0,
      };
      for (int j = 0; j < 2; j++) {
        for (int a = 0; a < 2; a++)
          for (int b = 0; b < 2; b++) dp[a][b] = 0;
        dp[0][j] = 1;
        for (auto t : trace) visited[t] = false;
        dfs(i, i, j);
        for (int a = 0; a < 2; a++)
          for (int b = 0; b < 2; b++) sum[a] += dp[a][b];
      }
      for (int j = 0; j < 2; j++) sum[j] %= MOD;
      long long cache[2] = {
          0,
      };
      for (int a = 0; a < 2; a++)
        for (int b = 0; b < 2; b++) cache[a ^ b] += ans[a] * sum[b];
      for (int j = 0; j < 2; j++) ans[j] = cache[j] % MOD;
    }
  printf("%lld", ans[1]);
}
