#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const int inf = 0x3f3f3f3f;
const double INF = 1e18;
const int mod = 1e9 + 7;
const int maxn = 20 + 5;
int cas = 1;
int vis[maxn];
long long int shu[maxn];
long long int a, b;
void dfs(int dep, long long int ans) {
  if (dep <= 0) {
    cout << ans << endl;
    exit(0);
  }
  for (long long int i = 9; i >= 0; i--) {
    if (vis[i] && ans + i * shu[dep] <= b) {
      vis[i]--;
      ans += i * shu[dep];
      dfs(dep - 1, ans);
      ans -= i * shu[dep];
      vis[i]++;
    }
  }
}
void solve() {
  cin >> a >> b;
  if (a == b) {
    cout << a << endl;
    return;
  }
  int len = 0;
  while (a) {
    vis[a % 10]++;
    a /= 10;
    len++;
  }
  long long int rat = 1;
  for (int i = 1; i <= len; i++) {
    shu[i] = rat;
    rat *= 10;
  }
  dfs(len, 0);
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
}
