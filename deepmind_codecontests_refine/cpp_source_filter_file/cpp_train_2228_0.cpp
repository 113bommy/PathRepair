#include <bits/stdc++.h>
using namespace std;
void solve() {
  int k, n;
  cin >> k >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr.begin(), arr.end());
  int diff = INT32_MAX;
  for (int i = 0; i + k < n; i++) {
    diff = min(diff, arr[i + k - 1] - arr[i]);
  }
  cout << diff << endl;
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
