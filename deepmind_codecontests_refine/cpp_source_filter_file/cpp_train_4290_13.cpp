#include <bits/stdc++.h>
using namespace std;
bool check(pair<long long int, long long int> arr[], long long int mid,
           long long int n, long long int s) {
  vector<pair<long long int, long long int>> both;
  long long int l = 0, r = 0;
  for (long long int i = 0; i < n; i++) {
    if (arr[i].second < mid) {
      s -= arr[i].first;
      l++;
    } else if (arr[i].first > mid) {
      s -= arr[i].first;
      r++;
    } else {
      both.push_back(arr[i]);
    }
  }
  if (l > (n / 2) || r > (n / 2)) return false;
  for (long long int i = 0; i < both.size(); i++) {
    if (l < (n / 2)) {
      s -= arr[i].first;
      l++;
    } else {
      s -= mid;
      r++;
    }
  }
  if (s < 0) return false;
  return true;
}
void solve() {
  long long int n, s, l, r = 0, a, b;
  cin >> n >> s;
  pair<long long int, long long int> arr[n];
  for (long long int i = 0; i < n; i++) {
    cin >> a >> b;
    arr[i] = {a, b};
    r = max(r, b);
  }
  sort(arr, arr + n);
  l = arr[n / 2].first;
  r = arr[n].second;
  while (l < r) {
    long long int mid = (l + r + 1) / 2;
    if (check(arr, mid, n, s)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << l << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
