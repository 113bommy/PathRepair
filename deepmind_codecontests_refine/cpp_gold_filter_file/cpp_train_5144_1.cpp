#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int sum = 0, i;
  int arr[n];
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  int count = 0;
  for (i = 0; i < n; i++) {
    if (count < m) {
      if (arr[i] < 0) {
        sum += arr[i];
        count++;
      }
    }
  }
  cout << abs(sum);
}
