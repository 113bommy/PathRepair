#include <bits/stdc++.h>
using namespace std;
vector<int> vc[210000];
int sum[210000], vis[210000];
void DFS(int u, int fa) {
  sum[u] = 1;
  for (int i = 0; i < vc[u].size(); i++) {
    int v = vc[u][i];
    if (v == fa) continue;
    vis[v] = !vis[u];
    DFS(v, u);
    sum[u] += sum[v];
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, i, j, u, v;
  cin >> n;
  for (i = 1; i < n; i++) {
    cin >> u >> v;
    vc[u].push_back(v);
    vc[v].push_back(u);
  }
  DFS(1, 0);
  long long cnt = 0, t = 0;
  for (i = 1; i <= n; i++) {
    if (vis[i]) cnt++;
    t += sum[i] * (n - sum[i]);
  }
  t += cnt * (n - cnt);
  cout << t / 2 << endl;
  return 0;
}
