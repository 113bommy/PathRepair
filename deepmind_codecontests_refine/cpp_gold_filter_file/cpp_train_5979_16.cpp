#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y, z;
} a[100005], b[100005], c[100005], d[100005];
bool cmp(node a, node b) { return a.x < b.x || (a.x == b.x && a.z > b.z); }
multiset<int> S;
int n, m, l, r;
bool check(int x) {
  int cnt1 = 0, cnt2 = 0;
  for (int i = 1; i <= n; i++)
    if (a[i].z >= x + x) {
      c[++cnt1].x = a[i].x;
      c[cnt1].y = a[i].y + x;
      c[cnt1].z = a[i].y + a[i].z - x;
    }
  for (int i = 1; i <= m; i++)
    if (b[i].z >= x + x) {
      d[++cnt2].x = b[i].x + x;
      d[cnt2].y = b[i].y;
      d[cnt2].z = 1;
      d[++cnt2].x = b[i].x + b[i].z - x + 1;
      d[cnt2].y = b[i].y;
      d[cnt2].z = -1;
    }
  sort(c + 1, c + cnt1 + 1, cmp);
  sort(d + 1, d + cnt2 + 1, cmp);
  int st = 1;
  S.clear();
  for (int i = 1; i <= cnt1; i++) {
    while (st <= cnt2 && d[st].x <= c[i].x) {
      if (d[st].z == 1)
        S.insert(d[st].y);
      else
        S.erase(d[st].y);
      st++;
    }
    set<int>::iterator x = S.lower_bound(c[i].y);
    if (x == S.end())
      continue;
    else if ((*x) <= c[i].z)
      return 1;
  }
  return 0;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
  for (int i = 1; i <= m; i++) scanf("%d%d%d", &b[i].x, &b[i].y, &b[i].z);
  l = 0;
  r = 1e9 + 7;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (check(mid))
      l = mid;
    else
      r = mid - 1;
  }
  printf("%d\n", l);
  return 0;
}
