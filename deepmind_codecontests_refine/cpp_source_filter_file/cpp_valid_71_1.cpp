#include <bits/stdc++.h>
using namespace std;
int a[150];
int vis[10];
long long ans, len;
string s;
void dfs(int p, int k, long long n, int f) {
  if (k == -1) return;
  if (p >= len) {
    ans = min(ans, n);
    return;
  }
  if (f) {
    int mn;
    if (k)
      mn = 0;
    else {
      for (int i = 0; i < 10; i++) {
        if (vis[i]) {
          mn = i;
          break;
        }
      }
    }
    for (int i = p; i < len; i++) n = n * 10 + mn;
    ans = min(ans, n);
    return;
  }
  ++vis[s[p] - '0'];
  dfs(p + 1, k - (vis[s[p] - '0'] == 1), n * 10 + s[p] - '0', 0);
  --vis[s[p] - '0'];
  if (s[p] != '9') {
    ++vis[s[p] - '0' + 1];
    dfs(p + 1, k - (vis[s[p] - '0' + 1] == 1), n * 10 + s[p] - '0' + 1, 1);
    --vis[s[p] - '0' + 1];
  }
  int fd = 0;
  for (int i = s[p] - '0' + 2; i < 10; i++) {
    if (vis[i]) {
      fd = i;
      break;
    }
  }
  if (fd) {
    ++vis[fd];
    dfs(p + 1, k, n * 10 + fd, 1);
    --vis[fd];
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    s = to_string(n);
    len = s.size();
    ans = 111111111;
    dfs(0, k, 0, 0);
    cout << ans << '\n';
  }
  return 0;
}
