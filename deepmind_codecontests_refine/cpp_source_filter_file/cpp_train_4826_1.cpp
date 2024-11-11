#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
int ik[N], du[N], vis[N], ok[N];
vector<int> e[N];
int bz;
void dfs(int u) {
  int k = e[u].size();
  if (du[u] & 1) bz = 1;
  vis[u] = 1;
  for (int i = 0; i < k; ++i) {
    int v = e[u][i];
    if (vis[v]) continue;
    dfs(v);
  }
}
int main() {
  int n = read(), m = read();
  for (int i = 1; i <= m; ++i) {
    int u = read(), v = read();
    ok[u] = ok[v] = 1;
    if (u == v) continue;
    ++du[u];
    ++du[v];
    e[u].push_back(v);
    e[v].push_back(u);
  }
  ok[1] = 1;
  int ans = 0, jd = 0, tot = 0;
  for (int i = 1; i <= n; ++i) {
    if (du[i] & 1) {
      ++ans;
      ++jd;
    } else if (!vis[i] && ok[i]) {
      bz = 0;
      ++tot;
      dfs(i);
      if (!bz) ans++;
    }
  }
  if (tot == 1 && jd == 0) {
    puts("0");
    return 0;
  }
  cout << ans / 2;
  return 0;
}
