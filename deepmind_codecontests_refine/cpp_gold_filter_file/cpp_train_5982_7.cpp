#include <bits/stdc++.h>
const int MAX = 1e5 + 11;
using namespace std;
const int MMOD = 1e9 + 7;
vector<int> adj[MAX];
int N, X[MAX], DP[MAX][2];
void dfs(int u) {
  DP[u][0] = (X[u] == 0);
  DP[u][1] = (X[u] == 1);
  for (int i = 0; i < (int((adj[u]).size())); ++i) {
    int w = adj[u][i];
    dfs(w);
    int x1 = (1LL * DP[u][1] * DP[w][1]) % MMOD;
    int x2 = (1LL * DP[u][1] * DP[w][0]) % MMOD;
    int x3 = (1LL * DP[u][0] * DP[w][1]) % MMOD;
    int y1 = (1LL * DP[u][0] * DP[w][1]) % MMOD;
    int y2 = (1LL * DP[u][0] * DP[w][0]) % MMOD;
    DP[u][1] = ((x1 + x2) % MMOD + x3) % MMOD;
    DP[u][0] = (y1 + y2) % MMOD;
  }
}
int main() {
  scanf("%d", &(N));
  for (int i = 0; i < (N - 1); ++i) {
    int(x);
    scanf("%d", &x);
    adj[x].push_back(i + 1);
  }
  for (int i = 0; i < (N); ++i) scanf("%d", &(X[i]));
  dfs(0);
  cout << DP[0][1];
  return 0;
}
