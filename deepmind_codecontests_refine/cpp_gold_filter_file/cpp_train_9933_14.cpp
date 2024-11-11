#include <bits/stdc++.h>
using namespace std;
int arr[150000];
int main() {
  int n, k, sum = 0, j = 1, i;
  cin >> n >> k;
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sum = accumulate(arr, arr + k, sum);
  int ansum = sum;
  for (i = k; i < n; i++) {
    if (sum - arr[i - k] + arr[i] < ansum) {
      j = i - k + 2;
      ansum = sum - arr[i - k] + arr[i];
    }
    sum = sum - arr[i - k] + arr[i];
  }
  cout << j;
  return 0;
}
