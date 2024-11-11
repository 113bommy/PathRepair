#include <bits/stdc++.h>
using namespace std;
int arr[1005];
vector<int> ans;
int main() {
  int k, p, x, y, n;
  cin >> n >> k >> p >> x >> y;
  int sum = 0;
  for (int i = 0; i < k; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  sort(arr, arr + k);
  int idx = lower_bound(arr, arr + k, y) - arr;
  if (idx == k) {
    arr[idx] = y;
    k++;
    sum += y;
    ans.push_back(y);
  }
  if (idx > n / 2) {
    cout << "-1\n";
    return 0;
  }
  for (int i = 0; i < n - k; i++) {
    if (idx < n / 2) {
      ans.push_back(1);
      idx++;
      sum++;
    } else {
      ans.push_back(y);
      sum += y;
    }
  }
  if (sum > x) {
    cout << "-1\n";
    return 0;
  }
  for (int i = 0; i < (int)ans.size(); i++) {
    if (i) cout << " ";
    cout << ans[i];
  }
  cout << "\n";
}
