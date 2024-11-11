#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[3];
  cin >> arr[0] >> arr[1] >> arr[2];
  int min = arr[0], post = 0;
  for (int i = 1; i < 3; i++) {
    if (arr[i] < min) {
      min = arr[i];
      post = i;
    }
  }
  if (post == 0) {
    for (int i = 0; i < 2; i++) {
      if (arr[1] >= min + 1 && arr[2] >= min + 2) {
        cout << 3 * min + 3;
        break;
      } else {
        min--;
      }
    }
  } else if (post == 1) {
    for (int i = 0; i < 2; i++) {
      if (arr[0] >= min - 1 && arr[2] >= min + 1) {
        cout << 3 * min;
        break;
      } else {
        min--;
      }
    }
  } else if (post == 2) {
    for (int i = 0; i < 2; i++) {
      if (arr[0] >= min - 2 && arr[1] >= min - 1) {
        cout << 3 * min - 3;
        break;
      } else {
        min--;
      }
    }
  }
  return 0;
}
