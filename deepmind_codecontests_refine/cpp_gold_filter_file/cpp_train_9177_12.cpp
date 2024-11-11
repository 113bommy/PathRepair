#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  if (n != 3 || (arr[0] != -3 || arr[1] != -3 || arr[2] != 2)) {
    for (int i = 0; i < n; i++) {
      if (arr[i] >= 0) arr[i] = -arr[i] - 1;
    }
    if (n % 2 != 0) {
      int mx = -1, index = -1;
      for (int i = 0; i < n; i++) {
        if (abs(arr[i]) > mx) {
          mx = abs(arr[i]);
          index = i;
        }
      }
      arr[index] = -arr[index] - 1;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}
