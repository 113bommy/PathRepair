#include <bits/stdc++.h>
using namespace std;
vector<int> t;
int sz = 0;
const int INF = 2e9;
void build(vector<int> a) {
  t.assign(2 * sz + 2, INF);
  for (int i = 0; i < sz; i++) {
    t[i + sz] = a[i];
  }
  for (int i = sz - 1; i > 0; i--) {
    t[i] = min(t[2 * i], t[2 * i + 1]);
  }
}
int get(int v, int tl, int tr, int l, int r) {
  if (tl > r || l > tr) {
    return INF;
  }
  if (tl == l && tr == r) {
    return t[v];
  }
  int tm = (tl + tr) / 2;
  return min(get(2 * v, tl, tm, l, min(r, tm)),
             get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  sz = 1;
  while (sz < 4 * n) {
    sz *= 2;
  }
  vector<int> a(sz);
  vector<pair<int, int>> q;
  vector<pair<int, int>> qq;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    q.emplace_back(l, 0);
    qq.emplace_back(l, r);
    q.emplace_back(r, 1);
    q.emplace_back(l - 1, -1);
    q.emplace_back(r + 1, -1);
  }
  sort(q.begin(), q.end());
  int b = 0;
  for (int i = 0; i < 4 * n; i++) {
    if (q[i].second == 0) {
      b++;
      int id = lower_bound(q.begin(), q.end(), make_pair(q[i].first, -1)) -
               q.begin();
      a[id] = max(a[id], b);
    } else {
      int id = lower_bound(q.begin(), q.end(), make_pair(q[i].first, -1)) -
               q.begin();
      a[id] = max(a[id], b);
      if (q[i].second == 1) b--;
    }
  }
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == 0) {
      a[i] = INF;
    }
  }
  build(a);
  for (int i = 0; i < n; i++) {
    int minimum = get(
        1, 0, sz - 1,
        lower_bound(q.begin(), q.end(), make_pair(qq[i].first, -1)) - q.begin(),
        lower_bound(q.begin(), q.end(), make_pair(qq[i].second, -1)) -
            q.begin());
    if (minimum > 1 && minimum != INF) {
      cout << i + 1;
      return 0;
    }
  }
  cout << -1;
  return 0;
}
