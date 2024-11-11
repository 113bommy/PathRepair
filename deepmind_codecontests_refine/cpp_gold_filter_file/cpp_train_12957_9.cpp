#include <bits/stdc++.h>
using namespace std;
int n, d;
int p[2005];
bool vis[2005];
vector<int> from[2005];
int f(int x, int y) {
  int i, a, ans;
  vis[x] = true;
  ans = 1;
  for (i = 0; i < from[x].size(); i++) {
    a = from[x][i];
    if (p[a] >= p[y] && p[a] - p[y] <= d && !vis[a]) {
      if (p[a] == p[y] && y <= a) continue;
      ans = ((long long)(ans) * (f(a, y) + 1)) % 1000000007;
    }
  }
  return ans;
}
int main() {
  int i, x, y;
  int ans;
  scanf("%d%d", &d, &n);
  for (i = 0; i < n; i++) scanf("%d", &p[i]);
  for (i = 0; i < n - 1; i++) {
    scanf("%d%d", &x, &y);
    x--;
    y--;
    from[x].push_back(y);
    from[y].push_back(x);
  }
  ans = 0;
  for (i = 0; i < n; i++) {
    memset(vis, 0, sizeof(vis));
    ans = (ans + f(i, i)) % 1000000007;
  }
  printf("%d", ans);
}
