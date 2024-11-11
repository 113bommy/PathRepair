#include <bits/stdc++.h>
using namespace std;
unsigned int n, m;
unsigned int A[8400000 >> 1];
bool vis[8400000], book[8400000];
void dfs(unsigned int u) {
  if (vis[u]) return;
  vis[u] = 1;
  if (u > 420000) dfs(u - 420000);
  if (u <= 420000) {
    if (book[(~u) % (1 << n)]) dfs((~u) % (1 << n) + 420000);
    for (unsigned int j = 0; j < n; ++j)
      if ((~u) & (1 << j)) dfs(u | (1 << j));
  }
}
signed main() {
  cin >> n >> m;
  for (unsigned int i = 1; i <= m; ++i) scanf("%d", &A[i]), book[A[i]] = 1;
  unsigned int res = 0;
  for (unsigned int i = 1; i <= m; ++i)
    if (!vis[A[i] + 420000]) dfs(A[i] + 420000), ++res;
  cout << res << endl;
}
