#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9 + 7;
const int N = (int)1e5 + 10;
struct qq {
  int l, r, i, w;
};
int t[4 * N], ans[2 * N];
pair<int, int> p[2 * N];
vector<qq> qx[N], qy[N];
void upd(int pos, int val, int v = 1, int l = 1, int r = N - 10) {
  if (l == r) {
    t[v] = val;
    return;
  }
  int m = (l + r) >> 1;
  if (pos <= m) {
    upd(pos, val, v + v, l, m);
  } else {
    upd(pos, val, v + v + 1, m + 1, r);
  }
  t[v] = min(t[v + v], t[v + v + 1]);
}
int get(int l, int r, int v = 1, int tl = 1, int tr = N - 10) {
  if (l > r || tr < l || tl > r) {
    return inf;
  }
  if (l <= tl && tr <= r) {
    return t[v];
  }
  int tm = (tl + tr) >> 1;
  return min(get(l, r, v + v, tl, tm), get(l, r, v + v + 1, tm + 1, tr));
}
inline bool cmp(pair<int, int> f, pair<int, int> s) {
  return f.second < s.second || (f.second == s.second && f.first < s.first);
}
int main() {
  int n, m, k, q;
  scanf("%d %d %d %d", &n, &m, &k, &q);
  for (int i = 1; i <= k; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    p[i] = {x, y};
  }
  for (int i = 1; i <= q; i++) {
    int ax, ay, bx, by;
    scanf("%d %d %d %d", &ax, &ay, &bx, &by);
    qx[bx].emplace_back(qq({ay, by, i, ax}));
    qy[by].emplace_back(qq({ax, bx, i, ay}));
  }
  sort(p + 1, p + k + 1);
  int ptr = 1;
  for (int i = 1; i < N; i++) {
    while (ptr <= k && p[ptr].first == i) {
      upd(p[ptr].second, i);
      ptr++;
    }
    for (auto j : qx[i]) {
      ans[j.i] |= ((get(j.l, j.r) >= j.w) ? 1 : 0);
    }
  }
  memset(t, 0, sizeof(t));
  ptr = 1;
  sort(p + 1, p + k + 1, cmp);
  for (int i = 1; i < N; i++) {
    while (ptr <= k && p[ptr].second == i) {
      upd(p[ptr].first, i);
      ptr++;
    }
    for (auto j : qy[i]) {
      ans[j.i] |= ((get(j.l, j.r) >= j.w) ? 1 : 0);
    }
  }
  for (int i = 1; i <= q; i++) {
    if (ans[i] == 1)
      puts("YES");
    else
      puts("NO");
  }
}
