#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int N, sz[200005];
vector<pii> edge[200005];
ll G, B;
ll dfs(int x, int p) {
  ll ret = 0;
  sz[x] = 1;
  for (auto i : edge[x]) {
    if (i.second == p) continue;
    dfs(i.second, x);
    sz[x] += sz[i.second];
    G += 1ll * i.first * min(sz[i.second], N - sz[i.second]);
    if (sz[i.second] & 1) B += i.first;
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int K;
    cin >> K;
    N = 2 * K;
    for (int i = 1; i <= N; ++i) edge[i].clear();
    for (int i = 1; i < N; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      edge[a].emplace_back(c, b);
      edge[b].emplace_back(c, a);
    }
    G = B = 0;
    dfs(1, 1);
    printf("%lld %lld\n", G, B);
  }
  return 0;
}
