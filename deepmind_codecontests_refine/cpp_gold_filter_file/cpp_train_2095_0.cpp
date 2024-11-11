#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> drivers, residents;
int arr[200009];
int ans[200009];
int lbound(int x, int m) {
  int lo = 0, hi = m - 1, idx = -1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (drivers[mid].first < x) {
      idx = mid;
      lo = mid + 1;
    } else
      hi = mid - 1;
  }
  return idx;
}
int ubound(int x, int m) {
  int lo = 0, hi = m - 1, idx = -1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (drivers[mid].first > x) {
      idx = mid;
      hi = mid - 1;
    } else
      lo = mid + 1;
  }
  return idx;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n + m; i++) cin >> arr[i];
  int dc = 0, rc = 0;
  for (int i = 0; i < n + m; i++) {
    int c;
    cin >> c;
    if (c) {
      drivers.push_back(make_pair(arr[i], dc));
      dc++;
    } else {
      residents.push_back(make_pair(arr[i], rc));
      rc++;
    }
  }
  sort(residents.begin(), residents.end());
  sort(drivers.begin(), drivers.end());
  int minm = 0;
  for (int i = 0; i < n; i++) {
    int lbi = lbound(residents[i].first, m);
    int ubi = ubound(residents[i].first, m);
    if (lbi == -1) {
      ans[drivers[ubi].second]++;
      continue;
    }
    if (ubi == -1) {
      ans[drivers[lbi].second]++;
      continue;
    }
    if (residents[i].first - drivers[lbi].first <=
        drivers[ubi].first - residents[i].first)
      ans[drivers[lbi].second]++;
    else
      ans[drivers[ubi].second]++;
  }
  for (int i = 0; i < m; i++) cout << ans[i] << " ";
  cout << endl;
}
