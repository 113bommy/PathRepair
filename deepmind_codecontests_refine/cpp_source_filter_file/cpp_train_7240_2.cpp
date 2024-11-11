#include <bits/stdc++.h>
using namespace std;
int main() {
  int *arr, n;
  cin >> n;
  arr = new int[n];
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  for (int i = 0; i < n; ++i) {
    if (i == n - 1)
      cout << arr[i];
    else {
      arr[i] += arr[i + 1];
      cout << arr[i];
    }
  }
}
