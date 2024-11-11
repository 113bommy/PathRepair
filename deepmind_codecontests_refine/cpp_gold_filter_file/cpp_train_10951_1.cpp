#include <bits/stdc++.h>
using namespace std;
int main() {
  int count;
  cin >> count;
  for (int i = 0; i < count; i++) {
    int size;
    cin >> size;
    int arr[size];
    for (int j = 0; j < size; j++) cin >> arr[j];
    int arr2[size];
    for (int j = 0; j < size; j++) cin >> arr2[j];
    int l = -1, r = -1;
    for (int j = 0; j < size; j++) {
      if (arr[j] != arr2[j]) {
        l = j;
        break;
      }
    }
    if (l == -1) {
      cout << "YES" << endl;
      continue;
    }
    for (int j = size - 1; j >= 0; j--) {
      if (arr[j] != arr2[j]) {
        r = j;
        break;
      }
    }
    int diff = arr[l] - arr2[l];
    if (diff > 0) {
      cout << "NO" << endl;
      continue;
    }
    bool fincheck = true;
    for (int j = l; j <= r; j++) {
      if (arr[j] - diff != arr2[j]) {
        cout << "NO" << endl;
        fincheck = false;
        break;
      }
    }
    if (fincheck) cout << "YES" << endl;
  }
  return 0;
}
