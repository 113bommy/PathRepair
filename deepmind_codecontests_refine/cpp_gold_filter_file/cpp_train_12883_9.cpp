#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());
  int cnt = 0;
  int prev = INT_MIN;
  for (int i = 0; i < n; i++) {
    if (arr[i] != 0 && arr[i] != prev) {
      cnt++;
      prev = arr[i];
    }
  }
  if (cnt == 1) {
    int flag = 0;
    for (int i = 0; i < n; i++) {
      if (arr[i] != 0) {
        flag = 1;
        break;
      }
    }
    if (flag == 1) {
      cout << cnt;
    } else {
      cout << 0 << endl;
    }
  } else
    cout << cnt << endl;
  return 0;
}
