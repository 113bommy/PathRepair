#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int SQRTN = 320;
const int LOGN = 20;
const int PI = acos(-1);
int n, a[N], c[N];
vector<vector<int> > loops;
vector<int> loop, v;
int vis[N];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", c + i);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= n; i++) {
    int x = i;
    if (vis[x]) continue;
    while (!vis[x]) {
      vis[x] = i;
      x = a[x];
    }
    if (vis[x] != i) continue;
    loop.clear();
    loop.push_back(x);
    while (a[x] != loop[0]) {
      loop.push_back(a[x]);
      x = a[x];
    }
    loops.push_back(loop);
  }
  int ans = 0;
  for (int i = 0; i < loops.size(); i++) {
    int mn = 1e9;
    for (int j = 0; j < loops[i].size(); j++) {
      mn = min(mn, c[loops[i][j]]);
    }
    ans += mn;
  }
  cout << ans << endl;
  return 0;
}
