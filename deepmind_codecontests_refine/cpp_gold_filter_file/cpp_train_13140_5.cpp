#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
      sort(arr, arr + n, greater<int>());
    }
    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
