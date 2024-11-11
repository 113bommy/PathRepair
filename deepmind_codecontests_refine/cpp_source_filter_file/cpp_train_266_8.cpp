#include <bits/stdc++.h>
using namespace std;
const int N = 10101, MAXK = 20, MAXL = 101, inf = 1 << 29;
int a[N], b[N], n, K, L, len[MAXL];
vector<int> ele;
int id[N], dis[N], cost[MAXK][MAXK];
void bfs(int c, int u) {
  fill(dis, dis + n + 1, inf);
  fill(cost[u], cost[u] + (int)(ele).size(), inf);
  dis[c] = 0;
  vector<int> v;
  v.push_back(c);
  for (int i = 0; i < (int)(v).size(); ++i) {
    c = v[i];
    if (b[c] == 1) cost[u][id[c]] = dis[c];
    for (int j = 0; j < L; ++j) {
      if (c - len[j] > 0 && dis[c - len[j]] == inf)
        dis[c - len[j]] = dis[c] + 1, v.push_back(c - len[j]);
      if (c + len[j] <= n && dis[c + len[j]] == inf)
        dis[c + len[j]] = dis[c] + 1, v.push_back(c + len[j]);
    }
  }
}
int f[1 << MAXK], who[1 << MAXK];
void Dp() {
  f[0] = 0;
  for (int i = 1; i < (1 << (int)(ele).size()); ++i) {
    f[i] = inf;
    int j = i & (-i);
    for (int k = i ^ j; k; k -= k & (-k))
      f[i] = min(f[i], f[i ^ j ^ (k & (-k))] + cost[who[j]][who[(k & (-k))]]);
  }
  int ans = f[(1 << (int)(ele).size()) - 1];
  if (ans == inf) ans = -1;
  printf("%d\n", ans);
}
int main() {
  for (int i = 0; i < MAXK; ++i) who[1 << i] = i;
  cin >> n >> K >> L;
  for (int i = 0; i < K; ++i) {
    int x;
    cin >> x;
    a[x] = 1;
  }
  for (int i = 0; i < L; ++i) cin >> len[i];
  for (int i = 1; i < n + 1; ++i) b[i] = a[i - 1] ^ a[i];
  for (int i = 1; i < n + 1; ++i)
    if (b[i] == 1) id[i] = (int)(ele).size(), ele.push_back(i);
  for (int i = 0; i < (int)(ele).size(); ++i) bfs(ele[i], i);
  Dp();
  return 0;
}
