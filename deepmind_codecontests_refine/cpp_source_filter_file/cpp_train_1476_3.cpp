#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, i, j;
  cin >> n;
  map<long long, long long> m;
  pair<long long, long long> a[4 * n + 1];
  vector<long long> v[51], s[51];
  for (i = 0; i < 4 * n + 1; i++) {
    long long x, y;
    cin >> x >> y;
    a[i].first = x;
    a[i].second = y;
    v[x].push_back(y);
    s[y].push_back(x);
  }
  long long mnx = -1, mny = -1, mxx = -1, mxy = -1;
  for (i = 0; i < 51; i++) {
    if (v[i].size() >= n + 1) {
      if (mnx == -1) {
        mnx = i;
      } else {
        mxx = i;
      }
    }
    if (s[i].size() >= n + 1) {
      if (mny == -1) {
        mny = i;
      } else {
        mxy = i;
      }
    }
  }
  for (i = 0; i < 4 * n + 1; i++) {
    if ((a[i].first == mnx || a[i].first == mxx) && a[i].second <= mxy &&
        a[i].second >= mny)
      continue;
    if ((a[i].second == mny || a[i].second == mxy) && a[i].first <= mxx &&
        a[i].first >= mnx)
      continue;
    cout << a[i].first << " " << a[i].second;
    return 0;
  }
}
