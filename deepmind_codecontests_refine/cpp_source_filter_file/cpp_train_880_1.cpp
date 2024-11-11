#include <bits/stdc++.h>
using namespace std;
mt19937 bruh(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rofl(chrono::steady_clock::now().time_since_epoch().count());
const int N = 5e5 + 2;
const int M = 1e5;
const int mod = 0;
const int inf = 2e9 + 3;
const long long INF = 1e18;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
void files() {
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
}
int n, m, k, q, badv[N], badg[N], ax[N], bx[N], ay[N], by[N];
vector<int> v[N], g[N], cv[N], cg[N];
struct node {
  int t[N];
  void build(int v = 1, int tl = 1, int tr = M) {
    t[v] = 0;
    if (tl == tr) return;
    int tm = tl + tr >> 1;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
  }
  void upd(int pos, int val, int v = 1, int tl = 1, int tr = M) {
    if (tl == tr) return (void)(t[v] = val);
    int tm = tl + tr >> 1;
    if (pos <= tm)
      upd(pos, val, v * 2, tl, tm);
    else
      upd(pos, val, v * 2 + 1, tm + 1, tr);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
  }
  int get(int l, int r, int v = 1, int tl = 1, int tr = M) {
    if (l <= tl || tr <= r) return t[v];
    if (r < tl || tr < l) return inf;
    int tm = tl + tr >> 1;
    return min(get(l, r, v * 2, tl, tm), get(l, r, v * 2 + 1, tm + 1, tr));
  }
} t;
int main() {
  scanf("%d %d %d %d", &n, &m, &k, &q);
  for (int i = 1, x, y; i <= k; ++i) {
    scanf("%d %d", &x, &y);
    g[x].push_back(y);
    v[y].push_back(x);
  }
  for (int i = 1; i <= q; ++i) {
    scanf("%d %d %d %d", &ax[i], &ay[i], &bx[i], &by[i]);
    cg[bx[i]].push_back(i);
    cv[by[i]].push_back(i);
  }
  t.build();
  for (int i = 1; i <= m; ++i) {
    for (auto it : v[i]) t.upd(it, i);
    for (auto it : cv[i]) {
      int mn = t.get(ax[it], bx[it]);
      if (mn < ay[it]) badv[i] = 1;
    }
  }
  t.build();
  for (int i = 1; i <= m; ++i) {
    for (auto it : g[i]) t.upd(it, i);
    for (auto it : cg[i]) {
      int mn = t.get(ay[it], by[it]);
      if (mn < ax[it]) badg[i] = 1;
    }
  }
  for (int i = 1; i <= q; ++i)
    if (badv[i] & badg[i])
      printf("NO\n");
    else
      printf("YES\n");
}
