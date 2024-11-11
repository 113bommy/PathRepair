#include <bits/stdc++.h>
using namespace std;
int n, i, j, a, b, c;
const int MAXN = 200;
struct E {
  int dest;
  int cost;
};
vector<E> edge[MAXN];
int ar[MAXN][MAXN];
int was[MAXN];
E t;
vector<int> order;
void dfs(int v) {
  was[v] = true;
  order.push_back(v);
  for (int i = 0; i < edge[v].size(); ++i) {
    if (!was[edge[v][i].dest]) {
      dfs(edge[v][i].dest);
    }
  }
};
int ans = 0;
int main() {
  cin >> n;
  for (i = 0; i < n; ++i) {
    cin >> a >> b >> c;
    t.dest = b;
    t.cost = 0;
    ar[a][b] = 0;
    edge[a].push_back(t);
    t.dest = a;
    t.cost = c;
    ar[b][a] = c;
    edge[b].push_back(t);
  }
  for (i = 0; i < n; ++i) {
    was[i] = 0;
  }
  dfs(1);
  int res;
  ans = 0;
  for (i = 0; i < order.size() - 1; ++i) {
    ans += ar[order[i]][order[i + 1]];
  }
  ans += ar[order[order.size() - 1]][order[0]];
  reverse(order.begin(), order.end());
  res = ans;
  ans = 0;
  for (i = 0; i < order.size() - 1; ++i) {
    ans += ar[order[i]][order[i + 1]];
  }
  ans += ar[order[order.size() - 1]][order[0]];
  res = min(res, ans);
  cout << res;
  return 0;
}
