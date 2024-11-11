#include <bits/stdc++.h>
using namespace std;
bool comparePairs(const std::pair<int, int>& lhs,
                  const std::pair<int, int>& rhs) {
  if (lhs.second <= rhs.second) return 1;
  return 0;
}
void solve() {
  int n, x;
  int arr[100000];
  std::vector<pair<int, int> > v;
  int i;
  cin >> n >> x;
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  for (i = 0; i < n; i++) {
    int a = (x / arr[i]) + ((x % arr[i] == 0) ? 0 : 1);
    if (a <= n - i) {
      v.push_back(make_pair(i, i + a - 1));
    }
  }
  if (v.size() == 0) {
    cout << 0 << endl;
    return;
  }
  sort(v.begin(), v.end(), comparePairs);
  int end = v[0].second, cnt = 1;
  for (i = 1; i < v.size(); i++) {
    if (v[i].first > end) {
      cnt++;
      end = v[i].second;
    }
  }
  cout << cnt << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
