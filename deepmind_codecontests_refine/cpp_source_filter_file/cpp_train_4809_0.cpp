#include <bits/stdc++.h>
using namespace std;
int arr[100002];
int ans[100002];
bool used[100002];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      used[i] = false;
    }
    int minmin = 1;
    ans[0] = arr[0];
    used[ans[0]] = true;
    bool flag = false;
    for (int i = 1; i < n; i++) {
      if (arr[i] < arr[i - 1]) {
        flag = true;
        break;
      }
      if (arr[i] == arr[i - 1]) {
        while (used[minmin]) minmin++;
        if (minmin > n || minmin > arr[i - 1]) {
          flag = true;
          break;
        }
        ans[i] = minmin;
      } else {
        ans[i] = arr[i];
      }
      if (used[ans[i]] || ans[i] < 1 || ans[i] > n) {
        flag = true;
        break;
      }
      used[ans[i]] = true;
    }
    if (flag) {
      cout << -1 << '\n';
      continue;
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }
}
