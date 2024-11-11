#include <bits/stdc++.h>
using namespace std;
vector<int> v[100001];
int niv[100001];
int rmq[18][100001];
int s[100001];
void dfs(int r, int t) {
  s[r] = 1;
  int i;
  for (i = 0; i < v[r].size(); i++)
    if (v[r][i] != t) {
      rmq[0][v[r][i]] = r;
      niv[v[r][i]] = 1 + niv[r];
      dfs(v[r][i], r);
      s[r] = s[r] + s[v[r][i]];
    }
}
int rmqq(int x, int d) {
  int i;
  for (i = 0; i < 18; i++)
    if (d & (1 << i)) x = rmq[i][x];
  return x;
}
int lca(int x, int y) {
  int i, d;
  if (niv[x] > niv[y]) swap(x, y);
  d = niv[y] - niv[x];
  y = rmqq(y, d);
  if (x == y) return x;
  for (i = 17; i >= 0; i--)
    if (rmq[i][x] != rmq[i][y]) {
      x = rmq[i][x];
      y = rmq[i][y];
    }
  return rmq[0][x];
}
int main() {
  int n, q, i, j, x, y, z, rau1, rau2;
  cin >> n;
  for (i = 1; i < n; i++) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  niv[1] = 1;
  dfs(1, 0);
  for (i = 1; (1 << i) <= n; i++)
    for (j = 1; j <= n; j++) rmq[i][j] = rmq[i - 1][rmq[i - 1][j]];
  cin >> q;
  for (i = 1; i <= q; i++) {
    cin >> x >> y;
    if (x == y) {
      cout << n << '\n';
      continue;
    }
    if (niv[x] > niv[y]) swap(x, y);
    z = lca(x, y);
    j = niv[x] + niv[y] - 2 * niv[z];
    if (j & 1)
      cout << "0\n";
    else {
      if (z == x) {
        z = rmqq(y, j / 2);
        rau1 = rmqq(y, j / 2 - 1);
        cout << s[z] - s[rau1] << '\n';
      } else {
        if (niv[x] == niv[y]) {
          rau1 = rmqq(x, j / 2 - 1);
          rau2 = rmqq(y, j / 2 - 1);
          cout << n - (s[rau1] + s[rau2]) << '\n';
        } else {
          z = rmqq(y, j / 2);
          rau1 = rmqq(y, j / 2 - 1);
          cout << s[z] - s[rau1] << '\n';
        }
      }
    }
  }
  return 0;
}
