#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const int INF = 1e9 + 7;
const int N = int(2e5 + 7);
int n, L, ans = INF, tr, pr, cur = -1, p[N];
set<pair<int, pair<int, int> > > second, t;
vector<int> v;
struct trump {
  int x, d, t, p, pt, id;
  inline bool operator<(const trump &other) const { return pt < other.pt; }
} a[N];
int main() {
  scanf("%d%d", &n, &L);
  ans = L;
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d%d", &a[i].x, &a[i].d, &a[i].t, &a[i].p);
    a[i].pt = a[i].x - a[i].p;
    a[i].id = i + 1;
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    if (a[i].pt < 0) continue;
    if (cur == -1)
      cur = a[i].pt;
    else
      cur += a[i].pt - a[i - 1].pt;
    while (t.size() && t.begin()->first < a[i].pt) {
      int x = t.begin()->first, ti = t.begin()->second.first;
      if (ti + a[i].pt - x < cur) {
        cur = ti + a[i].pt - x;
        pr = t.begin()->second.second;
      }
      second.erase(make_pair(x + ti, make_pair(x, t.begin()->second.second)));
      t.erase(t.begin());
    }
    if (second.size()) {
      int xt = second.begin()->first, x = second.begin()->second.first,
          id = second.begin()->second.second;
      if (xt - a[i].pt < cur) {
        cur = xt - a[i].pt;
        pr = id;
      }
    }
    int ti = a[i].p + cur + a[i].t, dist = a[i].x + a[i].d;
    if (L - dist + ti < ans) {
      ans = L - dist + ti;
      tr = a[i].id;
    }
    second.insert(make_pair(ti + dist, make_pair(dist, a[i].id)));
    t.insert(make_pair(dist, make_pair(ti, a[i].id)));
    p[a[i].id] = pr;
  }
  cout << ans << endl;
  while (tr != 0) {
    v.push_back(tr);
    tr = p[tr];
  }
  cout << v.size() << endl;
  reverse(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
  return 0;
}
