#include <bits/stdc++.h>
using namespace std;
long long p[200001];
long long vertex[100001];
long long wt = 0;
bool cmp(pair<long long, pair<long long, long long>> &a,
         pair<long long, pair<long long, long long>> &b) {
  return a.first < b.first;
}
long long Root(long long x) {
  while (x != p[x]) {
    p[x] = p[p[x]];
    x = p[x];
  }
  return x;
}
void Union(long long x, long long y, long long w) {
  long long r_x = Root(x);
  long long r_y = Root(y);
  if (r_x != r_y) {
    p[r_x] = r_y;
    wt += w;
  }
}
signed main() {
  for (long long i = 0; i <= 100000; i++) p[i] = i;
  long long m, n;
  cin >> m >> n;
  long long par = m + 1;
  for (long long i = 1; i <= n; i++) {
    vertex[i] = par;
    par++;
  }
  long long a[m], b[n];
  for (long long i = 0; i < m; i++) cin >> a[i];
  for (long long i = 0; i < n; i++) cin >> b[i];
  vector<pair<long long, pair<long long, long long>>> e;
  for (long long i = 0; i < m; i++) {
    long long sz;
    cin >> sz;
    for (long long j = 0; j < sz; j++) {
      long long y;
      cin >> y;
      e.push_back({a[i] + b[y - 1], {i + 1, vertex[y]}});
    }
  }
  sort(e.begin(), e.end(), cmp);
  long long tc = 0;
  for (long long i = (long long)e.size() - 1; i >= 0; i--) {
    long long x = e[i].second.first, y = e[i].second.second, w = e[i].first;
    Union(x, y, w);
    tc += w;
  }
  cout << tc - wt;
}
