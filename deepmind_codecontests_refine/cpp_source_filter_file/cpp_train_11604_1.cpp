#include <bits/stdc++.h>
using namespace std;
const int sz = 100005;
int n;
vector<int> T[sz];
vector<int> col;
const int MOD = 1000000007;
long long P[sz][2];
void dfs(int u, int prev) {
  if (col[u] == 1)
    P[u][1] = 1, P[u][0] = 0;
  else
    P[u][1] = 0, P[u][0] = 1;
  for (int i = 0; i < T[u].size(); i++) {
    int v = T[u][i];
    if (v == prev) continue;
    dfs(v, u);
    P[u][1] *= (P[v][0] + P[v][1]);
    P[u][1] % MOD;
    P[u][1] += P[u][0] * P[v][1];
    P[u][1] % MOD;
    P[u][0] = P[u][0] * (P[v][0] + P[v][1]);
    P[u][0] % MOD;
  }
}
int main() {
  memset(P, 0, sizeof P);
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int x;
    scanf("%d", &x);
    T[i + 1].push_back(x);
    T[x].push_back(i + 1);
  }
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    col.push_back(x);
  }
  dfs(0, -1);
  cout << P[0][1] << "\n";
  return 0;
}
