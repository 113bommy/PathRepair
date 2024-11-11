#include <bits/stdc++.h>
using namespace std;
struct node {
  int num;
  int x, y;
} a[200005], c[200005], b[200005];
vector<int> ret;
int n;
int m;
bool vis[200005];
bool cmp(node a, node b) {
  if (a.x != b.x) return a.x < b.x;
  return a.y > b.y;
}
bool judge(node p0, node p1, node p2) {
  int k1 = p2.y, k2 = p1.y, k3 = p0.y, k4 = p2.x, k5 = p1.x, k6 = p0.x;
  return 1ll * (k1 * k3 - k2 * k3) * (k4 * k6 - k4 * k5) >
         1ll * (k1 * k2 - k1 * k3) * (k5 * k6 - k4 * k6);
}
void tubao() {
  m = 1;
  c[1] = a[1];
  for (int i = 2; i <= n; i++) {
    if (a[i].x == a[i - 1].x) continue;
    while (m >= 2 && judge(a[i], c[m], c[m - 1])) m--;
    c[++m] = a[i];
  }
  for (int i = 1; i <= m; i++) vis[c[i].num] = 1;
  for (int i = 2; i <= m; i++) {
    if (c[i - 1].y <= c[i].y) {
      vis[c[i].num] = 0;
    } else
      break;
  }
  for (int i = 2; i <= n; i++) {
    if (a[i].y == a[i - 1].y && a[i].x == a[i - 1].x && vis[a[i - 1].num])
      vis[a[i].num] = true;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i].x, &a[i].y);
    a[i].num = i;
  }
  sort(a + 1, a + n + 1, cmp);
  tubao();
  for (int i = 1; i <= n; i++) {
    if (vis[i]) printf("%d ", i);
  }
  return 0;
}
