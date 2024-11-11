#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const int N = 2 * 1e5 + 10;
const long double eps = 1e-9;
const int mod = 998244353;
struct p {
  int a, b, m, id;
};
p a[N];
map<int, vector<int> > mp;
vector<int> vc;
vector<array<int, 3> > v;
pair<int, int> ans[N];
int res = 0;
void fnd() {
  int n = vc.size();
  v.clear();
  array<int, 3> t;
  for (int i : vc) {
    int al = max(0, a[i].a - a[i].m), ar = a[i].a - max(0, a[i].m - a[i].b);
    t[0] = al;
    t[1] = ar;
    t[2] = i;
    v.push_back(t);
  }
  sort(v.begin(), v.end());
  int l = 0, r = 0, wa;
  while (l < n) {
    wa = v[l][1];
    while (r < n && v[r][0] <= v[l][1]) {
      wa = min(wa, v[r][1]);
      ++r;
    }
    for (int i = l; i < r; ++i) {
      p cur = a[v[i][2]];
      ans[cur.id].first = cur.a - wa;
      ans[cur.id].second = cur.m + wa - cur.a;
    }
    l = r;
    ++res;
  }
  return;
}
void solve() {
  int n;
  cin >> n;
  mp.clear();
  res = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].a >> a[i].b >> a[i].m;
    a[i].id = i;
    mp[a[i].a + a[i].b - a[i].m].push_back(i);
  }
  for (auto i : mp) {
    vc = i.second;
    fnd();
  }
  cout << res << "\n";
  for (int i = 0; i < n; ++i)
    cout << ans[i].first << " " << ans[i].second << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
