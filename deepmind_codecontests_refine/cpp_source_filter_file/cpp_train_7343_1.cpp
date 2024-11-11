#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, tmp;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[j + 1] < arr[j]) {
        tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
        cout << j + 1 << " " << j + 2 << "\n";
      }
    }
  }
  return 0;
}
