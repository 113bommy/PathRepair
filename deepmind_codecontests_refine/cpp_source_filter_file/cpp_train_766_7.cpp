#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int a = 0, b = 0, c = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] < 0) {
      a = arr[i];
      cout << "1"
           << " " << arr[i] << endl;
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (arr[i] > 0) {
      b = arr[i];
      cout << "1"
           << " " << arr[i] << endl;
      break;
    }
  }
  if (b == 0) {
    for (int i = 0; i < n - 1; i++) {
      if (arr[i] != a && arr[i] < 0) {
        cout << "2"
             << " " << arr[i];
        b = arr[i];
        break;
      }
    }
    for (int i = 0; i < n - 1; i++) {
      if (arr[i] != a && arr[i] != b && arr[i] < 0) {
        cout << " " << arr[i] << endl;
        c = arr[i];
        break;
      }
    }
  }
  if (c == 0) {
    cout << n - 2;
  } else {
    cout << n - 3;
  }
  for (int i = 0; i < n; i++) {
    if (arr[i] == a || arr[i] == b || (arr[i] == c && c != 0)) {
      continue;
    }
    cout << " " << arr[i];
  }
  return 0;
}
