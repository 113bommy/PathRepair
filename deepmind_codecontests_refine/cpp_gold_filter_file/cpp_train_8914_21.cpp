#include <bits/stdc++.h>
using namespace std;
int n, a[100005];
vector<pair<int, int>> v;
void solve() {
  cin >> n;
  v.resize(n);
  v.assign(n, {INT_MAX, INT_MAX});
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  v[n - 1] = {n - 1, a[n - 1]};
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] < v[i + 1].second) {
      v[i] = {i, a[i]};
    } else {
      v[i] = v[i + 1];
    }
  }
  for (int i = 0; i < n; i++) {
    int ele = a[i], ans = -1, ind = -1;
    int low = 0, high = n - 1;
    while (low <= high) {
      int mid = high - (high - low) / 2;
      if (v[mid].second < a[i]) {
        if (v[mid].second > ans) {
          ans = v[mid].second;
          ind = v[mid].first;
        }
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    if (i + 1 > ind) {
      cout << "-1 ";
      continue;
    }
    cout << ind - (i + 1) << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
