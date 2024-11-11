#include <bits/stdc++.h>
using namespace std;
map<int, int> X, Y;
int tot;
int Pow[300010];
int v, e;
vector<int> G[300010];
bool vis[300010];
inline void dfs(int x) {
  vis[x] = 1;
  v++;
  e += G[x].size();
  for (int i = 0; i < G[x].size(); i++) {
    if (vis[G[x][i]]) continue;
    dfs(G[x][i]);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = (1); i <= (n); i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    if (X.find(x) == X.end()) X[x] = ++tot;
    if (Y.find(y) == Y.end()) Y[y] = ++tot;
    G[X[x]].push_back(Y[y]);
    G[Y[y]].push_back(X[x]);
  }
  Pow[0] = 1;
  for (int i = (1); i <= (2 * n); i++) Pow[i] = Pow[i - 1] * 2 % 1000000007;
  int ans = 1;
  for (int i = (1); i <= (tot); i++)
    if (!vis[i]) {
      v = 0, e = 0;
      dfs(i);
      e /= 2;
      int num = Pow[v];
      if (v - 1 == e) num--;
      ans = 1ll * ans * num % 1000000007;
    }
  cout << ans << endl;
  return 0;
}
