#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  bool flag = false;
  bool f = false;
  long long arr[4];
  for (long long i = 0; i < 4; i++) cin >> arr[i];
  sort(arr, arr + 4);
  for (long long i = 0; i <= 1; i++) {
    if (arr[i] + arr[i + 1] > arr[i + 2]) {
      flag = true;
    }
    if (arr[i] + arr[i + 1] == arr[i + 2]) {
      f = true;
    }
  }
  if (flag) {
    cout << "TRIANGLE" << endl;
  } else if (f) {
    cout << "SEGMENT" << endl;
  } else
    cout << "IMPOSSIBLE" << endl;
}
