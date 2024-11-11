#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:10000000000")
using namespace std;
long long n, m, ans = -1, best = (1e18 + 7);
pair<long long, long long> a[4];
int main() {
  a[0].first = (1e18 + 7);
  a[0].second = (1e18 + 7);
  a[1].first = (1e18 + 7);
  a[1].second = -(1e18 + 7);
  a[2].first = -(1e18 + 7);
  a[2].second = (1e18 + 7);
  a[3].first = -(1e18 + 7);
  a[3].second = -(1e18 + 7);
  cin >> n >> m;
  int c;
  cin >> c;
  for (int i = 0; i < c; i++) {
    long long q, w;
    cin >> q >> w;
    if (a[0].first + a[0].second > q + w) a[0] = make_pair(q, w);
    if (a[1].first + abs(a[1].second - m) > q + abs(m - w))
      a[1] = make_pair(q, w);
    if (abs(n - a[2].first) + a[2].second > abs(n - q) + w)
      a[2] = make_pair(q, w);
    if (abs(n - a[3].first) + abs(a[3].second - m) > abs(n - q) + abs(m - w))
      a[3] = make_pair(q, w);
  }
  cin >> c;
  for (int i = 0; i < c; i++) {
    long long q, w, d = 0;
    cin >> q >> w;
    for (int j = 0; j < 4; j++) {
      d = max(d, abs(q - a[0].first) + abs(w - a[0].second));
    }
    if (d < best) {
      best = d;
      ans = i + 1;
    }
  }
  cout << best << '\n' << ans << '\n';
  return 0;
}
