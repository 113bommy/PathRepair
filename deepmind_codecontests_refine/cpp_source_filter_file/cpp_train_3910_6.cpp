#include <bits/stdc++.h>
using namespace std;
bool has[200010];
vector<int> near[200010];
int n, k, best = 2147483647;
long long res = 0;
int root1, root2;
int dfs1(int now, int prev) {
  int cnt = has[now];
  for (auto x : near[now])
    if (x - prev) cnt += dfs1(x, now);
  if (cnt >= k && cnt < best) {
    root2 = now;
    best = cnt;
  }
  return cnt;
}
void dfs2(int now, int prev, int d) {
  if (has[now]) res += 1LL * d;
  for (auto x : near[now])
    if (x - prev) dfs2(x, now, d + 1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0; i < 2 * k; i++) {
    int val;
    cin >> val;
    has[val] = true;
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    near[u].push_back(v);
    near[v].push_back(u);
  }
  for (int i = 0; i < n; i++) {
    if (near[i].size() == 1) {
      root1 = i;
      break;
    }
  }
  int sink = dfs1(root1, -1);
  dfs2(1, -1, 0);
  cout << res << endl;
  return 0;
}
