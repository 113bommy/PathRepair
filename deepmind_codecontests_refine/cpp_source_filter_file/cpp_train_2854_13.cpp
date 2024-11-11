#include <bits/stdc++.h>
using namespace std;
int main() {
  const int n = 100000;
  const int s = 100000;
  int arr1[s];
  int arr[n];
  fill_n(arr, n, 0);
  fill_n(arr1, s, 0);
  long long z;
  long long k = 0;
  cin >> z;
  if (z == 1 || z == 2) {
    cout << z;
    return 0;
  }
  int counter = 2;
  for (int i = 0; i < z; i++) {
    cin >> arr[i];
    if (i >= 2) {
      if (arr[i] == arr[i - 1] + arr[i - 2]) {
        counter++;
        if (i == z - 1) arr1[k] = counter;
      } else {
        arr1[k] = counter;
        counter = 0;
        k++;
      }
    }
  }
  long long max = 0;
  for (int i = 0; i < z; i++) {
    if (arr1[i] > max) max = arr1[i];
  }
  cout << max + 2;
  cin.get();
  getchar();
  return 0;
}
