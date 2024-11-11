#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t = 0;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  for (int i = 0; i < n; i++) {
    if (arr[i] + arr[i + 1] > arr[i + 2]) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
