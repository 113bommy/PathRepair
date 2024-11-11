#include <bits/stdc++.h>
using namespace std;
const int mxN = 2e5;
int main() {
  int n;
  cin >> n;
  int arr[n], mx = 0;
  map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    mp[arr[i]]++;
    mx = max(mx, mp[arr[i]]);
  }
  for (int i = 0; i <= (int)1e5; ++i) {
    if (mp[i + 1] < mp[i + 2]) {
      cout << -1;
      return 0;
    }
  }
  cout << mx << endl;
  for (int i = 0; i < n; ++i) {
    cout << mp[arr[i]] << " ";
    mp[arr[i]]--;
  }
}
