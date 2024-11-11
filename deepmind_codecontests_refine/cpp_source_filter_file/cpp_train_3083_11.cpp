#include <bits/stdc++.h>
using namespace std;
bool ans = false;
bool isBroken(long long mid, long long n, long long m, long long k, long long q,
              vector<pair<long long, pair<long long, long long> > > broken) {
  if (mid == 0) return false;
  int screen[n][m];
  memset(screen, 0, sizeof(screen));
  for (long long i = 0; i < broken.size(); i++) {
    if (broken[i].first > mid) break;
    screen[broken[i].second.first - 1][broken[i].second.second - 1] = 1;
  }
  for (long long i = 0; i < n; i++)
    for (long long j = 1; j < m; j++) {
      screen[i][j] += screen[i][j - 1];
    }
  for (long long j = 0; j < m; j++)
    for (long long i = 1; i < n; i++) screen[i][j] += screen[i - 1][j];
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < m; j++) {
      long long x = i + k - 1;
      long long y = j + k - 1;
      if (x >= n || y >= m) break;
      long long sa = screen[x][y];
      if ((x - k) >= 0) {
        sa -= screen[x - k][y];
      }
      if ((y - k) >= 0) {
        sa -= screen[x][y - k];
      }
      if ((x - k) >= 0 && (y - k) >= 0) sa += screen[x - k][y - k];
      if (sa == (k * k)) {
        ans = true;
        return true;
      }
    }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m, k, q;
  cin >> n >> m >> k >> q;
  vector<pair<long long, pair<long long, long long> > > broken;
  for (long long i = 0; i < q; i++) {
    long long x, y, t;
    cin >> x >> y >> t;
    broken.push_back(make_pair(t, make_pair(x, y)));
  }
  sort(broken.begin(), broken.end());
  long long lo = 1, hi = 10e9;
  while (lo <= hi) {
    long long mid = (lo + hi) / 2;
    bool sa = isBroken(mid, n, m, k, q, broken);
    if (!sa) {
      lo = mid + 1;
    } else {
      bool x = isBroken(mid - 1, n, m, k, q, broken);
      if (!x) {
        cout << mid << endl;
        break;
      }
      hi = mid - 1;
    }
  }
  if (!ans) cout << -1 << endl;
}
