#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t, i, j, k, l;
  long long mod = 1e9 + 7;
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  vector<pair<int, int> > d, nd;
  while (m--) {
    int r;
    cin >> t >> l >> r;
    l--, r--;
    if (t)
      nd.push_back({l, r});
    else
      d.push_back({l, r + 1});
  }
  sort(nd.begin(), nd.end());
  for (i = 0; i + 1 < nd.size(); i++)
    if (nd[i].second >= nd[i + 1].first)
      nd[i].second = max(nd[i].second, nd[i + 1].second),
      nd.erase(nd.begin() + i + 1), i--;
  for (i = 0; i < nd.size(); i++) {
    for (j = nd[i].first; j < nd[i].second; j++) a[j] = 1;
    a[j] = 1e3 + 1;
  }
  for (i = 0; i < n; i++) {
    if (a[i] > 0)
      j = 1e3;
    else
      a[i] = j--;
  }
  k = 0;
  for (auto x : d) k += is_sorted(a.begin() + x.first, a.begin() + x.second);
  if (k)
    cout << "NO\n";
  else {
    cout << "YES\n";
    for (auto x : a) cout << x << " ";
    cout << endl;
  }
  return 0;
}
