#include <bits/stdc++.h>
using namespace std;
const int INF = (2e9) + 7;
const int maxn = 100100;
int h, w, n;
stack<pair<int, int> > q[maxn];
int u[maxn], l[maxn], r[maxn], s[maxn], p[maxn];
pair<int, int> minh[maxn << 2];
int cnt;
void build(int t, int l, int r) {
  minh[t] = make_pair(h + 1, l);
  if (l == r) {
    q[l].push(make_pair(h + 1, 1));
    return;
  }
  int mid = (l + r) >> 1;
  build(t << 1, l, mid);
  build(t << 1 | 1, mid + 1, r);
}
void insert(int t, int l, int r, int x, int h, int num) {
  if (l == r) {
    q[l].push(make_pair(h, num));
    minh[t] = make_pair(h, l);
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid)
    insert(t << 1, l, mid, x, h, num);
  else
    insert(t << 1 | 1, mid + 1, r, x, h, num);
  minh[t] = min(minh[t << 1], minh[t << 1 | 1]);
}
void ask(int t, int l, int r, int x, int y, int lim) {
  if (minh[t].first > lim) return;
  if (l == r) {
    while (!q[l].empty() && q[l].top().first <= lim) {
      (cnt += q[l].top().second) >= 1000000007 && (cnt -= 1000000007);
      q[l].pop();
    }
    minh[t] = q[l].empty() ? make_pair(INF, 0) : make_pair(q[l].top().first, l);
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid) ask(t << 1, l, mid, x, y, lim);
  if (y > mid) ask(t << 1 | 1, mid + 1, r, x, y, lim);
  minh[t] = min(minh[t << 1], minh[t << 1 | 1]);
}
int main() {
  scanf("%d%d%d", &h, &w, &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d%d%d", u + i, l + i, r + i, s + i);
    p[i] = i;
  }
  sort(p + 1, p + n + 1, [](int i, int j) { return u[i] > u[j]; });
  build(1, 1, w);
  for (int i = 1; i <= n; ++i) {
    int x = p[i];
    cnt = 0;
    ask(1, 1, w, l[x], r[x], u[x] + s[x]);
    if (cnt) {
      (l[x] == 1 || r[x] == w) && (cnt += cnt) >= 1000000007 &&
          (cnt -= 1000000007);
      if (r[x] < w) insert(1, 1, w, r[x] + 1, u[i], cnt);
      if (l[x] > 1) insert(1, 1, w, l[x] - 1, u[i], cnt);
    }
  }
  int res = 0;
  for (int i = 1; i <= w; ++i)
    while (!q[i].empty())
      (res += q[i].top().second) >= 1000000007 && (res -= 1000000007),
          q[i].pop();
  printf("%d\n", res);
  return 0;
}
