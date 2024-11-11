#include <bits/stdc++.h>
using namespace std;
vector<long long int> adj[100001];
long long int vis[100001], respect[100001];
vector<long long int> anss;
void dfs(long long int x) {
  vis[x] = 1;
  int flag = 0;
  if (respect[x]) flag = 1;
  for (auto j : adj[x]) {
    if (vis[j] == 0) {
      if (flag && respect[j])
        flag = 1;
      else
        flag = 0;
      dfs(j);
    }
  }
  if (flag) anss.push_back(x);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int t, i, m, z, u, v, ans, b, c, l, q, p, j, sum, d, n, a, x, y, k,
      w, h, r;
  t = 1;
  char ch;
  string s, aa, bb, dd, rr, tt, ss = "";
  while (t--) {
    cin >> n;
    long long int root;
    for (i = 1; i <= n; i++) {
      cin >> u >> v;
      respect[i] = v;
      if (u != -1) {
        adj[i].push_back(u);
        adj[u].push_back(i);
      } else
        root = i;
    }
    dfs(root);
    if (anss.empty())
      cout << -1 << "\n";
    else {
      reverse(anss.begin(), anss.end());
      for (auto j : anss) cout << j << " ";
    }
  }
  return 0;
}
