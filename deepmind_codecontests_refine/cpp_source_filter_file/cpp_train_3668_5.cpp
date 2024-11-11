#include <bits/stdc++.h>
using namespace std;
int a[200020];
vector<int> v[200020];
int w[200020];
int c[200020];
void dfs(int x, int y) {
  if (!a[x])
    c[x] = -1;
  else
    c[x] = 1;
  for (int i : v[x]) {
    if (i == y) continue;
    dfs(i, x);
    if (c[i] > 0) c[x] += c[i];
  }
}
void dfsutil(int x, int y, int z) {
  w[x] = c[x] + z;
  for (int i : v[x]) {
    if (i == y) continue;
    if (c[i] > 0)
      dfsutil(i, x, max(0, w[x] - c[i]));
    else
      dfsutil(i, x, w[x]);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n = 0, x = 0, y = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= (n - 1); ++i) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  dfs(1, 1);
  dfsutil(1, 1, 0);
  for (int i = 1; i <= n; ++i) {
    cout << w[i] << " ";
  }
}
