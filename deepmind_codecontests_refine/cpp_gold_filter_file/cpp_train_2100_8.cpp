#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int s, b;
  cin >> s >> b;
  long long int arr[s];
  for (long long int i = 0; i < s; i++) {
    cin >> arr[i];
  }
  long long int x, y;
  vector<pair<long long int, long long int>> vp;
  for (long long int i = 0; i < b; i++) {
    cin >> x >> y;
    vp.push_back({x, y});
  }
  sort((vp).begin(), (vp).end());
  long long int a[b], c[b];
  for (long long int i = 0; i < b; i++) {
    a[i] = vp[i].first;
    c[i] = vp[i].second;
  }
  for (long long int i = 1; i < b; i++) {
    c[i] += c[i - 1];
  }
  vector<long long int> ans;
  for (long long int i = 0; i < s; i++) {
    long long int key = arr[i];
    if (binary_search(a, a + b, key)) {
      auto val = lower_bound(a, a + b, key) - a;
      ans.push_back(c[val]);
    } else {
      auto val = lower_bound(a, a + b, key) - a;
      if (val != 0) {
        ans.push_back(c[val - 1]);
      } else
        ans.push_back(0);
    }
  }
  for (auto x : ans) {
    cout << x << " ";
  }
  cout << "\n";
  return 0;
}
