#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > gr(200000);
int main() {
  int n, s;
  cin >> n >> s;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    arr[i] = a;
  }
  sort(arr.begin(), arr.end());
  if (arr[n / 2] == s) {
    cout << 0;
  } else {
    if (arr[n / 2] > s) {
      int64_t ans = 0;
      for (int i = n / 2; i >= 0; --i) {
        if (arr[i] > s)
          ans += arr[i] - s;
        else
          break;
      }
      cout << ans;
    } else {
      int64_t ans = 0;
      for (int i = n / 2; i < n; ++i) {
        if (arr[i] < s)
          ans += s - arr[i];
        else
          break;
      }
      cout << ans;
    }
  }
  return 0;
}
