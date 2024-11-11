#include <bits/stdc++.h>
using namespace std;
long long int finish[400001], through[400001], dia[400001], par[400001],
    vis[400001], parent;
vector<long long int> v[400001];
long long int find(long long int x) {
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}
void dfs(long long int cur, long long int p) {
  vis[cur] = 1;
  par[cur] = parent;
  long long int max1 = -1, max2 = -1;
  for (long long int i = 0; i < v[cur].size(); i++) {
    long long int x = v[cur][i];
    if (x == p) continue;
    dfs(x, cur);
    if (finish[x] > max1) {
      max2 = max1;
      max1 = finish[x];
    } else if (finish[x] > max2)
      max2 = finish[x];
  }
  if (max1 == -1 && max2 == -1) {
    finish[cur] = 0;
    through[cur] = 0;
  } else if (max1 != -1 && max2 == -1) {
    finish[cur] = max1 + 1;
    through[cur] = max1 + 1;
  } else {
    finish[cur] = max1 + 1;
    through[cur] = max1 + max2 + 2;
  }
  dia[parent] = max(dia[parent], through[cur]);
}
int main() {
  ios::sync_with_stdio(false);
  ;
  cin.tie(0);
  ;
  long long int i, j, n, m, q, x, y, dia1, dia2, xp, yp, type;
  cin >> n >> m >> q;
  for (i = 1; i <= m; i++) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for (i = 1; i <= n; i++) {
    if (vis[i]) continue;
    parent = i;
    dfs(i, -1);
  }
  while (q--) {
    cin >> type;
    if (type == 1) {
      cin >> x;
      cout << dia[find(x)];
    } else {
      cin >> x >> y;
      xp = find(x);
      yp = find(y);
      if (xp == yp) continue;
      dia1 = dia[xp];
      dia2 = dia[yp];
      par[xp] = yp;
      dia[yp] =
          max(dia[yp], max(dia[xp], (dia[xp] + 1) / 2 + (dia[yp] + 1) / 2 + 1));
    }
  }
  return 0;
}
