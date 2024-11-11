#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  int sum1 = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  int count = 0;
  sort(arr, arr + n);
  int i = n - 1;
  while (sum1 <= sum) {
    count++;
    sum1 += arr[i];
    sum -= arr[i];
    i++;
  }
  cout << count;
  return 0;
}
