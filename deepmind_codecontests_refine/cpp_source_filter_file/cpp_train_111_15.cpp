#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int maxi = INT_MIN;
  int arr[105];
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
    maxi = max(maxi, arr[i]);
  }
  int k = maxi;
  while (k * n - sum < sum) {
    k++;
  }
  cout << k;
  return 0;
}
