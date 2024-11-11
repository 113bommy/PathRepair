#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long arr1[n], arr2[n], arr3[n];
  for (int i = 0; i < n; i++) {
    cin >> arr1[i];
  }
  for (int i = 0; i < n - 1; i++) {
    cin >> arr2[i];
  }
  for (int i = 0; i < n - 2; i++) {
    cin >> arr3[i];
  }
  sort(arr1, arr1 + n);
  sort(arr2, arr2 + n - 1);
  sort(arr3, arr3 + n - 2);
  for (int i = 0; i < n; i++) {
    if (arr1[i] != arr2[i]) {
      cout << arr1[i] << "\n";
      break;
    }
  }
  for (int i = 0; i < n - 1; i++) {
    if (arr2[i] != arr3[i]) {
      cout << arr2[i] << "\n";
      break;
    }
  }
  return 0;
}
