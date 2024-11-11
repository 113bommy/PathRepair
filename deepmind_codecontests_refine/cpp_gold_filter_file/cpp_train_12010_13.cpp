#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  int x = arr[0];
  for (int i = 1; i < n; i++) {
    if (x < arr[i]) {
      cout << arr[i];
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
