#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > g[100005];
int upor[100005], nich[100005];
int sub[100005], n;
bool lucky(int num) {
  while (num) {
    int rem = num % 10;
    num /= 10;
    if (rem == 4 || rem == 7) {
      continue;
    }
    return false;
  }
  return true;
}
void dfs1(int src, int par) {
  sub[src] = 1;
  for (auto i : g[src]) {
    int u = i.first;
    int flag = i.second;
    if (par == u) {
      continue;
    }
    dfs1(u, src);
    sub[src] += sub[u];
    if (flag) {
      nich[src] += sub[u];
    } else {
      nich[src] += nich[u];
    }
  }
}
void dfs2(int src, int par, int f) {
  if (par != -1) {
    if (f) {
      upor[src] = n - sub[src];
    } else {
      upor[src] = upor[par] + nich[par] - nich[src];
    }
  }
  for (auto i : g[src]) {
    int u = i.first;
    int flag = i.second;
    if (par == u) {
      continue;
    }
    dfs2(u, src, flag);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, lucky(w)});
    g[v].push_back({u, lucky(w)});
  }
  dfs1(1, -1);
  dfs2(1, -1, 0);
  long long int ans = 0LL;
  for (int i = 1; i <= n; i++) {
    int total = nich[i] + upor[i];
    ans += (1LL * total * (total - 1));
  }
  cout << ans << endl;
  return 0;
}
