#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;
vector<int> x[maxn];
int deomx[maxn * 4], deomn[maxn * 4];
pair<int, int> lad[2 * maxn];
pair<pair<pair<int, int>, pair<int, int> >, int> zap[2 * maxn];
bool ans[2 * maxn];
int n, m;
void build(int *a, int v = 0, int tl = 0, int tr = m) {
  if (tl == tr) {
    deomx[v] = a[tl];
    deomn[v] = a[tl];
    return;
  }
  int tm = (tl + tr) >> 1;
  build(a, v * 2 + 1, tl, tm);
  build(a, v * 2 + 2, tm + 1, tr);
  deomx[v] = max(deomx[v * 2 + 1], deomx[v * 2 + 2]);
  deomn[v] = max(deomn[v * 2 + 1], deomn[v * 2 + 2]);
}
void change(int pos, int val, int v = 0, int tl = 0, int tr = m) {
  if (tl == tr) {
    deomx[v] = val;
    deomn[v] = val;
    return;
  }
  int tm = (tl + tr) >> 1;
  if (pos <= tm) {
    change(pos, val, v * 2 + 1, tl, tm);
  } else {
    change(pos, val, v * 2 + 2, tm + 1, tr);
  }
  deomx[v] = max(deomx[v * 2 + 1], deomx[v * 2 + 2]);
  deomn[v] = max(deomn[v * 2 + 1], deomn[v * 2 + 2]);
}
pair<int, int> get(int lf, int rg, int v = 0, int tl = 0, int tr = m) {
  if (lf > rg) {
    return (make_pair(-mod, mod));
  }
  if (lf == tl && rg == tr) {
    return (make_pair(deomx[v], deomn[v]));
  }
  int tm = (tl + tr) >> 1;
  pair<int, int> p1 = get(lf, min(tm, rg), v * 2 + 1, tl, tm);
  pair<int, int> p2 = get(max(lf, tm + 1), rg, v * 2 + 2, tm + 1, tr);
  return (make_pair(max(p1.first, p2.first), min(p1.second, p2.second)));
}
int main() {
  srand(time(0));
  const string file = "";
  if (!file.empty()) {
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
  }
  int k, q;
  scanf("%d%d%d%d", &n, &m, &k, &q);
  for (int i = 0; i < k; i++) {
    scanf("%d%d", &lad[i].first, &lad[i].second);
  }
  for (int i = 0; i < q; i++) {
    scanf("%d%d%d%d", &zap[i].first.first.first, &zap[i].first.first.second,
          &zap[i].first.second.first, &zap[i].first.second.second);
    zap[i].second = i;
  }
  sort(&lad[0], &lad[k]);
  sort(&zap[0], &zap[q]);
  for (int i = k - 1; i >= 0; i--) {
    x[lad[i].second].push_back(lad[i].first);
  }
  for (int i = 1; i <= m; i++) {
    if (!x[i].empty()) {
      change(i, x[i].back());
      x[i].pop_back();
    }
  }
  int f = 0, g = 0;
  for (int i = 1; i <= n; i++) {
    while (g < q && zap[g].first.first.first == i) {
      int x1 = zap[g].first.first.first, y1 = zap[g].first.first.second;
      int x2 = zap[g].first.second.first, y2 = zap[g].first.second.second;
      int nz = zap[g].second;
      pair<int, int> p = get(y1, y2);
      if (p.second != 0 && p.first <= x2) {
        ans[nz] = 1;
      }
      g++;
    }
    while (f < k && lad[f].first == i) {
      int pos = lad[f].second;
      if (x[pos].empty()) {
        change(pos, 0);
      } else {
        change(pos, x[pos].back());
        x[pos].pop_back();
      }
      f++;
    }
  }
  swap(n, m);
  for (int i = 0; i < k; i++) {
    swap(lad[i].first, lad[i].second);
  }
  for (int i = 0; i < q; i++) {
    swap(zap[i].first.first.first, zap[i].first.first.second);
    swap(zap[i].first.second.first, zap[i].first.second.second);
  }
  sort(&lad[0], &lad[k]);
  sort(&zap[0], &zap[q]);
  for (int i = k - 1; i >= 0; i--) {
    x[lad[i].second].push_back(lad[i].first);
  }
  for (int i = 1; i <= m; i++) {
    if (!x[i].empty()) {
      change(i, x[i].back());
      x[i].pop_back();
    }
  }
  f = 0, g = 0;
  for (int i = 1; i <= n; i++) {
    while (g < q && zap[g].first.first.first == i) {
      int x1 = zap[g].first.first.first, y1 = zap[g].first.first.second;
      int x2 = zap[g].first.second.first, y2 = zap[g].first.second.second;
      int nz = zap[g].second;
      pair<int, int> p = get(y1, y2);
      if (p.second != 0 && p.first <= x2) {
        ans[nz] = 1;
      }
      g++;
    }
    while (f < k && lad[f].first == i) {
      int pos = lad[f].second;
      if (x[pos].empty()) {
        change(pos, 0);
      } else {
        change(pos, x[pos].back());
        x[pos].pop_back();
      }
      f++;
    }
  }
  for (int i = 0; i < q; i++) {
    if (ans[i]) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return (0);
}
