#include <bits/stdc++.h>
using namespace std;
int a[300000];
pair<int, pair<int, int> > tr[300000];
int col[300000];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int m, n, k, t;
  cin >> m >> n >> k >> t;
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < k; i++) {
    cin >> tr[i].second.first >> tr[i].second.second >> tr[i].first;
  }
  sort(a, a + m);
  sort(tr, tr + k);
  int hi = m, lo = 0, mid, ans = 0;
  while (lo <= hi) {
    mid = (hi + lo + 1) / 2;
    if (mid == 0) {
      cout << "0" << endl;
      return 0;
    }
    int q = a[m - mid];
    for (int i = 0; i < n + 2; i++) {
      col[i] = 0;
    }
    for (int i = k - 1; i >= 0; i--) {
      if (tr[i].first <= q) break;
      col[tr[i].second.first] += 1;
      col[tr[i].second.second + 1] -= 1;
    }
    for (int i = 1; i < n + 2; i++) {
      col[i] += col[i - 1];
    }
    long long dist = 0LL;
    for (int i = 0; i < n + 2; i++) {
      if (col[i] > 0) dist++;
    }
    dist = dist * 2LL;
    dist += (long long)(n + 1);
    if (dist <= (long long)t) {
      ans = max(mid, ans);
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  cout << ans << endl;
  return 0;
}
