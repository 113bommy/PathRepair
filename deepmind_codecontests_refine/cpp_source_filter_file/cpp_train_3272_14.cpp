#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, temp = 0;
  cin >> n;
  int arr[n];
  for (int h = 0; h < n; h++) {
    cin >> arr[h];
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[i] > arr[j]) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
  for (int s = 0; s < n; s++) {
    cout << arr[s];
  }
  return 0;
}
