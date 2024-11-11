#include <bits/stdc++.h>
using namespace std;
void init_code() {}
long long int c[207];
bool adj[207][207];
long long int n;
void dfs(long long int u, long long int cu) {
  if (~c[u]) {
    if (c[u] ^ cu) {
      cout << "NO"
           << "\n";
      exit(0);
    }
    return;
  }
  c[u] = cu;
  for (long long int v = 0; v < n; v++)
    if (adj[u][v]) dfs(v, cu ^ 1);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  init_code();
  cin >> n;
  string str;
  cin >> str;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = i + 1; j < n; j++) {
      if (str[j] < str[i]) adj[i][j] = adj[j][i] = 1;
    }
  }
  memset(c, -1, sizeof(c));
  for (long long int i = 0; i < n; i++) {
    if (c[i] < 0) dfs(i, 0);
  }
  cout << "YES"
       << "\n";
  for (long long int i = 0; i < n; i++) cout << c[i];
  return 0;
}
