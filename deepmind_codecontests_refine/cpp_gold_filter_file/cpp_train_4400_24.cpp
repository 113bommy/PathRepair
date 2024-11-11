#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[100], parr[100];
  for (size_t i = 1; i <= n; i++) {
    cin >> arr[i];
    parr[arr[i]] = i;
  }
  for (size_t i = 1; i <= n; i++) {
    swap(arr[i], parr[i]);
  }
  for (size_t i = 1; i <= n; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}
