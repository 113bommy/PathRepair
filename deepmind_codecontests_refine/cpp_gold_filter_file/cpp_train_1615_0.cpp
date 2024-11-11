#include <bits/stdc++.h>
using namespace std;
const unsigned long long inf = (1ll << 62);
const unsigned long long mod = 1e9 + 7;
unsigned long long POW(unsigned long long x, unsigned long long y) {
  if (y == 0) return 1;
  if (y == 1) return x;
  unsigned long long ans = POW(x, y / 2) % mod;
  ans *= ans;
  ans %= mod;
  if (y % 2) ans *= x;
  return ans % mod;
}
unsigned long long gcd(unsigned long long x, unsigned long long y) {
  if (x < y) swap(x, y);
  if (y == 0) return x;
  return gcd(y, x % y);
}
unsigned long long LCM(unsigned long long x, unsigned long long y) {
  return x / gcd(x, y) * y;
}
const int MX = 123999;
int n, m, x, y, human[MX], dis[MX], blocked[MX], node, vis[MX], dis1[MX],
    deg[MX];
vector<int> v[MX];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d%d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &x);
    human[x] = 1;
    node = x;
  }
  queue<int> q;
  unsigned long long ans = 0;
  for (int i = 1; i <= n; i++) {
    deg[i] = v[i].size();
    if (deg[i] == 1) q.push(i);
  }
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    if (human[x]) continue;
    ans++;
    blocked[x] = 1;
    for (auto pp : v[x]) {
      deg[pp]--;
      if (deg[pp] == 1) {
        q.push(pp);
      }
    }
  }
  ans = n - ans;
  for (int i = 1; i <= n; i++) dis[i] = MX;
  dis[node] = 0;
  q.push(node);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    if (vis[x]) continue;
    vis[x] = 1;
    for (auto pp : v[x]) {
      if (blocked[pp]) continue;
      if (dis[pp] >= dis[x] + 1) {
        dis[pp] = dis[x] + 1;
        q.push(pp);
      }
    }
  }
  int mx = -1, ind;
  for (int i = 1; i <= n; i++) {
    if (blocked[i]) continue;
    if (dis[i] > mx) {
      mx = dis[i];
      ind = i;
    }
  }
  int minn = n + 1;
  for (int i = 1; i <= n; i++) {
    if (blocked[i]) continue;
    if (dis[i] == mx) minn = min(minn, i);
  }
  for (int i = 1; i <= n; i++) dis1[i] = MX;
  dis1[ind] = 0;
  q.push(ind);
  memset(vis, 0, sizeof(vis));
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    if (vis[x]) continue;
    vis[x] = 1;
    for (auto pp : v[x]) {
      if (blocked[pp]) continue;
      if (dis1[pp] >= dis1[x] + 1) {
        dis1[pp] = dis1[x] + 1;
        q.push(pp);
      }
    }
  }
  int mx1 = -1, ind1 = n + 1;
  for (int i = 1; i <= n; i++) {
    if (blocked[i]) continue;
    mx1 = max(mx1, dis1[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (blocked[i]) continue;
    if (dis1[i] == mx1) minn = min(minn, i);
  }
  ans--;
  ans *= 2;
  ans -= mx1;
  cout << minn << endl;
  cout << ans << endl;
}
