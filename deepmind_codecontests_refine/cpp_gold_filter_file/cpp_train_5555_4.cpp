#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100010], cnt[100010], ans[100010], c[100010];
struct node {
  int l, r, id;
} p[100010];
vector<int> pos[100010];
int lowbit(int x) { return x & (-x); }
void add(int x, int y) {
  while (x <= n) c[x] += y, x += lowbit(x);
}
int find(int x) {
  int ans = 0;
  while (x) ans += c[x], x -= lowbit(x);
  return ans;
}
bool cmp(node a, node b) { return a.r < b.r; }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &p[i].l, &p[i].r);
    p[i].id = i;
  }
  sort(p + 1, p + m + 1, cmp);
  int t = 1;
  for (int i = 1; i <= n; i++) {
    if (a[i] > n) continue;
    cnt[a[i]]++;
    pos[a[i]].push_back(i);
    if (cnt[a[i]] >= a[i]) {
      add(pos[a[i]][cnt[a[i]] - a[i]], 1);
      if (cnt[a[i]] > a[i]) add(pos[a[i]][cnt[a[i]] - a[i] - 1], -2);
      if (cnt[a[i]] > a[i] + 1) add(pos[a[i]][cnt[a[i]] - a[i] - 2], 1);
    }
    while (p[t].r == i && t <= m) {
      ans[p[t].id] = find(p[t].r) - find(p[t].l - 1);
      t++;
    }
  }
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  return 0;
}
