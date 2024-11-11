#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int k, n;
vector<int> adj[N];
long long sum = 0;
int cc[N][6], sz[N];
long long go[N];
long long dfs(int first, int p) {
  int u, i, j;
  long long ret = 0;
  sz[first] = 1;
  for (i = 0; i < adj[first].size(); ++i) {
    u = adj[first][i];
    if (u != p) {
      ret += dfs(u, first);
      sz[first] += sz[u];
      for (j = 0; j <= k; ++j) cc[first][j] += cc[u][j];
    }
  }
  u = cc[first][k];
  for (i = k - 1; i >= 0; --i) {
    cc[first][i + 1] = cc[first][i];
  }
  cc[first][1] += u;
  ++cc[first][1];
  go[first] = ret + u + 1;
  sum += ret;
  return go[first];
}
void dfs2(int first, int p, int *bit, long long tot) {
  int u, i, j, ori[6];
  for (i = 0; i <= k; ++i) ori[i] = bit[i];
  u = bit[k];
  for (i = k - 1; i >= 0; --i) bit[i + 1] = bit[i];
  bit[1] += u;
  tot += u;
  sum += tot;
  for (i = 0; i < adj[first].size(); ++i) {
    u = adj[first][i];
    if (u != p) {
      tot += go[u];
      for (j = 0; j <= k; ++j) {
        bit[j] += cc[u][j];
      }
    }
  }
  for (i = 0; i < adj[first].size(); ++i) {
    u = adj[first][i];
    if (u != p) {
      tot -= go[u];
      for (j = 0; j <= k; ++j) {
        bit[j] -= cc[u][j];
      }
      ++bit[k];
      dfs2(u, first, bit, tot);
      --bit[k];
      tot += go[u];
      for (j = 0; j <= k; ++j) {
        bit[j] += cc[u][j];
      }
    }
  }
  for (i = 0; i <= k; ++i) bit[i] = ori[i];
}
int main() {
  int i, a, b;
  cin >> n >> k;
  for (i = 0; i < n - 1; ++i) {
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1, 0);
  int bit[6] = {0, 0, 0, 0, 0, 0};
  dfs2(1, 0, bit, 0);
  cout << (sum + 1) / 2 << endl;
}
