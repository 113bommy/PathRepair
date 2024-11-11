#include <bits/stdc++.h>
using namespace std;
vector<long long int> adj[100005];
vector<long long int> lev(100005, 0);
int table[100005][21];
vector<long long int> store(100005);
long long int n, level;
long long int dfs(long long int i, long long int x) {
  long long int z = 1;
  for (long long int j = 0; j < adj[i].size(); j++) {
    if (adj[i][j] != x) {
      lev[adj[i][j]] = lev[i] + 1;
      table[adj[i][j]][0] = i;
      z += dfs(adj[i][j], i);
    }
  }
  store[i] = z;
  return z;
}
void prep() {
  for (long long int i = 1; i <= level; i++) {
    for (long long int j = 1; j <= n; j++) {
      if (table[j][i - 1] != -1) table[j][i] = table[table[j][i - 1]][i - 1];
    }
  }
}
int lca(int x, int y) {
  if (lev[x] < lev[y]) swap(x, y);
  int diff = lev[x] - lev[y];
  while (diff > 0) {
    int k = log2(diff);
    x = table[x][k];
    k = 1 << k;
    diff -= k;
  }
  if (x == y) return y;
  for (int j = level; j >= 0; j--) {
    if (table[x][j] != -1 && table[x][j] != table[y][j]) {
      x = table[x][j];
      y = table[y][j];
    }
  }
  return table[x][0];
}
long long int calc(long long int u, long long int k) {
  long long int cur = u;
  for (long long int j = 20; j >= 0; j--) {
    if (k & (1LL << j)) cur = table[cur][j];
  }
  return cur;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  memset(table, -1, sizeof(table));
  level = log2(n);
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1, 0);
  prep();
  int m, x, y;
  cin >> m;
  while (m--) {
    cin >> x >> y;
    if (x == y) {
      cout << (n - 1) << endl;
      continue;
    }
    if (lev[x] == lev[y]) {
      int z = lca(x, y);
      int f = lev[x] - lev[z] - 1;
      cout << (n - store[calc(x, f)] - store[calc(y, f)]) << endl;
    } else {
      int z = lca(x, y);
      int f = lev[x] + lev[y] - 2 * lev[z];
      if (f % 2 != 0) {
        cout << 0 << endl;
      } else {
        if (lev[x] > lev[y]) {
          swap(x, y);
        }
        f = (f + 1) / 2 - 1;
        cout << (store[calc(y, f + 1)] - store[calc(y, f)]) << endl;
      }
    }
  }
  return 0;
}
