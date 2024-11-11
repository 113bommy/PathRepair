#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, m;
  cin >> n >> m >> k;
  pair<int, int> arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i].first;
    arr[i].second = i + 1;
  }
  sort(arr, arr + n);
  vector<int> v;
  long long sum = 0;
  for (int i = n - 1; i >= n - k * m; i--) {
    v.push_back(arr[i].second);
    sum += arr[i].first;
  }
  sort(v.begin(), v.end());
  cout << sum << endl;
  for (int i = m - 1; i < k * m - 1; i += m) cout << v[i] << " ";
  return 0;
}
