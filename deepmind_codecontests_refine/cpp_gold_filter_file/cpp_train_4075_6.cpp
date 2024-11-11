#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  cout << arr[n - 1] << " ";
  for (int i = n - 2; i >= 0; i--) {
    if (arr[i] == arr[n - 1]) {
      cout << arr[i];
      break;
    }
    if (arr[n - 1] % arr[i] != 0) {
      cout << arr[i];
      break;
    }
    if (arr[i] == arr[i - 1]) {
      cout << arr[i];
      break;
    }
  }
}
