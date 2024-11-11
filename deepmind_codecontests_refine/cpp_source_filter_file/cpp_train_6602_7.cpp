#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int> > seg, last;
pair<int, int> v[200002];
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) cin >> v[i].first >> v[i].second;
  sort(v, v + m);
  last.push_back({1, 1});
  int i = 0, lin = 0;
  while (i < m) {
    if (v[i].first != lin + 1 && last.size()) {
      int aux = last[0].first;
      last.clear();
      last.push_back({aux, n});
    }
    int j = i;
    while (j < m && v[j].first == v[i].first) j++;
    seg.clear();
    int st = 1, k = 0;
    for (int p = i; p <= j; p++) {
      int dr = (p < j ? v[p].second - 1 : n);
      while (k < last.size() && last[k].second < st) k++;
      if (k < last.size() && max(last[k].first, st) <= dr)
        seg.push_back({max(last[k].first, st), dr});
      st = v[i].second + 1;
    }
    last = seg;
    lin = v[i].first;
    i = j;
  }
  if (seg.size() && (lin < n || seg.back().second == n))
    cout << 2 * n - 2;
  else
    cout << -1;
  return 0;
}
