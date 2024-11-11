#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
struct node {
  int l, r;
};
node a[N];
int vis[N];
int v1[N], v2[N];
int solve(int x, int y) {
  if (a[x].l > a[y].l) {
    swap(x, y);
  }
  if (a[x].r < a[y].l) return 0;
  if (a[x].r > a[y].r) {
    return v2[a[y].r] - v2[a[y].l - 1];
  }
  return v2[a[x].r] - v2[a[y].l - 1];
}
int main() {
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= q; i++) {
    cin >> a[i].l >> a[i].r;
    for (int j = a[i].l; j <= a[i].r; j++) {
      vis[j]++;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i] > 0) ans++;
    if (vis[i] == 1) v1[i] = 1;
    if (vis[i] == 2) v2[i] = 1;
    v1[i] += v1[i - 1];
    v2[i] += v2[i - 1];
  }
  int res = 10000;
  for (int i = 1; i <= q; i++) {
    for (int j = 1; j <= q; j++) {
      if (i == j) continue;
      int tt = 0;
      tt += v1[a[i].r] - v1[a[i].l - 1];
      tt += v1[a[j].r] - v1[a[j].l - 1];
      tt += solve(i, j);
      res = min(res, tt);
    }
  }
  cout << ans - res << endl;
}
