#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
set<pair<int, int> > s;
int n, h[MAXN], l[MAXN], r[MAXN], P[MAXN], f[MAXN];
bool cmp(const int &a, const int &b) { return h[a] > h[b]; }
int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> n >> t;
  for (int i = 1; i <= n; ++i) cin >> h[i] >> l[i] >> r[i], P[i] = i;
  P[n + 1] = n + 1;
  l[0] = l[n + 1] = -1e9;
  r[0] = r[n + 1] = -1e9;
  h[0] = 1e9;
  h[n + 1] = -1;
  f[0] = 2e9;
  sort(P + 1, P + n + 2, cmp);
  s.insert(pair<int, int>(-1e9, 0));
  s.insert(pair<int, int>(1e9, 0));
  for (int o = 1; o <= n + 1; ++o) {
    int i = P[o];
    set<pair<int, int> >::iterator st = s.lower_bound(make_pair(l[i], i));
    set<pair<int, int> >::iterator it = st;
    it--;
    while (it->first < r[i]) {
      set<pair<int, int> >::iterator tmp1 = it;
      if (tmp1 != s.begin()) tmp1--;
      set<pair<int, int> >::iterator tmp2 = it;
      tmp2++;
      int j = it->second, p = tmp1->second, q = tmp2->second;
      if ((h[j] <= h[p] || l[j] >= r[p] || r[p] <= l[i]) &&
          (h[j] <= h[q] || r[j] <= l[q] || l[q] >= r[i]))
        f[i] = max(f[i], min(f[j], min(r[i], r[j]) - max(l[i], l[j])));
      ++it;
    }
    it--;
    int j = it->second;
    s.erase(st, ++it);
    if (r[i] != it->first) s.insert(pair<int, int>(r[i], j));
    s.insert(pair<int, int>(l[i], i));
  }
  cout << f[n + 1] << endl;
  return 0;
}
