#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
const int N = 200010;
inline int read() {
  int s = 0, w = 1;
  register char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
  return s * w;
}
int n, m, P, K, a[N], tag[N << 2];
vector<pair<int, int>> g[N << 2];
inline vector<pair<int, int>> Merge(vector<pair<int, int>> x,
                                    vector<pair<int, int>> y) {
  for (auto i : y) {
    int flg = 0;
    for (auto &j : x)
      if (j.first == i.first) {
        j.second += i.second;
        flg = 1;
        break;
      }
    if (flg) continue;
    x.emplace_back(i);
    if ((int)x.size() <= K) continue;
    int mi = 1e9;
    for (auto j : x) mi = min(mi, j.second);
    vector<pair<int, int>> ch;
    for (auto j : x)
      if (j.second > mi) ch.emplace_back(make_pair(j.first, j.second - mi));
    x = ch;
  }
  return x;
}
void Build(int x, int l, int r) {
  if (l == r) {
    g[x].emplace_back(make_pair(a[l], 1));
    return;
  }
  int mid = (l + r) / 2;
  Build((x << 1), l, mid);
  Build((x << 1 | 1), mid + 1, r);
  g[x] = Merge(g[(x << 1)], g[(x << 1 | 1)]);
}
inline void Push_Down(int x, int l, int r) {
  int mid = (l + r) / 2;
  g[(x << 1)].clear(), g[(x << 1)].emplace_back(make_pair(tag[x], mid - l + 1));
  g[(x << 1 | 1)].clear(),
      g[(x << 1 | 1)].emplace_back(make_pair(tag[x], r - mid));
  tag[(x << 1)] = tag[(x << 1 | 1)] = tag[x];
  tag[x] = 0;
}
void UpDate(int u, int v, int l, int r, int x, int w) {
  if (l >= u && r <= v) {
    g[x].clear();
    g[x].emplace_back(make_pair(w, r - l + 1));
    tag[x] = w;
    return;
  }
  if (tag[x]) Push_Down(x, l, r);
  int mid = (l + r) / 2;
  if (u <= mid) UpDate(u, v, l, mid, (x << 1), w);
  if (v > mid) UpDate(u, v, mid + 1, r, (x << 1 | 1), w);
  g[x] = Merge(g[(x << 1)], g[(x << 1 | 1)]);
}
vector<pair<int, int>> Ask(int u, int v, int l, int r, int x) {
  if (l >= u && r <= v) return g[x];
  if (tag[x]) Push_Down(x, l, r);
  int mid = (l + r) / 2;
  vector<pair<int, int>> tt;
  if (u <= mid) tt = Merge(tt, Ask(u, v, l, mid, (x << 1)));
  if (v > mid) tt = Merge(tt, Ask(u, v, mid + 1, r, (x << 1 | 1)));
  return tt;
}
signed main() {
  n = read(), m = read(), P = read(), K = 100 / P;
  for (register int i = 1; i <= n; i++) a[i] = read();
  Build(1, 1, n);
  for (register int i = 1; i <= m; i++) {
    int opt = read();
    if (opt == 1) {
      int l, r, w;
      l = read(), r = read(), w = read();
      UpDate(l, r, 1, n, 1, w);
    } else {
      int l, r;
      l = read(), r = read();
      vector<pair<int, int>> ans = Ask(l, r, 1, n, 1);
      printf("%d", (int)ans.size());
      for (auto i : ans) printf(" %d", i);
      puts("");
    }
  }
  return 0;
}
