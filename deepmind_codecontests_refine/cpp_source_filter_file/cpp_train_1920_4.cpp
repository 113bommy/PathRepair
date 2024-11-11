#include <bits/stdc++.h>
using namespace std;
const long long linf = 1e18 + 5;
const int mod = 1e9 + 7;
const int logN = 17;
const int inf = 1e9;
const int N = 1e5 + 5;
int n, m, x, y, depth[N], mx[N][3], rmq[N][logN + 1], lca[N][logN + 1],
    lp[N][logN + 1], start[N], finish[N], T;
int LOG[N], lp2[N][logN + 1];
vector<int> v[N];
int get(int x, int y) {
  if (x > y) return 0;
  int t = LOG[y - x + 1];
  return max(rmq[x][t], rmq[y - (1 << t) + 1][t]);
}
int take(int x, int t) {
  int ans = 0, y = x;
  if (t <= 0) return -inf;
  for (int i = 0; i <= logN; i++)
    if (t & (1 << i)) {
      ans = max(ans, lp[x][i] + depth[y] - depth[x]);
      x = lca[x][i];
    }
  return ans;
}
int take2(int x, int t) {
  int ans = 0, tt = depth[x] - t;
  if (t <= 0) return -inf;
  for (int i = 0; i <= logN; i++)
    if (t & (1 << i)) {
      ans = max(ans, lp2[x][i] + (depth[x] - (1 << i)) - tt);
      x = lca[x][i];
    }
  return ans;
}
int w1(int node, int x) {
  if (node == x) return 0;
  return max(get(start[node], start[x] - 1), get(finish[x] + 1, finish[node])) -
         depth[node];
}
int w2(int node, int x, int y) {
  if (node == x || node == y) return 0;
  if (start[x] > start[y]) swap(x, y);
  return max(get(start[node], start[x] - 1),
             max(get(finish[x] + 1, start[y] - 1),
                 get(finish[y] + 1, finish[node]))) -
         depth[node];
}
int calc(int x, int t) {
  for (int i = 0; i <= logN; i++)
    if (t & (1 << i)) x = lca[x][i];
  return x;
}
int bef(int node, int x) { return calc(node, depth[node] - depth[x] - 1); }
int take_max(int node) {
  int root = lca[node][0];
  if (mx[root][1] == mx[node][1] + 1) return mx[root][2] + 1;
  return mx[root][1] + 1;
}
int LCA(int x, int y) {
  if (depth[x] < depth[y]) swap(x, y);
  int diff = depth[x] - depth[y];
  for (int i = 0; i <= logN; i++)
    if (diff & (1 << i)) x = lca[x][i];
  if (x == y) return x;
  for (int i = logN; i >= 0; i--)
    if (lca[x][i] != lca[y][i]) x = lca[x][i], y = lca[y][i];
  return lca[x][0];
}
int solve(int x, int y) {
  int l = LCA(x, y);
  int dist = depth[x] + depth[y] - 2 * depth[l];
  dist >>= 1;
  if (depth[x] == depth[y] || (depth[x] + 1 == depth[y] && l != x)) {
    int ans =
        max(take(x, depth[x] - depth[l] - 1),
            max(mx[x][1], w2(l, bef(x, l), bef(y, l)) + depth[x] - depth[l]));
    ans = max(max(ans, take(l, depth[l]) + depth[x] - depth[l]),
              max(mx[y][1], take(y, depth[y] - depth[l] - 1)));
    return ans;
  }
  if (depth[x] - depth[l] > dist) {
    int ans = max(take(x, dist), mx[x][1]), node = calc(x, dist);
    int t = max(take2(node, depth[node] - depth[l] - 1) + 1,
                max(take(l, depth[l]), w2(l, bef(x, l), bef(y, l)))) +
            depth[y] - depth[l];
    if (l != y)
      ans = max(max(max(ans, take(y, depth[y] - depth[l] - 1)), mx[y][1]), t);
    else
      ans = max(max(w1(y, node), ans), take(y, depth[y]));
    return ans;
  }
  return solve(y, x);
}
void dfs(int node, int root) {
  lca[node][0] = root;
  start[node] = ++T;
  depth[node] = depth[root] + 1;
  for (__typeof(v[node].begin()) it = v[node].begin(); it != v[node].end();
       it++)
    if (*it != root) {
      int c = *it;
      dfs(c, node);
      if (mx[c][1] + 1 >= mx[node][1]) {
        mx[node][2] = mx[node][1];
        mx[node][1] = mx[c][1] + 1;
      } else if (mx[c][2] + 1 >= mx[node][2])
        mx[node][2] = mx[c][1] + 1;
    }
  rmq[start[node]][0] = depth[node];
  finish[node] = T;
}
int main() {
  ios_base::sync_with_stdio(false);
  for (int i = 1; i <= N - 1; i++) LOG[i] = log2(i);
  cin >> n;
  for (int i = 2; i <= n; i++) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  depth[0] = -1;
  dfs(1, 0);
  for (int i = 2; i <= n; i++) {
    lp[i][0] = take_max(i);
    lp2[i][0] = lp[i][0] - 1;
  }
  for (int j = 1; j <= logN; j++)
    for (int i = 1; i <= n; i++) {
      lca[i][j] = lca[lca[i][j - 1]][j - 1];
      lp[i][j] = max(lp[i][j - 1], lp[lca[i][j - 1]][j - 1] + (1 << j - 1));
      lp2[i][j] = max(lp2[i][j - 1] + (1 << j - 1), lp[lca[i][j - 1]][j - 1]);
      rmq[i][j] = max(rmq[i][j - 1], rmq[min(n, i + (1 << j - 1))][j - 1]);
    }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> x >> y;
    cout << solve(x, y) << '\n';
  }
  return 0;
}
