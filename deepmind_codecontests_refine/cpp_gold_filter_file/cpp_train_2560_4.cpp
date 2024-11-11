#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m;
  cin >> n >> m;
  vector<pair<long long int, long long int>> v;
  long long int arr[n];
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
    v.push_back({arr[i], i});
  }
  sort(v.rbegin(), v.rend());
  long long int ans[n];
  for (long long int i = 0; i < n; i++) {
    ans[i] = arr[i] / 2;
    if (arr[i] & 1) ans[i]++;
    m -= ans[i];
    if (m < 0) {
      cout << "-1" << endl;
      return 0;
    }
  }
  for (long long int i = 0; i < v.size(); i++) {
    long long int k = v[i].second;
    long long int l = v[i].first;
    long long int b = ans[k];
    b = l - b;
    ans[k] += min(b, m);
    m -= min(b, m);
    if (m <= 0) break;
  }
  if (m > 0)
    cout << "-1" << endl;
  else {
    for (long long int i = 0; i < n; i++) cout << ans[i] << " ";
  }
}
