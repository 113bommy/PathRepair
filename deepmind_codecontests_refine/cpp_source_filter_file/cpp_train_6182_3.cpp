#include <bits/stdc++.h>
using namespace std;
long long int n, level[300005];
long long int vis[300005], subtree[300005], alltree[300005];
vector<long long int> v[300005];
long long int bitsize;
void dfs(long long int x, long long int num) {
  vis[x] = 1;
  subtree[x] = num;
  for (long long int i = 0; i < v[x].size(); i++) {
    if (!vis[v[x][i]]) {
      level[v[x][i]] = 1 + level[x];
      dfs(v[x][i], num);
    }
  }
}
struct {
  map<long long int, long long int> bit2;
  void update(long long int x, long long int val) {
    for (; x <= 300005; x += x & -x) bit2[x] += val;
  }
  long long int query(long long int x) {
    long long int sum = 0;
    for (; x > 0; x -= x & -x) {
      sum += bit2[x];
    }
    return sum;
  }
} bit[300005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long int i, j, k, nb, val, q, l, r, x, y, op, node, d, valroot = 0,
                                                              mxlevel = 0;
  memset(vis, 0, sizeof(vis));
  cin >> n >> q;
  for (i = 1; i < n; i++) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  level[1] = 0;
  for (i = 0; i < v[1].size(); i++) {
    vis[1] = 1;
    level[v[1][i]] = 1;
    dfs(v[1][i], i + 1);
  }
  while (q--) {
    cin >> op;
    if (op == 0) {
      cin >> node >> x >> d;
      if (d < level[node]) {
        long long int posl = level[node] - d + 1;
        long long int posr = level[node] + 2 + d;
        bit[subtree[node]].update(posl, x);
        bit[subtree[node]].update(posr, -x);
      } else if (d == level[node]) {
        long long int posr = level[node] + 2 + d;
        bit[0].update(1, x);
        bit[0].update(2, -x);
        bit[subtree[node]].update(2, x);
        bit[subtree[node]].update(posr, -x);
      } else if (d > level[node]) {
        long long int posl = 1;
        long long int posr = d - level[node] + 2;
        bit[0].update(1, x);
        bit[0].update(posr, -x);
        posl = posr + 1;
        posr = level[node] + d + 2;
        bit[subtree[node]].update(posl, x);
        bit[subtree[node]].update(posr, -x);
      }
    } else {
      cin >> node;
      if (node != 1)
        cout << bit[subtree[node]].query(level[node] + 1) +
                    bit[0].query(level[node] + 1)
             << endl;
      else
        cout << bit[0].query(1) << endl;
    }
  }
}
