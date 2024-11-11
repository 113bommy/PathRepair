#include <bits/stdc++.h>
using namespace std;
int a[100005], b[100005], par[100005], sz[100005];
vector<int> v[100005];
int root(int x) {
  while (par[x] != x) {
    par[x] = par[par[x]];
    x = par[x];
  }
  return x;
}
void un(int x, int y) {
  int rx = root(x), ry = root(y);
  if (sz[rx] >= sz[ry]) {
    par[ry] = par[rx];
    sz[rx] += sz[ry];
    sz[ry] = 0;
  } else {
    par[rx] = par[ry];
    sz[ry] += sz[rx];
    sz[rx] = 0;
  }
}
int main() {
  int n, i, j;
  cin >> n;
  for (i = 0; i < n + 1; i++) {
    par[i] = i;
    sz[i] = 1;
  }
  for (i = 1; i < n + 1; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);
  for (i = 1; i < n + 1; i++) a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
  for (i = 1; i < n + 1; i++) un(i, a[i]);
  for (i = 1; i < n + 1; i++) {
    int r = root(i);
    v[r].push_back(i);
  }
  int ans = 0;
  for (i = 1; i < n + 1; i++) {
    if (i == root(i)) ans++;
  }
  cout << ans << "\n";
  for (i = 1; i < n + 1; i++) {
    if (i == root(i)) {
      cout << v[i].size() << " ";
      for (j = 0; j < v[i].size(); j++) cout << v[i][j] << " ";
      cout << "\n";
    }
  }
  return 0;
}
