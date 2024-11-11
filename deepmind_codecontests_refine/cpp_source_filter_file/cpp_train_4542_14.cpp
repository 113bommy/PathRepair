#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
vector<int> idx[maxn], w[maxn], side[maxn];
int scnt = 0;
int mem[maxn][maxn][maxn];
bool instk[maxn][maxn][maxn];
int x[maxn], size[maxn];
struct gg {
  int u, v, val;
} ori[maxn * 2 + 100];
void add(int u, int v, int val) {
  idx[u].push_back(++scnt);
  w[u].push_back(val);
  side[u].push_back(v);
  ori[scnt] = (gg){u, v, val};
}
void dfs1(int u, int fa) {
  for (int i = (0), iend = (side[u].size() - 1); i <= iend; i++) {
    int v = side[u][i];
    if (v == fa) continue;
    dfs1(v, u);
    size[u] += size[v];
  }
}
const int inf = 1e9;
int dp(int e, int tot, int cnt) {
  if (cnt > tot) return inf;
  if (ori[e].u == 3 && ori[e].v == 2 && tot == 1 && cnt == 1) {
    int ggg = 1;
  }
  if (mem[e][tot][cnt] < inf) return mem[e][tot][cnt];
  if (instk[e][tot][cnt]) return inf;
  instk[e][tot][cnt] = 1;
  int u = ori[e].v, fa = ori[e].u;
  if (side[u].size() == 1) {
    int cost;
    if (tot == cnt)
      cost = 0;
    else
      cost = dp(idx[u][0], tot - cnt, tot - cnt) + w[u][0];
    return (mem[e][tot][cnt] = cost);
  }
  int l = 0, r = inf;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    int cost = 0;
    for (int i = (0), iend = (side[u].size() - 1); i <= iend; i++) {
      int v = side[u][i];
      if (v == fa) continue;
      for (int j = tot; j >= 0; j--) {
        if (dp(idx[u][i], tot, j) + w[u][i] >= mid) {
          cost += j;
          break;
        }
      }
    }
    if (cost >= cnt)
      l = mid;
    else
      r = mid - 1;
  }
  return (mem[e][tot][cnt] = l);
}
int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = (1), iend = (n - 1); i <= iend; i++) {
    int u, v, val;
    cin >> u >> v >> val;
    add(u, v, val);
    add(v, u, val);
  }
  int s, m;
  cin >> s >> m;
  for (int i = (1), iend = (m); i <= iend; i++) cin >> x[i], size[x[i]] = 1;
  dfs1(s, 0);
  memset(mem, 0x3f, sizeof(mem));
  for (int i = (1), iend = (scnt); i <= iend; i++) mem[i][0][0] = 0;
  int ans = 1e9 + 100;
  for (int i = (0), iend = (side[s].size() - 1); i <= iend; i++) {
    ans = min(ans, dp(idx[s][i], m, size[side[s][i]]) + w[s][i]);
  }
  cout << ans;
  return 0;
}
