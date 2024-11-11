#include <bits/stdc++.h>
using namespace std;
const int MOD = (long long)(1e9 + 7);
const long long N = 1e5 + 7;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<pair<pair<long long, long long>, pair<long long, long long>>> v(n);
  vector<pair<long long, long long>> p(n);
  vector<long long> ans(n, 0);
  for (int i = 0; i < n; i++) {
    long long x, y;
    scanf("%lld %lld", &x, &y);
    v[i].second = make_pair(x, y);
    v[i].first = make_pair(x - y, i);
    p[i] = v[i].second;
  }
  sort(v.rbegin(), v.rend());
  long long x = 0, y = 0;
  for (int i = 0, j = n - 1; i < n; i++, j--) {
    ans[v[i].first.second] += (y + i * v[i].second.first);
    ans[v[j].first.second] += (x + i * v[j].second.second);
    y += v[i].second.second;
    x += v[j].second.first;
  }
  for (int i = 0; i < m; i++) {
    long long u, v;
    scanf("%lld %lld", &u, &v);
    u--, v--;
    long long mn = min(p[u].first + p[v].second, p[v].first + p[u].second);
    ans[u] -= mn;
    ans[v] -= mn;
  }
  for (int i = 0; i < n; i++) printf("%d%c", ans[i], " \n"[i + 1 == n]);
}
