#include <bits/stdc++.h>
using namespace std;
int a[101];
int b[101];
int vis[101];
int n;
void dfs(int i) {
  vis[i] = 1;
  for (int k = 1; k <= n; k++) {
    if (!vis[k]) {
      if (a[k] < a[i] && a[i] < b[k])
        dfs(k);
      else if (a[k] < b[i] && b[i] < b[k])
        dfs(k);
    }
  }
}
int main() {
  cin >> n;
  int ind = 0;
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  for (int i = 1; i <= n; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      ind++;
      cin >> a[ind];
      cin >> b[ind];
    }
    if (type == 2) {
      int x, y;
      cin >> x >> y;
      memset(vis, 0, sizeof(vis));
      dfs(x);
      if (vis[y])
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
}
