#include <bits/stdc++.h>
using namespace std;
const int maxn = 500010, inf = 1e9 + 233;
struct sgt {
  int mx, mn;
  set<int> s;
} tr[maxn << 2];
struct que {
  int x, y, x2, y2;
} q[maxn];
struct poi {
  int l, r, pos;
};
vector<poi> v[maxn];
int n, N1, N2;
int b1[maxn], b2[maxn];
bool vis[maxn];
template <typename T>
inline void read(T &k) {
  int f = 1;
  k = 0;
  char c = getchar();
  while (c < '0' || c > '9') c == '-' && (f = -1), c = getchar();
  while (c <= '9' && c >= '0') k = k * 10 + c - '0', c = getchar();
  k *= f;
}
inline void up(int x) {
  tr[x].mx = max(tr[x << 1].mx, tr[x << 1 | 1].mx);
  tr[x].mn = min(tr[x << 1].mn, tr[x << 1 | 1].mn);
  if (tr[x].s.size()) {
    int mx = *tr[x].s.rbegin();
    if (vis[mx])
      tr[x].mn = max(tr[x].mn, mx);
    else
      tr[x].mx = max(tr[x].mx, mx);
  }
  if (tr[x].mn > tr[x].mx) tr[x].mx = 0;
}
void update(int x, int l, int r, int cl, int cr, int ty) {
  if (cl <= l && r <= cr) {
    if (ty > 0)
      tr[x].s.insert(ty);
    else
      tr[x].s.erase(-ty);
    up(x);
    return;
  }
  int mid = (l + r) >> 1;
  if (cl <= mid) update(x << 1, l, mid, cl, cr, ty);
  if (cr > mid) update(x << 1 | 1, mid + 1, r, cl, cr, ty);
  up(x);
}
int main() {
  read(n);
  for (int i = 1; i <= n; i++) {
    read(q[i].x);
    read(q[i].y);
    read(q[i].x2);
    read(q[i].y2);
    b1[++N1] = q[i].x;
    b1[++N1] = q[i].x2;
    b2[++N2] = q[i].y;
    b2[++N2] = q[i].y2;
  }
  sort(b1 + 1, b1 + 1 + N1);
  sort(b2 + 1, b2 + 1 + N2);
  N1 = unique(b1 + 1, b1 + 1 + N1) - b1 - 1;
  N2 = unique(b2 + 1, b2 + 1 + N2) - b2 - 1;
  for (int i = 1; i <= n; i++)
    q[i].x = lower_bound(b1 + 1, b1 + 1 + N1, q[i].x) - b1,
    q[i].x2 = lower_bound(b1 + 1, b1 + 1 + N1, q[i].x2) - b1;
  for (int i = 1; i <= n; i++)
    q[i].y = lower_bound(b2 + 1, b2 + 1 + N2, q[i].y) - b2,
    q[i].y2 = lower_bound(b2 + 1, b2 + 1 + N2, q[i].y2) - b2;
  for (int i = 1; i <= n; i++) {
    v[q[i].x].push_back((poi){q[i].y, q[i].y2 - 1, i});
    v[q[i].x2].push_back((poi){q[i].y, q[i].y2 - 1, -i});
  }
  int ans = 0;
  for (int i = 1; i <= N1; i++) {
    for (int j = 0; j < v[i].size(); j++)
      update(1, 1, N2, v[i][j].l, v[i][j].r, v[i][j].pos);
    while (tr[1].mx) {
      vis[tr[1].mx] = 1;
      ans++;
      update(1, 1, N2, q[tr[1].mx].y, q[tr[1].mx].y2 - 1, 0);
    }
  }
  printf("%d\n", ans + 1);
}
