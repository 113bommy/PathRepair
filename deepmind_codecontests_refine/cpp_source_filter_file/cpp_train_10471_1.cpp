#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const int inf = 0x3f3f3f3f;
const double eps = 1e-7;
const int maxn = 1e5 + 7;
int r[maxn][3];
int par[maxn * 2];
int find(int x) {
  if (par[x] == x)
    return x;
  else
    return par[x] = find(par[x]);
}
void unite(int x, int y) {
  x = find(x), y = find(y);
  if (x != y) par[x] = y;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= 2 * n; i++) par[i] = i;
  for (int i = 1; i <= n; i++) scanf("%d", &r[i][0]);
  for (int i = 1; i <= m; i++) {
    int xi;
    cin >> xi;
    while (xi--) {
      int x;
      cin >> x;
      if (r[x][1])
        r[x][2] = i;
      else
        r[x][1] = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    int x = r[i][1], y = r[i][2];
    if (r[i][0]) {
      if (find(x) == find(y + n))
        return 0 * printf("NO\n");
      else {
        unite(x, y);
        unite(x + n, y + n);
      }
    } else {
      if (find(x) == find(y))
        return 0 * printf("NO\n");
      else {
        unite(x, y + n);
        unite(x + n, y);
      }
    }
  }
  printf("YES\n");
  return 0;
}
