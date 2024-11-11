#include <bits/stdc++.h>
using namespace std;
const int maxn = 20 + 9;
int N, M, K;
int vis[maxn];
vector<pair<int, int>> g[maxn];
int dfs(int x, int d, int V) {
  if (x >= N) {
    return 1;
  }
  int ret = dfs(x + 1, d, V);
  for (auto e : g[x]) {
    if (!vis[e.first] && d + e.second <= V) {
      vis[e.first] = 1;
      if ((ret += dfs(x + 1, d + e.second, V)) >= K) {
        return K;
      }
      vis[e.first] = 0;
    }
  }
  return ret;
}
bool chk(int m) {
  for (int i = 0; i < N; i++) {
    vis[i] = 0;
  }
  return dfs(0, 0, m) >= K;
}
int main() {
  cin >> N >> M >> K;
  while (M--) {
    int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    g[--u].push_back(make_pair(--v, c));
  }
  int L = 0, R = int(2e9);
  while (L < R) {
    int m = L + (R - L) / 2;
    chk(m) ? R = m : L = m + 1;
  }
  cout << L << endl;
  return 0;
}
