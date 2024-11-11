#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
int n, m, ans[N], cp[N], t[N * 4];
pair<int, int> a[N];
vector<pair<int, int> > v[N];
void upd(int pos, int val, int v = 1, int tl = 1, int tr = n) {
  if (tl == tr) {
    t[v] = val;
  } else {
    int tm = (tl + tr) >> 1;
    if (pos <= tm)
      upd(pos, val, v << 1, tl, tm);
    else
      upd(pos, val, v << 1 | 1, tm + 1, tr);
    t[v] = t[v << 1] + t[v << 1 | 1];
  }
}
int get(int k, int v = 1, int tl = 1, int tr = n) {
  if (tl == tr) return tl;
  int tm = (tl + tr) >> 1;
  if (t[v << 1] >= k)
    return get(k, v << 1, tl, tm);
  else
    return get(k - t[v << 1], v << 2 | 1, tm + 1, tr);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = -i;
    cp[i] = a[i].first;
  }
  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int k, pos;
    cin >> k >> pos;
    v[k].emplace_back(pos, i);
  }
  for (int i = 1; i <= n; i++) {
    upd(-a[i].second, 1);
    for (int j = 0; j < v[i].size(); j++) {
      int id = v[i][j].second;
      int pos = v[i][j].first;
      ans[id] = cp[get(pos)];
    }
  }
  for (int i = 1; i <= m; i++) {
    cout << ans[i] << endl;
  }
}
