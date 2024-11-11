#include <bits/stdc++.h>
using namespace std;
const int me = 100025;
int N;
int u[me], v[me], cnt[me], mask[me], used[me];
vector<int> edges[me];
long long x[me], y[me];
void dfs(int node, int step) {
  used[node] = 1;
  for (int i : edges[node]) {
    if (used[i]) continue;
    int where = -1;
    int tr = rand() % 123 + 10;
    while (tr--)
      for (int j = 0; j < 4; j++)
        if (!(mask[node] & (1 << j))) {
          where = j;
          break;
        }
    assert(where != -1);
    mask[node] |= 1LL << where;
    x[i] = x[node];
    y[i] = y[node];
    if (where == 0)
      x[i] += 1LL << step, mask[i] |= 2;
    else if (where == 1)
      x[i] -= 1LL << step, mask[i] |= 1;
    else if (where == 2)
      y[i] += 1LL << step, mask[i] |= 8;
    else
      y[i] -= 1LL << step, mask[i] |= 4;
    dfs(i, step - 2);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 1; i < N; i++) {
    cin >> u[i] >> v[i];
    edges[u[i]].push_back(v[i]);
    edges[v[i]].push_back(u[i]);
  }
  for (int i = 1; i <= N; i++) {
    if (edges[i].size() > 4) {
      cout << "NO" << endl;
      return 0;
    }
  }
  x[1] = 0, y[1] = 0;
  dfs(1, 59);
  cout << "YES" << endl;
  for (int i = 1; i <= N; i++) cout << x[i] << " " << y[i] << endl;
  return 0;
}
