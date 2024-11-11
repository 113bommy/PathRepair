#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());
  int ans = 0;
  vector<int> vis(150001 + 3, 0);
  for (int i = 0; i < n; i++) {
    if (arr[i] - 1 != 0 && vis[arr[i] - 1] == 0) {
      vis[arr[i] - 1] = 1;
      ans++;
    } else if (vis[arr[i]] == 0) {
      vis[arr[i]] = 1;
      ans++;
    } else if (vis[arr[i] + 1] == 0) {
      vis[arr[i] + 1] = 1;
      ans++;
    } else
      continue;
  }
  cout << ans << "\n";
}
