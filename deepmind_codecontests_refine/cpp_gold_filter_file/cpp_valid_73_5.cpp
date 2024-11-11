#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<int> ideal(n);
    for (int i = 0; i < n; i++) ideal[i] = i + 1;
    int ctr = 0;
    int oddIndex = 0;
    while (arr != ideal) {
      if (oddIndex % 2 == 0) {
        for (int i = 0; i < n - 1; i += 2) {
          if (arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
        }
      } else {
        for (int i = 1; i < n - 1; i += 2) {
          if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
          }
        }
      }
      oddIndex++;
      ctr++;
    }
    cout << ctr << "\n";
  }
  return 0;
}
