#include <bits/stdc++.h>
using namespace std;
int const maxx = 2 * 1e5 + 20;
long long x[maxx], w[maxx];
long long l[maxx], r[maxx];
pair<long long, long long> p[maxx];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i] >> w[i];
  for (int i = 0; i < n; i++) {
    l[i] = x[i] - w[i];
    r[i] = x[i] + w[i];
  }
  for (int i = 0; i < n; i++) {
    p[i].first = r[i];
    p[i].second = i;
  }
  sort(p, p + n);
  int ans = 1;
  int x = r[p[0].second];
  for (int i = 1; i < n; i++) {
    if (l[p[i].second] > x) {
      x = r[p[i].second];
      ans++;
    }
  }
  cout << ans;
  return 0;
}
