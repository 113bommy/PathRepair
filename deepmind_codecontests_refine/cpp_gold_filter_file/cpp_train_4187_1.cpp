#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int MAX_V = 2020;
const int MAX_LOG_V = 13;
vector<int> G[MAX_V];
int root;
int parent[MAX_LOG_V][MAX_V];
int depth[MAX_V];
void dfs(int v, int p, int d) {
  parent[0][v] = p;
  depth[v] = d;
  for (int i = 0; i < G[v].size(); i++) {
    if (G[v][i] != p) dfs(G[v][i], v, d + 1);
  }
}
void init(int V) {
  dfs(root, -1, 0);
  for (int k = 0; k + 1 < MAX_LOG_V; k++) {
    for (int v = 0; v < V; v++) {
      if (parent[k][v] < 0)
        parent[k + 1][v] = -1;
      else
        parent[k + 1][v] = parent[k][parent[k][v]];
    }
  }
}
int lca(int u, int v) {
  if (depth[u] > depth[v]) swap(u, v);
  for (int k = 0; k < MAX_LOG_V; k++) {
    if ((depth[v] - depth[u]) >> k & 1) {
      v = parent[k][v];
    }
  }
  if (u == v) return u;
  for (int k = MAX_LOG_V - 1; k >= 0; k--) {
    if (parent[k][u] != parent[k][v]) {
      u = parent[k][u];
      v = parent[k][v];
    }
  }
  return parent[0][u];
}
vector<int> G2[MAX_V];
int root2;
int parent2[MAX_LOG_V][MAX_V];
int depth2[MAX_V];
void dfs2(int v, int p, int d) {
  parent2[0][v] = p;
  depth2[v] = d;
  for (int i = 0; i < G2[v].size(); i++) {
    if (G2[v][i] != p) dfs2(G2[v][i], v, d + 1);
  }
}
void init2(int V) {
  dfs2(root2, -1, 0);
  for (int k = 0; k + 1 < MAX_LOG_V; k++) {
    for (int v = 0; v < V; v++) {
      if (parent2[k][v] < 0)
        parent2[k + 1][v] = -1;
      else
        parent2[k + 1][v] = parent2[k][parent2[k][v]];
    }
  }
}
int lca2(int u, int v) {
  if (depth2[u] > depth2[v]) swap(u, v);
  for (int k = 0; k < MAX_LOG_V; k++) {
    if ((depth2[v] - depth2[u]) >> k & 1) {
      v = parent2[k][v];
    }
  }
  if (u == v) return u;
  for (int k = MAX_LOG_V - 1; k >= 0; k--) {
    if (parent2[k][u] != parent2[k][v]) {
      u = parent2[k][u];
      v = parent2[k][v];
    }
  }
  return parent2[0][u];
}
int dp[1010][1010][3];
const int INF = 1e9;
void chmin(int &a, int b) {
  if (a > b) a = b;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  int A;
  cin >> A;
  vector<int> PA(A);
  for (int i = 0; i < (A - 1); ++i) {
    cin >> PA[i];
    PA[i]--;
    G[PA[i]].push_back(i + 1);
  }
  vector<int> X(N);
  for (int i = 0; i < (N); ++i) {
    cin >> X[i];
    X[i]--;
  }
  int B;
  cin >> B;
  vector<int> PB(B);
  for (int i = 0; i < (B - 1); ++i) {
    cin >> PB[i];
    PB[i]--;
    G2[PB[i]].push_back(i + 1);
  }
  vector<int> Y(N);
  for (int i = 0; i < (N); ++i) {
    cin >> Y[i];
    Y[i]--;
  }
  init(A);
  init2(B);
  for (int i = 0; i < (N + 1); ++i)
    for (int j = 0; j < (N + 1); ++j)
      for (int k = 0; k < (3); ++k) dp[i][j][k] = INF;
  dp[0][0][2] = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      for (int k = 0; k < 3; k++) {
        if (dp[i][j][k] == INF) continue;
        for (int l = 0; l < 2; l++) {
          int nj = j, nk = l;
          int neco = 0;
          if (k == 2) {
            nj = 0;
            nk = l;
            if (l == 0)
              neco = depth[X[i]];
            else
              neco = depth2[Y[i]];
          } else if (l == k) {
            if (k == 0) {
              int lc = lca(X[i], X[i - 1]);
              neco = depth[X[i]] - depth[lc];
            } else {
              int lc = lca2(Y[i], Y[i - 1]);
              neco = depth2[Y[i]] - depth2[lc];
            }
          } else {
            if (l == 0) {
              if (j == 0)
                neco = depth[X[i]];
              else {
                int lc = lca(X[i], X[j - 1]);
                neco = depth[X[i]] - depth[lc];
              }
            } else {
              if (j == 0)
                neco = depth2[Y[i]];
              else {
                int lc = lca2(Y[i], Y[j - 1]);
                neco = depth2[Y[i]] - depth2[lc];
              }
            }
            nj = i;
          }
          chmin(dp[i + 1][nj][nk], dp[i][j][k] + neco);
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= N; i++)
    for (int k = 0; k < 2; k++) {
      if (dp[N][i][k] == INF) continue;
      if (ans < A - 1 + B - 1 - dp[N][i][k]) ans = A - 1 + B - 1 - dp[N][i][k];
    }
  cout << ans << endl;
  return 0;
}
