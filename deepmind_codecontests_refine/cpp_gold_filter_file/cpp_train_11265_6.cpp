#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  map<int, int> mp;
  int prev = 0, count = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] > prev) {
      count++;
    } else {
      count = 1;
    }
    mp[i] = count;
    prev = arr[i];
  }
  int ans = 1;
  for (int i = 0; i < n; i++) {
    int j = i - mp[i] - 1;
    ans = max(mp[i], ans);
    if (j >= 0) {
      if (arr[j] < arr[j + 2]) ans = max(ans, mp[i] + mp[j]);
      int j = i - mp[i];
      if (arr[j] < arr[j + 2]) {
        ans = max(ans, mp[i] - 1 + mp[j]);
      }
    } else
      ans = max(ans, mp[i]);
  }
  cout << ans;
}
