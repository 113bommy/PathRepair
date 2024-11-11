#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 22, inf = 1e9 + 7;
int n;
long long s[4 * N], cursum;
vector<pair<int, int> > t[4 * N];
vector<int> p[4 * N];
pair<int, int> a[N];
void build(int v, int tl, int tr) {
  if (tl == tr) {
    s[v] = a[tl].first;
    t[v].push_back({a[tl].second, a[tl].first});
    p[v].push_back(a[tl].first);
    return;
  }
  int tm = (tl + tr) / 2;
  build(v * 2, tl, tm);
  build(v * 2 + 1, tm + 1, tr);
  s[v] = s[v * 2] + s[v * 2 + 1];
  t[v].resize(tr - tl + 1);
  p[v].resize(tr - tl + 1);
  merge(t[v * 2].begin(), t[v * 2].end(), t[v * 2 + 1].begin(),
        t[v * 2 + 1].end(), t[v].begin());
  for (int i = 0; i < t[v].size(); i++) {
    if (i == 0)
      p[v][i] = t[v][i].second;
    else
      p[v][i] = p[v][i - 1] + t[v][i].second;
  }
}
long long sum(int v, int tl, int tr, int l, int r) {
  if (l <= tl && tr <= r) {
    return s[v];
  }
  if (tl > r || tr < l) return 0LL;
  int tm = (tl + tr) / 2;
  return sum(v * 2, tl, tm, l, r) + sum(v * 2 + 1, tm + 1, tr, l, r);
}
int get(int v, int tl, int tr, int l, int r, int val) {
  if (l <= tl && tr <= r) {
    int id = lower_bound(t[v].begin(), t[v].end(), make_pair(val, -inf)) -
             t[v].begin();
    if (id != 0) cursum += p[v][id - 1];
    return id;
  }
  if (tl > r || tr < l) {
    return 0;
  }
  int tm = (tl + tr) / 2;
  return get(v * 2, tl, tm, l, r, val) + get(v * 2 + 1, tm + 1, tr, l, r, val);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i].second;
  }
  sort(a + 1, a + n + 1);
  build(1, 1, n);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    cursum = 0;
    int cnt = get(1, 1, n, i + 1, n, a[i].second);
    long long cur = 0;
    cur += sum(1, 1, n, i + 1, n);
    cur -= cursum;
    cur -= a[i].first * 1LL * (n - i - cnt);
    ans += cur;
  }
  cout << endl;
  cout << ans;
  return 0;
}
