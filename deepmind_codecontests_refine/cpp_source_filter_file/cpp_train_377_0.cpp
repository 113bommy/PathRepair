#include <bits/stdc++.h>
int getbit(long long x, int y) { return (x >> y) & 1; }
long long getoff(long long x, int y) { return x ^ ((1ll) << y); }
using namespace std;
int n, k, t[500010], f[20010][2];
pair<int, int> a[500010];
priority_queue<pair<int, int>, vector<pair<int, int> >,
               greater<pair<int, int> > >
    q;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> k >> n;
  for (int i = 1; i <= n; ++i) cin >> t[i];
  sort(t + 1, t + n + 1);
  for (int i = 1; i < n; ++i) q.emplace(t[i + 1] - t[i], i);
  int sz = 0;
  while (sz < 4 * k - 1) {
    a[++sz].first = q.top().second;
    a[sz].second = q.top().first;
    q.pop();
  }
  n = sz;
  sort(a + 1, a + n + 1);
  int ch = 1;
  for (int j = 1; j <= k; ++j) {
    for (int i = 0; i <= n; ++i) f[i][ch] = 1e9;
    if (j == 1) f[1][ch] = a[1].second;
    for (int i = 2; i <= n; ++i) {
      f[i][ch] = f[i - 1][ch];
      if (a[i].first == a[i - 1].first + 1)
        f[i][ch] = min(f[i][ch], f[i - 2][ch ^ 1] + a[i].second);
      else
        f[i][ch] = min(f[i][ch], f[i - 1][ch ^ 1] + a[i].second);
    }
    ch ^= 1;
  }
  ch ^= 1;
  cout << f[n][ch];
  return 0;
}
