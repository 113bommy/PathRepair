#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 50;
const long long mod = 1e9 + 7;
int s[maxn << 2];
int a[maxn];
int last[maxn];
int vis[maxn];
void update(int l, int r, int pos, int k, int val) {
  if (l == r) {
    s[k] = val;
    return;
  }
  int mid = (l + r) / 2;
  if (pos <= mid)
    update(l, mid, pos, k * 2, val);
  else
    update(mid + 1, r, pos, k * 2 + 1, val);
  s[k] = min(s[k * 2], s[k * 2 + 1]);
}
int query(int l, int r, int a, int b, int k) {
  if (l >= a && b >= r) {
    return s[k];
  }
  int mid = (l + r) / 2;
  int res = 1e7;
  if (mid >= a) res = min(res, query(l, mid, a, b, k * 2));
  if (mid < b) res = min(res, query(mid + 1, r, a, b, k * 2 + 1));
  return res;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] == 1) {
      last[1] = i;
      update(1, n, a[i], 1, i);
      continue;
    }
    if (!vis[a[i]] && query(1, n, 1, a[i] - 1, 1) > last[a[i]]) vis[a[i]] = 1;
    last[a[i]] = i;
    update(1, n, a[i], 1, i);
    vis[1] = 1;
  }
  for (int i = 2; i <= n; i++) {
    if (!vis[i] && query(1, n, 1, i - 1, 1) > last[i]) vis[i] = 1;
  }
  int ans = 0;
  while (vis[++ans])
    ;
  printf("%d", ans);
  return 0;
}
