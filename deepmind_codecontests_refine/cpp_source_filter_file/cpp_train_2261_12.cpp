#include <bits/stdc++.h>
using namespace std;
struct A {
  int p1, p2;
} a[1000000];
int vis[1000000], go[1000000];
int main() {
  int n, x, tot = 0;
  long long ans = 0;
  cin >> n;
  for (register int i = 1; i <= n + n; i++) {
    cin >> x;
    if (!vis[x])
      a[vis[x] = ++tot].p1 = i, go[i] = tot;
    else
      a[vis[x]].p2 = i, go[i] = -tot;
  }
  for (register int i = 1; i <= tot; i++) {
    ans += a[i].p2 - a[i].p1 - 1;
    for (register int j = a[i].p2 - 1; j > a[i].p1; j--)
      if (go[j] > 0)
        go[++a[go[j]].p1] = go[j];
      else
        go[++a[-go[j]].p2] = go[j];
  }
  cout << ans;
  return 0;
}
