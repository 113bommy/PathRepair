#include <bits/stdc++.h>
using namespace std;
struct node {
  int v, c, l, r, s, id;
} a[100010];
int n, mx, dp[100010], pre[100010];
vector<int> ans;
map<int, pair<int, int> > mp;
bool cmp(node x, node y) {
  if (x.s == y.s) {
    return x.l < y.l;
  }
  return x.s < y.s;
}
void update(int x) {
  ans.clear();
  for (int i = x; i; i = pre[i]) {
    ans.push_back(a[i].id);
  }
}
void work(int l, int r) {
  mp.clear();
  for (int i = l; i <= r; i++) {
    if (mp[a[i].l].first == 0 && a[i].l) {
      continue;
    }
    dp[i] = mp[a[i].l].first + a[i].v;
    pre[i] = mp[a[i].l].second;
    if (mp[a[i].l + a[i].c].first < dp[i]) {
      mp[a[i].l + a[i].c].first = dp[i];
      mp[a[i].l + a[i].c].second = i;
    }
    if (a[i].r == 0 && mx < dp[i]) {
      mx = dp[i];
      update(i);
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d%d", &a[i].v, &a[i].c, &a[i].l, &a[i].r);
    a[i].s = a[i].c + a[i].l + a[i].r;
    a[i].id = i;
  }
  sort(a + 1, a + n + 1, cmp);
  int l = 1;
  for (int i = 2; i <= n; i++) {
    if (a[i].s != a[l].s) {
      work(l, i - 1);
      l = i;
    }
  }
  work(l, n);
  sort(ans.begin(), ans.end());
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}
