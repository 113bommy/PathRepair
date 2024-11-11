#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int total_time = n + arr[0];
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] > arr[i + 1]) {
      total_time = total_time + arr[i] - arr[i + 1] + 1;
    } else if (arr[i] <= arr[i + 1]) {
      total_time++;
      total_time = total_time + arr[i + 1] - arr[i];
    }
  }
  cout << total_time;
  return 0;
}
