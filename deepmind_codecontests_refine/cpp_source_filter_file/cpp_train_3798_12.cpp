#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
using namespace std;
template <typename T>
void uin(T &a, T b) {
  if (b < a) a = b;
}
template <typename T>
void uax(T &a, T b) {
  if (b > a) a = b;
}
const int maxn = 100 * 1000 + 228, INF = 1e9 + 228;
struct rect {
  int x1, y1228, x2, y2;
  rect() {}
  rect(int _x1, int _y1, int _x2, int _y2) {
    x1 = _x1;
    y1228 = _y1;
    x2 = _x2;
    y2 = _y2;
  }
};
struct event {
  int type;
  rect R;
  int num;
  event(int _type, rect _R, int _num) {
    type = _type;
    R = _R;
    num = _num;
  }
};
vector<event> ev[maxn];
struct node {
  int mn;
  int l, r;
  node() { mn = l = r = 0; }
};
node d[maxn * 3];
void build(int l, int r, int v = 1) {
  d[v].l = l;
  d[v].r = r;
  d[v].mn = 0;
  if (l == r) return;
  int m = (l + r) >> 1;
  build(l, m, v << 1);
  build(m + 1, r, v << 1 | 1);
}
void update(int i, int x, int v = 1) {
  if (d[v].l == d[v].r) {
    d[v].mn = x;
  } else {
    int m = (d[v].l + d[v].r) >> 1;
    if (i <= m)
      update(i, x, v << 1);
    else
      update(i, x, v << 1 | 1);
    d[v].mn = min(d[v << 1].mn, d[v << 1 | 1].mn);
  }
}
int get(int l, int r, int v = 1) {
  if (l > r || d[v].l > r || d[v].r < l) return INF;
  if (l <= d[v].l && d[v].r <= r) return d[v].mn;
  return min(get(l, r, v << 1), get(l, r, v << 1 | 1));
}
bool ok[maxn][2];
void go(vector<pair<int, int> > p, vector<rect> r, int tt) {
  for (int i = 1; i < maxn; ++i) {
    ev[i].clear();
  }
  for (auto P : p) {
    ev[P.first].push_back({1, rect(P.first, P.second, 0, 0), 0});
  }
  int ptr = 1;
  for (auto R : r) {
    ev[R.x2].push_back({2, R, ptr++});
  }
  build(1, maxn - 1);
  for (int x = 1; x < maxn; ++x) {
    for (auto e : ev[x]) {
      if (e.type == 1) {
        update(e.R.y1228, e.R.x1);
      }
    }
    for (auto e : ev[x]) {
      if (e.type == 2) {
        if (get(e.R.y1228, e.R.y2) >= e.R.x1) {
          ok[e.num][tt] = 1;
        }
      }
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k, q;
  cin >> n >> m >> k >> q;
  vector<pair<int, int> > p1, p2;
  for (int i = 0; i < k; ++i) {
    int x, y;
    cin >> x >> y;
    p1.push_back({x, y});
    p2.push_back({y, x});
  }
  vector<rect> r1, r2;
  for (int i = 0; i < q; ++i) {
    int x1, y1228, x2, y2;
    cin >> x1 >> y1228 >> x2 >> y2;
    r1.push_back({x1, y1228, x2, y2});
    r2.push_back({y1228, x1, y2, x2});
  }
  go(p1, r1, 0);
  go(p2, r2, 1);
  for (int i = 1; i <= q; ++i) {
    if (ok[i][0] || ok[i][1]) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
