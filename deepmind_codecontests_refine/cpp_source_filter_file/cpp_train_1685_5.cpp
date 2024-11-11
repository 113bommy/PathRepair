#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int q = 0; q < t; q++) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int mini = INT_MAX;
    int result = 0;
    for (int i = n - 1; i > -1; i--) {
      if (arr[i] < mini) {
        mini = arr[i];
      } else {
        result++;
      }
    }
    cout << result << endl;
  }
  return 0;
}
