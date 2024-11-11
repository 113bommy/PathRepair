#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, sum = 0, min;
  cin >> n >> k;
  int arr[2 * n], brr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    arr[i + n] = arr[i];
  }
  for (int i = 0; i < k - 1; i++) {
    for (int j = i; j <= i + n - 1; j += k) {
      sum = sum + arr[j];
    }
    brr[i] = sum;
    sum = 0;
  }
  min = brr[0];
  for (int i = 0; i < k - 1; i++) {
    if (min > brr[i]) {
      min = brr[i];
    }
  }
  for (int i = 0; i < k - 1; i++) {
    if (min == brr[i]) {
      cout << i + 1;
      return 0;
    }
  }
  return 0;
}
