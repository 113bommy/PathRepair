#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10;
long long n, q, d[N], t[N], f[N], v[N], a[N];
multiset<long long> s[N];
void add(long long x) {
  if (!v[x] && !s[x].empty()) {
    v[x] = 1;
    s[0].insert((*s[x].begin()) + t[x] / (d[x] + 1));
    s[0].insert(((*(--s[x].end()))) + t[x] / (d[x] + 1));
  }
}
void del(long long x) {
  if (v[x] && !s[x].empty()) {
    v[x] = 0;
    s[0].erase(s[0].find((*s[x].begin()) + t[x] / (d[x] + 1)));
    s[0].erase(s[0].find((*(--s[x].end())) + t[x] / (d[x] + 1)));
  }
}
void sol(long long i, long long j) {
  del(f[i]), del(f[f[i]]), del(f[f[f[i]]]);
  del(j), del(f[j]), del(f[f[j]]);
  s[f[i]].erase(s[f[i]].find(a[i]));
  s[f[f[i]]].erase(s[f[f[i]]].find(a[f[i]]));
  a[f[i]] -= t[i] / (d[i] + 1);
  a[f[i]] +=
      d[f[i]] * (t[f[i]] / (d[f[i]] + 1)) - (d[f[i]] - 1) * (t[f[i]] / d[f[i]]);
  s[f[f[i]]].insert(a[f[i]]);
  s[f[f[f[i]]]].erase(s[f[f[f[i]]]].find(a[f[f[i]]]));
  a[f[f[i]]] += t[f[i]] / d[f[i]] - t[f[i]] / (d[f[i]] + 1);
  s[f[f[f[i]]]].insert(a[f[f[i]]]);
  --d[f[i]], ++d[j];
  s[j].insert(a[i]);
  s[f[j]].erase(s[f[j]].find(a[j]));
  a[j] += t[i] / (d[i] + 1);
  a[j] += (d[j] - 1) * (t[j] / d[j]) - d[j] * (t[j] / (d[j] + 1));
  s[f[j]].insert(a[j]);
  s[f[f[j]]].erase(s[f[f[j]]].find(a[f[j]]));
  a[f[j]] += t[j] / (d[j] + 1) - t[j] / d[j];
  s[f[f[j]]].insert(a[f[j]]);
  add(f[i]), add(f[f[i]]), add(f[f[f[i]]]);
  add(j), add(f[j]), add(f[f[j]]);
  f[i] = j;
}
signed main() {
  ios::sync_with_stdio(false);
  cin >> n >> q;
  for (long long i = 1; i <= n; i++) cin >> t[i];
  for (long long i = 1; i <= n; i++) cin >> f[i], d[i]++, d[f[i]]++;
  for (long long i = 1; i <= n; i++) {
    a[i] += t[i] - d[i] * (t[i] / (d[i] + 1));
    a[f[i]] += t[i] / (d[i] + 1);
  }
  for (long long i = 1; i <= n; i++) s[f[i]].insert(a[i]);
  for (long long i = 1; i <= n; i++) add(i);
  for (long long i = 1; i <= q; i++) {
    long long op, x, y;
    cin >> op;
    if (op == 1) cin >> x >> y, sol(x, y);
    if (op == 2) cin >> x, cout << a[x] + t[f[x]] / (d[f[x]] + 1) << "\n";
    if (op == 3) cout << (*s[0].begin()) << " " << (*(--s[0].end())) << "\n";
  }
  return 0;
}
