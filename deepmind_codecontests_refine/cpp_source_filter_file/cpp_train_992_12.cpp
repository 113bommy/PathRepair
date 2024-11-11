#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int siz = 1e5 + 5;
int ans, cnt, root = -1, n, p[siz], vis[siz];
void go(int v) {
  vis[v] = cnt;
  if (!vis[p[v]])
    go(p[v]);
  else if (vis[p[v]] == cnt) {
    if (root != -1) {
      if (root != v) {
        ans++;
        p[v] = root;
      }
    } else {
      root = v;
      p[v] = v;
      ans++;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    if (i == p[i]) root = i;
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      cnt++;
      go(i);
    }
  }
  cout << ans << endl;
  for (int i = 1; i <= n; i++) cout << p[i] << " ";
}
