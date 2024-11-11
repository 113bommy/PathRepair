#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005;
vector<int> tree[MAX];
int d[MAX], sz[MAX];
void dfs(int v) {
  sz[v] = 1;
  for (int i = 0; i < (int)tree[v].size(); i++) {
    int u = tree[v][i];
    d[u] = d[v] + 1;
    dfs(u);
    sz[v] += sz[u];
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int p;
    cin >> p;
    p--;
    tree[p].push_back(i);
  }
  dfs(0);
  for (int i = 0; i < n; i++) {
    int ans = n - sz[i] - d[i] + 2 * (d[i] + 1);
    cout << ans / 2 << ".";
    if (ans % 2)
      cout << "5"
           << " ";
    else
      cout << "0"
           << " ";
  }
  return 0;
}
