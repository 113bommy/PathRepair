#include <bits/stdc++.h>
using namespace std;
const int N = (int)5e5 + 5;
vector<pair<int, int> > t[N * 4];
int a[N], n, m, x, y;
map<int, int> hm;
void Build(int v, int l, int r) {
  if (l == r) {
    t[v].push_back(make_pair(a[l], l - a[l]));
  } else {
    int tm = (l + r) >> 1;
    Build(v + v, l, tm);
    Build(v + v + 1, tm + 1, r);
    x = y = 0;
    while (x < t[v + v].size() || y < t[v + v + 1].size()) {
      if (x < t[v + v].size() && y < t[v + v + 1].size()) {
        if (t[v + v][x].first < t[v + v + 1][y].first) {
          t[v].push_back(t[v + v][x]);
          x++;
        } else {
          t[v].push_back(t[v + v + 1][y]);
          y++;
        }
      } else if (x < t[v + v].size()) {
        t[v].push_back(t[v + v][x]);
        x++;
      } else {
        t[v].push_back(t[v + v + 1][y]);
        y++;
      }
    }
    for (int i = t[v].size() - 2; i >= 0; i--) {
      t[v][i].second = min(t[v][i].second, t[v][i + 1].second);
    }
  }
}
int Get(int v, int tl, int tr, int l, int r, int L) {
  if (l > r) {
    return (int)2e9;
  }
  if (tl == l && r == tr) {
    int pos =
        lower_bound(t[v].begin(), t[v].end(), make_pair(L, 0)) - t[v].begin();
    return pos == t[v].size() ? (int)2e9 : t[v][pos].second;
  }
  int tm = (tl + tr) >> 1;
  return min(Get(v + v, tl, tm, l, min(r, tm), L),
             Get(v + v + 1, tm + 1, tr, max(l, tm + 1), r, L));
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    a[i] = hm[x];
    if (a[i] == 0) {
      a[i] = -N;
    }
    hm[x] = i;
  }
  Build(1, 1, n);
  while (m--) {
    int l, r;
    scanf("%d%d", &l, &r);
    int ver = Get(1, 1, n, l, r, l);
    printf("%d\n", ver == (int)2e9 ? -1 : ver);
  }
  return 0;
}
