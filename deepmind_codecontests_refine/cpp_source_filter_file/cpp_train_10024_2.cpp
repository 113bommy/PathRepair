#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n;
  int* arr = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int max = -11111, min = 1111111;
  for (int i = 0; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
      a = i;
    }
    if (arr[i] <= min) {
      min = arr[i];
      b = i;
    }
  }
  n -= 1;
  if ((a == 0) && (b == n - 1)) {
    cout << 0;
    return 0;
  }
  if (a > b) {
    cout << (n - b) + (n - (n - a)) - 1;
  } else
    cout << (n - b) + (n - (n - a));
  delete[] arr;
  return 0;
}
