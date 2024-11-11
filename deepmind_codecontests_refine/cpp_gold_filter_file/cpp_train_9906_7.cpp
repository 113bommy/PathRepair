#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n;
vector<int> adj[MAXN], val[MAXN];
int del[MAXN];
int size[MAXN];
long long has[2], tot[2][2];
long long ans;
void dfs(int u, int p) {
  size[u] = 1;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (v != p && !del[v]) {
      dfs(v, u);
      size[u] += size[v];
    }
  }
}
int findcentroid(int u) {
  int p = -1;
  dfs(u, -1);
  int cap = size[u] >> 1;
  while (1) {
    bool found = false;
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      if (v != p && !del[v] && size[v] > cap) {
        found = true;
        p = u;
        u = v;
        break;
      }
    }
    if (!found) return u;
  }
}
void go(int u, int p, int g, int cnt) {
  for (int i = 0; i < (int)adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == p || del[v]) continue;
    int t = val[u][i];
    if (t != g && cnt) continue;
    has[t]++;
    go(v, u, t, cnt | (t != g));
  }
}
void work(int u) {
  tot[0][0] = tot[0][1] = tot[1][0] = tot[1][1] = 0;
  for (int i = 0; i < (int)adj[u].size(); i++) {
    has[0] = has[1] = 0;
    int v = adj[u][i];
    if (del[v]) continue;
    int t = val[u][i];
    has[t]++;
    go(v, u, t, 0);
    if (t) {
      ans += has[1] * 2;
      ans += has[0];
      ans += has[0] * tot[1][0];
      ans += has[1] * tot[1][0] * 2;
      ans += has[1] * tot[1][1];
      ans += has[1] * tot[0][0];
      tot[1][0] += has[1];
      tot[1][1] += has[0];
    } else {
      ans += has[0] * 2;
      ans += has[1];
      ans += has[1] * tot[0][0];
      ans += has[0] * tot[0][0] * 2;
      ans += has[0] * tot[0][1];
      ans += has[0] * tot[1][0];
      tot[0][0] += has[0];
      tot[0][1] += has[1];
    }
  }
}
void divide(int u) {
  u = findcentroid(u);
  del[u] = 1, work(u);
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (!del[v]) {
      divide(v);
    }
  }
}
int main() {
  cin >> n;
  for (int i = (0); i < (n - 1); i++) {
    int x, y, z;
    cin >> x >> y >> z;
    x--;
    y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
    val[x].push_back(z);
    val[y].push_back(z);
  }
  divide(0);
  cout << ans;
  return 0;
}
