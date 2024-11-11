#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  bool flag = true;
  if (n == 1) {
    cout << arr[0];
  } else {
    if (arr[0] == 1) {
      cout << 1 << endl;
    } else {
      for (int i = 1; i < n; i++) {
        if (arr[i] % arr[0] != 0) {
          flag = false;
          break;
        }
      }
      if (flag) {
        cout << arr[0];
      } else {
        cout << -1;
      }
    }
  }
}
