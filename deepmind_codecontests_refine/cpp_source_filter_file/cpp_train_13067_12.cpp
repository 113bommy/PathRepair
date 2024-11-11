#include <bits/stdc++.h>
using namespace std;
long long n, m, i, j, a, b, d, answ;
pair<long long, long long> p[200005];
vector<long long> g;
set<long long> q;
set<long long>::iterator it;
int main() {
  scanf("%lld%lld%lld", &d, &m, &n);
  g.push_back(0);
  g.push_back(d);
  for (i = 1; i <= n; i++) {
    scanf("%lld%lld", &a, &b);
    g.push_back(a);
    p[i] = make_pair(b, a);
  }
  sort(p + 1, p + n + 1);
  sort(g.begin(), g.end());
  for (i = 1; i < g.size(); i++)
    if (g[i] - g[i - 1] > m) {
      cout << -1 << endl;
      return 0;
    }
  q.insert(0);
  q.insert(d);
  for (i = 1; i <= n; i++) {
    a = p[i].second;
    b = p[i].first;
    it = q.lower_bound(a);
    long long x = (*it);
    --it;
    long long aa = (*it);
    if (x - aa <= m) continue;
    q.insert(a);
    if (a - aa > m)
      answ += b * min(x - a, m);
    else
      answ += b * min(d - a, x - m - aa);
  }
  cout << answ << endl;
  return 0;
}
