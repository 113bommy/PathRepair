#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, ans;
vector<int> a[100005];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i)
    scanf("%d %d", &x, &y), a[x].push_back(y), a[y].push_back(x);
  for (int i = 1; i <= n; ++i) ans += (a[i].size() & 1);
  for (int i = 1; i <= n; ++i)
    if (a[i].size() == 2) {
      x = a[i][0], y = a[i][1];
      if (x == y)
        a[x].clear(), ans += 2;
      else
        a[x][a[x][0] != i] = y, a[y][a[y][0] != i] = x;
    }
  printf("%d %d\n", ans / 2, m);
  return 0;
}
