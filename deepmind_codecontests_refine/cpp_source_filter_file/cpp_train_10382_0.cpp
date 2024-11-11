#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0;
  bool f = 1;
  char s = getchar();
  while ((s < '0' || s > '9') && s > 0) {
    if (s == '-') f ^= 1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') x = (x << 1) + (x << 3) + s - '0', s = getchar();
  return f ? x : -x;
}
int n, m, a, ans;
map<int, int> x;
map<int, int> mp;
struct que {
  int x1, x2, y1, y2;
  void ins() {
    x1 = read(), y1 = read(), x2 = read(), y2 = read();
    x[x1]++, x[x2]++, mp[y1]++, mp[y2 - 1]++;
  }
} Q[100005];
vector<int> sr[100005 << 1];
int mx[100005 << 3], mn[100005 << 3];
set<int> s[100005 << 3];
bool vis[100005];
inline void update(int x, bool f) {
  if (f)
    mn[x] = mx[x] = 0;
  else
    mx[x] = max(mx[x << 1], mx[x << 1 | 1]),
    mn[x] = min(mn[x << 1], mn[x << 1 | 1]);
  if (s[x].empty()) return;
  int h = *s[x].rbegin();
  mn[x] = max(mn[x], h);
  if (h > mx[x]) {
    if (vis[h] || h < mn[x])
      mx[x] = 0;
    else
      mx[x] = h;
  }
}
inline void sch(int x, int l, int r, int a, int b, int z) {
  if (l == a && r == b) {
    if (z > 0)
      s[x].insert(z);
    else
      s[x].erase(-z);
    update(x, l == r);
    return;
  }
  int mid = (l + r) >> 1;
  if (a <= mid) sch(x << 1, l, mid, a, min(mid, b), z);
  if (b > mid) sch(x << 1 | 1, mid + 1, r, max(a, mid + 1), b, z);
  update(x, 0);
}
signed main() {
  n = read();
  for (int i = 1; i <= n; i++) Q[i].ins();
  map<int, int>::iterator it;
  for (it = mp.begin(); it != mp.end(); it++) it->second = ++m;
  for (it = x.begin(); it != x.end(); it++) it->second = ++a;
  for (int i = 1; i <= n; i++) {
    Q[i].x1 = x[Q[i].x1], Q[i].x2 = x[Q[i].x2];
    Q[i].y1 = mp[Q[i].y1], Q[i].y2 = mp[Q[i].y2 - 1];
    sr[Q[i].x1].push_back(i), sr[Q[i].x2].push_back(-i);
  }
  for (int i = 1; i <= a; i++) {
    for (int j = 0; j < (int)sr[i].size(); j++) {
      int id = sr[i][j];
      if (id < 0) id = -id;
      sch(1, 1, m, Q[id].y1, Q[id].y2, sr[i][j]);
    }
    while (mx[1] && !vis[mx[1]]) {
      vis[mx[1]] = 1, ans++;
      sch(1, 1, m, Q[mx[1]].y1, Q[mx[1]].y2, 0);
    }
  }
  printf("%d\n", ans + 1);
  return 0;
}
