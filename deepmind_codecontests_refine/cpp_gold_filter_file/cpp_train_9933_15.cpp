#include <bits/stdc++.h>
using namespace std;
int minFence(int arr[], int n, int k) {
  int sum = 0;
  for (int i = 0; i < k; i++) {
    sum = sum + arr[i];
  }
  int res = sum;
  int j = 0;
  int ans = 1;
  for (int i = k; i < n; i++) {
    sum = sum + arr[i] - arr[j];
    if (sum < res) {
      res = sum;
      ans = j + 2;
    }
    j++;
  }
  return ans;
}
int main() {
  int n, k;
  cin >> n >> k;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout << minFence(arr, n, k);
}
