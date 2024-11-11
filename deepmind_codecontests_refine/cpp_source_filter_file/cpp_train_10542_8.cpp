#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int f[N][N];
struct node {
  int x, y;
} a[N], b[N];
bool cmp(node x, node y) { return x.y < y.y; }
bool toleft(node a, node b, node c) {
  if (c.y <= a.y || c.y > b.y) return 0;
  if (a.x * b.y - a.y * b.x + b.x * c.y - b.y * c.x + c.x * a.y - c.y * a.x > 0)
    return 1;
  return 0;
}
int n, m, ans;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
  for (int i = 1; i <= m; i++) cin >> b[i].x >> b[i].y;
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i < n; i++)
    for (int j = i + 1; j <= n; j++)
      for (int k = 1; k <= m; k++)
        if (toleft(a[i], a[j], b[k])) f[i][j]++;
  for (int i = 1; i < n; i++)
    for (int j = i + 1; j < n; j++)
      for (int k = j + 1; k <= n; k++)
        if (f[i][j] + f[j][k] == f[i][k]) ans++;
  cout << ans;
  return 0;
}
