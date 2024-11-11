#include <bits/stdc++.h>
using namespace std;
const int INF = 1000 * 1000 * 1000;
const long long INF64 = 1LL * INF * INF;
const long long mod = INF + 7;
const long double eps = 1e-9;
bool check(vector<pair<long long, long long> >& g, int s, int k) {
  long long a = 0;
  for (int i = 0; i < g.size(); ++i) {
    if (a + g[i].first <= s)
      a += g[i].first;
    else
      return false;
    if (i + 1 >= k) return true;
  }
}
void solve() {
  int n, k, m, s;
  cin >> n >> m >> k >> s;
  vector<int> a(n), b(n);
  vector<int> ra(n), rb(n);
  vector<pair<long long, long long> > dol, funt, d, f;
  vector<int> g;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    ra[i] = i;
    if (i) {
      if (a[i] >= a[i - 1]) ra[i] = ra[i - 1];
      a[i] = min(a[i - 1], a[i]);
    }
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    rb[i] = i;
    if (i) {
      if (b[i] >= b[i - 1]) rb[i] = rb[i - 1];
      b[i] = min(b[i - 1], b[i]);
    }
  }
  for (int i = 0; i < m; ++i) {
    int t, c;
    cin >> t >> c;
    if (t == 1)
      dol.push_back({c, i + 1});
    else
      funt.push_back({c, i + 1});
    g.push_back(t);
  }
  sort(dol.begin(), dol.end());
  sort(funt.begin(), funt.end());
  d = dol, f = funt;
  int l = -1, r = n;
  while (r - l > 1) {
    int m = (l + r) / 2;
    for (int i = 0; i < d.size(); ++i) d[i].first = dol[i].first * a[m];
    for (int i = 0; i < f.size(); ++i) f[i].first = funt[i].first * b[m];
    vector<pair<long long, long long> > mer;
    mer.reserve(d.size() + f.size());
    merge(d.begin(), d.end(), f.begin(), f.end(), back_inserter(mer));
    if (check(mer, s, k))
      r = m;
    else
      l = m;
  }
  if (r == n) {
    cout << -1 << endl;
    return;
  }
  for (int i = 0; i < d.size(); ++i) d[i].first = dol[i].first * a[r];
  for (int i = 0; i < f.size(); ++i) f[i].first = funt[i].first * b[r];
  vector<pair<long long, long long> > mer;
  mer.reserve(d.size() + f.size());
  merge(d.begin(), d.end(), f.begin(), f.end(), back_inserter(mer));
  cout << r + 1 << endl;
  for (int i = 0; i < k; ++i)
    cout << mer[i].second << " "
         << (g[mer[i].second - 1] == 1 ? ra[r] + 1 : rb[r] + 1) << endl;
}
int main() {
  cout.sync_with_stdio(false);
  solve();
  return 0;
}
