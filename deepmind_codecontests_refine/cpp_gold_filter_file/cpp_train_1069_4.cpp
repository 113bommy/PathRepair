#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long MX = 1e9;
const long long INF = 1e9;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  long long a[n];
  for (int i = 0; i < n; ++i) cin >> a[i];
  int sz[n], tot = n;
  long long ans = 0, sq[n], x, y, l1, l2;
  priority_queue<pair<long long, int> > q;
  for (int i = 0; i < n; ++i) {
    sq[i] = a[i] * a[i];
    sz[i] = 1;
    ans += sq[i];
    if (sz[i] == a[i]) continue;
    x = a[i] / 2;
    y = x;
    if (a[i] & 1) ++y;
    q.push({sq[i] - ((x * x) + (y * y)), i});
  }
  while (tot < k) {
    ++tot;
    int id = q.top().second;
    long long mn = q.top().first;
    q.pop();
    ++sz[id];
    sq[id] -= mn;
    ans -= mn;
    if (sz[id] == a[id]) continue;
    x = a[id] / (sz[id] + 1);
    l2 = a[id] % (sz[id] + 1);
    l1 = sz[id] - l2 + 1;
    y = x + 1;
    x = x * x;
    y = y * y;
    q.push({sq[id] - ((x * l1) + (y * l2)), id});
  }
  cout << ans << '\n';
  return 0;
}
