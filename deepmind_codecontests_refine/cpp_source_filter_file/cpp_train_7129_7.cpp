#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> neigh[(1 << 20)];
int col[(1 << 20)];
bool used[(1 << 20)];
int dist[(1 << 20)];
bool isBip(int x, int cc) {
  col[x] = cc;
  bool ret = 1;
  for (int i = 0; i < neigh[x].size(); i++) {
    if (col[neigh[x][i]] == 0) {
      ret &= isBip(neigh[x][i], -cc);
    } else if (col[neigh[x][i]] == cc) {
      ret = 0;
    }
  }
  return ret;
}
queue<int> q;
int maxD(int x) {
  for (int i = 0; i <= n; i++) {
    dist[x] = 0;
  }
  q.push(x);
  dist[x] = 1;
  while (!q.empty()) {
    x = q.front();
    q.pop();
    for (int i = 0; i < neigh[x].size(); i++) {
      if (dist[neigh[x][i]]) {
        continue;
      }
      dist[neigh[x][i]] = dist[x] + 1;
      q.push(neigh[x][i]);
    }
  }
  int ret = 0;
  for (int i = 0; i <= n; i++) {
    ret = max(ret, dist[i]);
  }
  return ret - 1;
}
int par[1042], cans[1042];
int getP(int x) { return x == par[x] ? x : par[x] = getP(par[x]); }
int main() {
  cin >> n >> m;
  for (int i = 0; i <= n; i++) {
    par[i] = i;
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    neigh[a].push_back(b);
    neigh[b].push_back(a);
    int p1 = getP(a), p2 = getP(b);
    par[p1] = p2;
  }
  for (int i = 1; i <= n; i++) {
    if (col[i]) {
      continue;
    }
    if (!isBip(i, 1)) {
      cout << "-1\n";
      return 0;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    cans[getP(i)] = max(cans[getP(i)], maxD(i));
  }
  for (int i = 1; i <= n; i++) {
    if (i == getP(i)) {
      ans += cans[i];
    }
  }
  cout << ans << "\n";
  return 0;
}
