#include <bits/stdc++.h>
using namespace std;
long long a[5000005], b[5000005], c[5000005], r, m, n, sum = 0;
vector<pair<long long, long long> > v[5000005];
long long check(long long x) {
  if (a[x]) return a[x];
  a[x] = 1;
  for (long long i = 0; i < v[x].size(); i++) {
    long long j = v[x][i].first;
    if (check(j) + 1 > a[x]) {
      a[x] = a[j] + 1;
      b[x] = max(b[x], v[x][i].second);
    }
  }
  return a[x];
}
int main() {
  ios_base::sync_with_stdio(0);
  long long k = 0, t = 0, x, y = 0, l = 1, i, j;
  cin >> n >> m;
  for (i = 0; i < m; i++) {
    cin >> x >> y;
    v[x].push_back(make_pair(y, i + 1));
  }
  for (i = 1; i <= n; i++) {
    if (check(i) == n) {
      cout << b[i];
      return 0;
    }
  }
  cout << "-1";
  return 0;
}
