#include <bits/stdc++.h>
using namespace std;
int head[100010];
int nex[200010];
int to[200010];
int cnt = 0;
void add(int u, int v) {
  nex[++cnt] = head[u];
  to[cnt] = v;
  head[u] = cnt;
}
int vis[100010];
int x[100010];
int temp[400010];
int ans;
void dfs(int now, int fa) {
  vis[now] = 1;
  temp[ans++] = now;
  x[now] ^= 1;
  for (int i = head[now]; i; i = nex[i]) {
    int k = to[i];
    if (!vis[k]) {
      dfs(k, now);
      temp[ans++] = now;
      x[now] ^= 1;
    }
  }
  if (x[now]) {
    temp[ans++] = fa;
    x[fa] ^= 1;
    temp[ans++] = now;
    x[now] ^= 1;
  }
}
int main() {
  int n, m;
  int u, v;
  cin >> n >> m;
  while (m--) {
    cin >> u >> v;
    add(u, v);
    add(v, u);
  }
  int s = 0;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
    if (x[i]) s = i;
  }
  if (s) {
    dfs(s, 0);
    for (int i = 1; i <= n; i++) {
      if (!vis[i] && x[i]) {
        cout << "-1" << endl;
        return 0;
      }
    }
  }
  if (ans > 1 && temp[ans - 2] == 0) ans -= 3;
  cout << ans << endl;
  for (int i = 0; i < ans; i++) {
    cout << temp[i] << " ";
  }
  return 0;
}
