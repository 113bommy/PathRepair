#include <bits/stdc++.h>
using namespace std;
int comp(const pair<int, int> &a, const pair<int, int> b) {
  return a.first < b.first;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > arr(m);
    int x, y;
    for (int i = 0; i < m; i++) {
      cin >> x >> y;
      arr[i] = make_pair(x, y);
    }
    sort(arr.begin(), arr.end(), comp);
    vector<long long> pre(m + 1, 0);
    for (int i = m - 1; i >= 0; i--) pre[i] = pre[i + 1] + arr[i].first;
    long long ans = 0;
    for (int i = 0; i < m; i++) {
      int pos =
          upper_bound(arr.begin(), arr.end(), make_pair(arr[i].second, 0)) -
          arr.begin();
      if (m - 1 - pos + 1 > n - 1) pos = m - (n - 1);
      long long happy = pre[pos];
      int count = n - (m - pos);
      if (pos > i) happy += arr[i].first, count--;
      happy += count * arr[i].second;
      ans = max(ans, happy);
    }
    cout << ans << endl;
  }
  return 0;
}
