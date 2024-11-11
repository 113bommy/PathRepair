#include <bits/stdc++.h>
using namespace std;
int n, k;
bool cmp(pair<int, int> x, pair<int, int> y) {
  if (x.first > y.first) {
    return true;
  } else if (x.first < y.first) {
    return false;
  } else if (x.second < y.second) {
    return true;
  } else {
    return false;
  }
  return false;
}
void solve() {
  cin >> n >> k;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
  sort(a.begin(), a.end(), cmp);
  int cnt = 0;
  int l = a[k - 1].first;
  int r = a[k - 1].second;
  for (int i = 0; i < n; i++) {
    if (a[i].first == l && a[i].second == r) ++cnt;
  }
  cout << cnt;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
}
