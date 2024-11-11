#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int INF = 1e9;
pair<pair<long long, long long>, int> ar[N];
int n;
bool cekslope(int a, int b, int c) {
  return (ar[b].first.second - ar[a].first.second) *
             (ar[c].first.first - ar[a].first.first) ==
         (ar[b].first.first - ar[a].first.first) *
             (ar[c].first.second - ar[a].first.second);
}
double dist(int x, int y) {
  if (x == 0) return 0;
  if (y == 0) return 0;
  return sqrt((ar[x].first.first - ar[y].first.first) *
                  (ar[x].first.first - ar[y].first.first) +
              (ar[x].first.second - ar[y].first.second) *
                  (ar[x].first.second - ar[y].first.second));
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);
  int k;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> ar[i].first.first >> ar[i].first.second;
    ar[i].second = i;
  }
  if (n == 3) {
    swap(ar[1], ar[k]);
    cout << min(dist(1, 2) + dist(2, 3), dist(1, 3) + dist(3, 2)) << '\n';
    return 0;
  }
  int idx;
  if (!cekslope(1, 2, 3) && !cekslope(1, 2, 4) && !cekslope(1, 3, 4))
    idx = 1;
  else if (!cekslope(1, 2, 3) && !cekslope(1, 2, 4))
    idx = 2;
  else {
    for (int i = 3; i <= n; ++i) {
      if (!cekslope(1, 2, i)) idx = i;
    }
  }
  vector<pair<pair<long long, long long>, int> > v;
  for (int i = 1; i <= n; ++i) {
    if (i == idx) continue;
    v.push_back(ar[i]);
  }
  sort(v.begin(), v.end());
  if (idx == k) {
    cout << dist(v[0].second, v[n - 2].second) +
                min(dist(v[0].second, idx), dist(v[n - 2].second, idx))
         << '\n';
    return 0;
  }
  for (int i = 0; i < n - 1; ++i) {
    if (v[i].second == k) {
      k = i;
      break;
    }
  }
  double ans = 1e9;
  ans =
      min(ans, dist(v[k].second, v[n - 2].second) +
                   dist(v[n - 2].second, v[0].second) + dist(v[0].second, idx));
  ans = min(ans, dist(v[k].second, v[0].second) +
                     dist(v[0].second, v[n - 2].second) +
                     dist(v[n - 2].second, idx));
  for (int i = 1; i <= k; ++i) {
    int cur = v[i].second;
    int prev = v[i - 1].second;
    int start = v[0].second;
    int last = v[n - 2].second;
    ans = min(ans,
              min(dist(v[k].second, cur) + dist(cur, last) + dist(last, idx),
                  dist(v[k].second, last) + dist(last, cur) + dist(cur, idx)) +
                  dist(idx, prev) + dist(prev, start));
  }
  for (int i = k; i < n - 2; ++i) {
    int cur = v[i].second;
    int nx = v[i + 1].second;
    int start = v[0].second;
    int last = v[n - 2].second;
    ans = min(
        ans, min(dist(v[k].second, cur) + dist(cur, start) + dist(start, idx),
                 dist(v[k].second, start) + dist(start, cur) + dist(cur, idx)) +
                 dist(idx, nx) + dist(nx, last));
  }
  cout << ans << '\n';
  return 0;
}
