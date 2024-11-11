#include <bits/stdc++.h>
using namespace std;
const int INF = int(1e9) + 1;
const long long INFll = 1ll * INF * INF;
const long double EPS = 1e-26;
const int MOD = 1000000007;
const int N = 5050;
struct sg {
  int l, r, type;
  sg() : l(0), r(0), type(0) {}
  sg(int l, int r, int type) {
    this->l = l;
    this->r = r;
    this->type = type;
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  int e, s, n, m;
  cin >> e >> s >> n >> m;
  vector<pair<int, int> > v;
  int x, y;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    v.push_back(make_pair(y, 4 - x));
  }
  sort(v.begin(), v.end());
  vector<sg> t(1);
  t[0].l = v[0].first;
  t[0].r = v[0].first + s - 1;
  t[0].type = v[0].second;
  for (int i = 1; i < v.size(); i++) {
    while (t.back().type > v[i].second) {
      if (t.back().r < v[i].first) break;
      if (v[i].first <= t.back().l) {
        t.pop_back();
        continue;
      }
      t.back().r = v[i].first - 1;
      break;
    }
    t.push_back(
        {max(v[i].first, t.back().r + 1), v[i].first + s - 1, v[i].second});
  }
  vector<int> k2(t.size() + 1, 0), k3(t.size() + 1, 0), a2(t.size());
  for (int i = 0; i < t.size(); i++) {
    a2[i] = t[i].l;
  }
  int it = 0;
  while (it < t.size() && t[it].r < e - 1) it++;
  int can;
  if (it == t.size() || t[it].l > e - 1)
    can = e;
  else {
    int calc = e;
    while (true) {
      k2[it] = k2[it + 1];
      k3[it] = k3[it + 1];
      if (t[it].type == 2) k2[it] += calc - t[it].l;
      if (t[it].type == 3) k3[it] += calc - t[it].l;
      calc = t[it].l;
      it--;
      if (it < 0 || t[it].r < t[it + 1].l - 1) break;
    }
    can = calc;
  }
  for (int i = 0; i < m; i++) {
    int start;
    cin >> start;
    start += s;
    if (start < can) {
      cout << "-1 -1\n";
      continue;
    }
    if (start >= e) {
      cout << "0 0\n";
      continue;
    }
    int num = lower_bound(a2.begin(), a2.end(), start) - a2.begin();
    int ans1 = k2[num];
    int ans2 = k3[num];
    if (start < a2[num]) {
      num--;
      ans1 = k2[num];
      ans2 = k3[num];
      if (t[num].type == 2)
        ans1 -= start - a2[num];
      else if (t[num].type == 3)
        ans2 -= start - a2[num];
    }
    cout << ans2 << " " << ans1 << "\n";
  }
  return 0;
}
