#include <bits/stdc++.h>
using namespace std;
vector<long long> par;
long long find(long long u) {
  if (u == par[u]) return u;
  return par[u] = find(par[u]);
}
void tests() {
  long long n;
  cin >> n;
  par.assign(n, 0);
  for (long long i = 0; i < n; i++) par[i] = i;
  vector<pair<long long, long long> > a(n);
  for (long long i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
  for (long long i = 0; i < n; i++) {
    for (long long j = i + 1; j < n; j++) {
      if (a[i].first == a[j].first || a[i].second == a[j].second) {
        long long x = find(i), y = find(j);
        par[y] = x;
      }
    }
  }
  set<long long> s;
  for (long long i = 0; i < n; i++) s.insert(par[i]);
  cout << s.size() - 1 << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  while (t--) {
    tests();
  }
  return 0;
}
