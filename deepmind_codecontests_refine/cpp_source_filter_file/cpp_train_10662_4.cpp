#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int maxn = 2e5 + 5;
int tin[maxn], tout[maxn];
int timer;
vector<int> vis;
vector<int> g[maxn];
int level[maxn];
void dfs(int s, int par) {
  int i;
  tin[s] = ++timer;
  vis.push_back(s);
  int l = g[s].size();
  if (s == 1)
    level[s] = 0;
  else
    level[s] = level[par] + 1;
  for (i = 0; i < l; i++) {
    if (g[s][i] != par) dfs(g[s][i], s);
  }
  tout[s] = timer;
}
int BIT[1000006];
long long sum(int idx) {
  if (idx == 0) return 0;
  int res = 0;
  while (idx > 0) {
    res += (long long)BIT[idx];
    idx -= (idx & -idx);
  }
  return res;
}
void update(int idx, int val) {
  while (idx < 1000006) {
    BIT[idx] += val;
    idx += idx & -idx;
  }
}
long long value[100005];
int main() {
  int n, t, m, l, k, ans, i, j, res = 0, fl;
  t = 1;
  int q, x, y;
  while (t--) {
    scanf("%d", &n);
    scanf("%d", &q);
    for (i = 1; i <= n; i++) cin >> value[i];
    for (i = 0; i < n - 1; i++) {
      scanf("%d", &x);
      scanf("%d", &y);
      g[x].push_back(y);
      g[y].push_back(x);
    }
    vis.push_back(0);
    timer = 0;
    dfs(1, -1);
    int ct = 1;
    while (q--) {
      scanf("%d", &x);
      if (x == 2) {
        int idx;
        scanf("%d", &idx);
        int right = tout[idx];
        int left = tin[idx];
        if (level[idx] % 2 == 0)
          cout << value[idx] + sum(left) << endl;
        else
          cout << value[idx] - sum(left) << endl;
      } else {
        scanf("%d", &x);
        scanf("%d", &y);
        int left = tin[x];
        int right = tout[x];
        if (level[x] % 2 == 0) {
          update(left, y);
          update(right + 1, -y);
        } else {
          update(left, -y);
          update(right + 1, y);
        }
      }
    }
  }
  return 0;
}
