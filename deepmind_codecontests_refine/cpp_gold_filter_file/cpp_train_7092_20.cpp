#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > G[100005];
int sub[100005], down[100005], up[100005];
long long int ans;
int chek(string& w) {
  int flag = 1;
  for (auto z : w) {
    if (z != '4' && z != '7') {
      flag = 0;
      break;
    }
  }
  return flag;
}
void dfs(int n, int p) {
  sub[n] = 1;
  for (auto z : G[n]) {
    if (z.first == p) continue;
    dfs(z.first, n);
    sub[n] += sub[z.first];
    if (z.second == 1) {
      down[n] += sub[z.first];
    } else {
      down[n] += down[z.first];
    }
  }
}
void dfs2(int n, int p) {
  ans += (long long int)(down[n] + up[n]) * ((down[n] + up[n]) - 1);
  for (auto z : G[n]) {
    if (z.first == p) continue;
    if (z.second == 1) {
      up[z.first] = sub[1] - sub[z.first];
    } else {
      up[z.first] = up[n] + down[n] - down[z.first];
    }
    dfs2(z.first, n);
  }
}
int main() {
  int n, i, j, t, u, v;
  string w;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (i = 0; i < n - 1; i++) {
    cin >> u >> v >> w;
    t = chek(w);
    G[u].push_back({v, t});
    G[v].push_back({u, t});
  }
  dfs(1, -1);
  dfs2(1, -1);
  cout << ans;
  return 0;
}
