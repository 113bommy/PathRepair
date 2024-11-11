#include <bits/stdc++.h>
using namespace std;
void start() {}
vector<long long int> g[200007];
vector<long long int> v;
vector<bool> vis, vis1;
long double siz = 0, reference = 0;
bool cycle = 0;
void dfs(long long int x, long long int count1, long long int& maxx) {
  vis[x] = 1;
  count1++;
  for (auto i : g[x]) {
    if (!vis[i]) {
      if (count1 >= maxx) {
        reference = i;
        maxx = count1;
      }
      dfs(i, count1, maxx);
    }
  }
  return;
}
void dfs2(long long int x) {
  long long int maxx = -999999999999999999;
  long long int ans = 0;
  dfs(x, ans, maxx);
  ans = 0;
  for (long long int i = 1; i < vis.size() + 1; i++) vis[i] = 0;
  dfs(reference, ans, maxx);
  cout << maxx - 1 << "\n";
}
void sober() {
  long long int n, x = 0, a = 0, b = 0, y = 0, sum = 0, k = 0, m = 0;
  cin >> n >> m;
  vis.resize(n + 1, 0);
  for (long long int i = 0; i < m; i++) {
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  long long int comp = 0;
  dfs2(1);
  return;
}
signed main() {
  start();
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  while (t--) {
    sober();
  }
}
