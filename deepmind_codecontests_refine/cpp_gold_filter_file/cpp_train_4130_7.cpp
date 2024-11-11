#include <bits/stdc++.h>
using namespace std;
int vis[10000], n, a[10000], ans[10000], cnt;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = n - 1; i >= 0; i--)
    if (!vis[a[i]]) ans[cnt++] = a[i], vis[a[i]] = 1;
  cout << cnt << endl;
  for (int i = cnt - 1; i >= 0; i--) cout << ans[i] << " ";
  return 0;
}
