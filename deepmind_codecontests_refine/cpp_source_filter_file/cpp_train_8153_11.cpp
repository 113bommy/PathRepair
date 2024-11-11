#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int a[N], n, t[4 * N];
vector<pair<int, int> > ans;
int comb(int x, int y) {
  if (a[x] < a[y])
    return x;
  else if (a[x] > a[y])
    return y;
  else
    return min(x, y);
}
void build(int v, int tl, int tr) {
  if (tl == tr)
    t[v] = tl;
  else {
    int tm = (tl + tr) >> 1;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v] = comb(t[v * 2], t[v * 2 + 1]);
  }
}
int mini(int v, int tl, int tr, int l, int r) {
  if (l > r) return N - 1;
  if (l == tl && r == tr) return t[v];
  int tm = (tl + tr) >> 1;
  return comb(mini(v * 2, tl, tm, l, min(tm, r)),
              mini(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r));
}
void count(int l, int r, int cur = 0) {
  if (l > r) return;
  int m = mini(1, 0, n - 1, l, r);
  for (int i = 0; i < a[m] - cur; i++) ans.push_back(make_pair(l + 1, r + 1));
  for (int prev = l; prev <= r;) {
    int re = mini(1, 0, n - 1, prev, r);
    if (a[m] != a[re]) re = r + 1;
    count(prev, re - 1, cur + a[m]);
    prev = re + 1;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  a[N - 1] = 2000000000;
  build(1, 0, n - 1);
  count(0, n - 1);
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < ans.size(); i++)
    printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}
