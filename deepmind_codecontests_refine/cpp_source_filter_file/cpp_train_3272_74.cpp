#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, arr[100];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = i; j < n; j++) {
      if (arr[i] > arr[j]) {
        int swap = arr[j];
        arr[j] = arr[i];
        arr[i] = swap;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << arr[i];
  }
  return 0;
}
