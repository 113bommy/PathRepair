#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  bool ok = true;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  for (int i = 1; i <= n; i++) {
    if (arr[i - 1] < arr[i]) {
      cout << arr[i];
      ok = false;
      break;
    }
  }
  if (ok) {
    cout << "NO";
  }
  return 0;
}
