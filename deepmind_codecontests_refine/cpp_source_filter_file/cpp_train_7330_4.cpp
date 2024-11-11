#include <bits/stdc++.h>
using namespace std;
const int N = 7 + 3e5;
int t[4 * N][2];
void push(int v) {
  t[v + v][1] += t[v][1];
  t[v + v + 1][1] += t[v][1];
  t[v + v][0] += t[v][1];
  t[v + v + 1][0] += t[v][1];
  t[v][1] = 0;
}
void upd(int v, int tl, int tr, int l, int r, int val) {
  if (l > r) {
    return;
  }
  if (tl == l && tr == r) {
    t[v][0] += val;
    t[v][1] += val;
    return;
  }
  push(v);
  int tm = (tl + tr) >> 1;
  upd(v + v, tl, tm, l, min(tm, r), val);
  upd(v + v + 1, tm + 1, tr, max(tm + 1, l), r, val);
  t[v][0] = max(t[v + v][0], t[v + v + 1][0]);
}
int get(int v, int tl, int tr) {
  if (tl == tr) {
    return tl;
  }
  push(v);
  int tm = (tl + tr) >> 1;
  if (t[v + v][0] > t[v + v + 1][0]) {
    return get(v + v, tl, tm);
  } else {
    return get(v + v + 1, tm + 1, tr);
  }
}
int n, l[N], v[N], r[N];
vector<pair<int, int> > x;
int idx, ans, lbest, rbest;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d %d", &l[i], &v[i], &r[i]);
    x.push_back(make_pair(l[i], -i));
    x.push_back(make_pair(v[i], i));
  }
  sort(x.begin(), x.end());
  for (int i = 0; i < n; i++) {
    idx = x[i].second;
    if (idx < 0) {
      idx = -idx;
      upd(1, 1, N, v[idx], r[idx], 1);
      if (t[1][0] > ans) {
        ans = t[1][0];
        lbest = l[idx];
        rbest = get(1, 1, N);
      }
    } else {
      upd(1, 1, N, v[idx], r[idx], -1);
    }
  }
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++) {
    if (l[i] <= lbest && lbest <= v[i] && v[i] <= rbest && rbest <= r[i]) {
      printf("%d ", i);
    }
  }
  return 0;
}
