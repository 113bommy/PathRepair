#include <bits/stdc++.h>
using namespace std;
int n, ans, x;
bool vis[2000000];
void solve() {
  bool flag = true;
  int minprime_novis = 2;
  memset(vis, false, sizeof(vis));
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    while (vis[minprime_novis]) minprime_novis++;
    if (flag)
      ans = x;
    else
      ans = minprime_novis;
    while (vis[ans]) ans++;
    if (ans > x) flag = false;
    if (i < n - 1)
      cout << ans << ' ';
    else
      cout << ans << endl;
    x = ans;
    for (int j = minprime_novis; j * j <= x; j++)
      if (x % j == 0) {
        if (vis[j]) flag = false;
        while (x % j == 0) x /= j;
        for (int k = j; k < 2000000; k += j) vis[k] = true;
      }
    if (x > 1) {
      int tmp = x;
      while (tmp < 2000000) {
        vis[tmp] = true;
        tmp += x;
      }
    }
  }
}
int main() {
  solve();
  return 0;
}
