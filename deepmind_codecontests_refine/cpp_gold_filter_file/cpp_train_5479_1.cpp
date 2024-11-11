#include <bits/stdc++.h>
using namespace std;
set<pair<long long, long long> > s;
vector<pair<long long, long long> > g;
int n, m, l, k;
long long ans, x, lst;
int main() {
  scanf("%d%lld", &n, &lst);
  s.insert(make_pair(lst - 1, 0));
  for (int i = 1; i < n; i++) {
    scanf("%lld", &x);
    if (x >= lst) continue;
    lst = x;
    g.clear();
    while (!s.empty()) {
      set<pair<long long, long long> >::iterator it = s.end();
      it--;
      if ((*it).first < x) break;
      g.push_back((*it));
      s.erase(it);
    }
    if (!g.size()) continue;
    long long mx = 0;
    for (int j = 0; j < g.size(); j++) {
      pair<long long, long long> t = g[j];
      mx = max(mx, t.second + 1ll * i * (t.first - x - t.first % x));
      s.insert(
          make_pair(t.first % x, t.second + 1ll * i * (t.first - t.first % x)));
    }
    s.insert(make_pair(x - 1, mx));
  }
  for (set<pair<long long, long long> >::iterator it = s.begin(); it != s.end();
       it++) {
    ans = max(ans, n * it->first + it->second);
  }
  printf("%lld\n", ans);
  return 0;
}
