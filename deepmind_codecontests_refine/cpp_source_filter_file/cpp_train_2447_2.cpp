#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  if (n == 1) {
    cout << arr[0];
    return 0;
  }
  int empty = 0;
  int s, e;
  for (int i = 0; i < n; ++i) {
    if (arr[i] == 0)
      empty++;
    else {
      s = i;
      break;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (arr[i] == 0)
      empty++;
    else {
      e = i;
      break;
    }
  }
  int ans = 0;
  for (int i = s; i <= e; ++i) {
    if (arr[i] == 1) {
      ans++;
    } else if (arr[i] == 0 && (arr[i - 1] == 1 || arr[i + 1] == 1)) {
      ans++;
    }
  }
  cout << ans;
}
