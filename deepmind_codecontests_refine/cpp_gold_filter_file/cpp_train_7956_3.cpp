#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
const int md = 1e9 + 7;
int n, m;
int a[N];
int x[N];
int y[N];
int used[N];
int pos[N];
int t[N * 4];
vector<int> v;
int get(int v, int tl, int tr, int l, int r) {
  if (tl > r || l > tr) return 0;
  if (l <= tl && tr <= r) return t[v];
  int tm = (tl + tr) / 2;
  return get(v + v, tl, tm, l, r) + get(v + v + 1, tm + 1, tr, l, r);
}
void upd(int v, int tl, int tr, int pos, int x) {
  if (tl == tr)
    t[v] = x;
  else {
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      upd(v + v, tl, tm, pos, x);
    else
      upd(v + v + 1, tm + 1, tr, pos, x);
    t[v] = t[v + v] + t[v + v + 1];
  }
}
int get1(int v, int tl, int tr, int b) {
  if (tl == tr) return tl;
  int tm = (tl + tr) / 2;
  if (tm + 1 + t[v + v + 1] <= b)
    return get1(v + v + 1, tm + 1, tr, b);
  else
    return get1(v + v, tl, tm, b - t[v + v + 1]);
}
int main() {
  scanf("%d%d", &n, &m);
  int cur = m;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x[i], &y[i]);
    if (!used[x[i]]) {
      pos[x[i]] = get1(1, 1, n, y[i]) + m;
      a[pos[x[i]] - m] = x[i];
      upd(1, 1, n, pos[x[i]] - m, 1);
    }
    used[x[i]] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (!used[i]) v.push_back(i);
  }
  int it = 0;
  for (int i = 1; i <= n; i++) {
    if (!a[i]) {
      if (it == int(v.size())) return cout << -1, 0;
      a[i] = v[it];
      pos[a[i]] = m + i;
      it++;
    }
  }
  for (int i = 0; i <= 2000000; i++) t[i] = 0;
  cur = m;
  for (int i = 1; i <= n; i++) {
    upd(1, 1, n + m, pos[i], 1);
  }
  for (int i = 1; i <= m; i++) {
    int sum = get(1, 1, n + m, 1, pos[x[i]]);
    if (sum != y[i]) return cout << -1, 0;
    upd(1, 1, n + m, pos[x[i]], 0);
    pos[x[i]] = cur;
    upd(1, 1, n + m, pos[x[i]], 1);
    cur--;
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i] << ' ';
  }
  return 0;
}
