#include <bits/stdc++.h>
using namespace std;
long long n, px, py, r[100005];
pair<pair<int, int>, int> a[100005];
int main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first.first >> a[i].first.second;
    a[i].second = i;
  }
  while (1) {
    random_shuffle(a + 1, a + n + 1);
    px = py = 0;
    for (int i = 1; i <= n; i++)
      if ((px + a[i].first.first) * (px + a[i].first.first) +
              (py + a[i].first.second) * (py + a[i].first.second) <
          (px - a[i].first.first) * (px - a[i].first.first) +
              (py - a[i].first.second) * (py - a[i].first.second)) {
        r[a[i].second] = 1;
        px += a[i].first.first;
        py += a[i].first.second;
      } else {
        r[a[i].second] = -1;
        px -= a[i].first.first;
        py -= a[i].first.second;
      }
    if (px * px + py * py <= 1LL * 1.5 * 1.5 * 1e12) break;
  }
  for (int i = 1; i <= n; i++) cout << r[i] << ' ';
}
